#include "MMWinSystem.h"
#include "MMWinFactory.h"

MMWinSystem::MMWinSystem()
: m_iWinID(0),
  mDesktopWin(NULL),
  mWinFactory(NULL),
  mWinPropertyFactory(NULL) {

}

MMWinSystem::~MMWinSystem() {
    CC_SAFE_RELEASE(mDesktopWin);
    CC_SAFE_RELEASE(mWinFactory);
    CC_SAFE_RELEASE(mWinPropertyFactory);
}

MMWinSystem* MMWinSystem::create( MMDesktopWin* desktopWin ) {
    MMWinSystem* winSystem = new MMWinSystem;

    if(winSystem && winSystem->init(desktopWin)) {
        winSystem->autorelease();
    }
    else {
        CC_SAFE_DELETE(winSystem);
        winSystem = NULL;
    }

    return winSystem;
}

bool MMWinSystem::init(MMDesktopWin* desktopWin) {
    desktopWin->retain();
    this->mDesktopWin = desktopWin;

    /* �ؼ����� */
    mWinFactory = MMWinFactory::create();
    mWinFactory->retain();

    /* �ؼ����Լӹ��� */
    mWinPropertyFactory = MMWinPropertyFactory::create();
    mWinPropertyFactory->retain();
    return true;
}

MMBase* MMWinSystem::createWinsByXmlData( MMWinXmlData* xmlData, bool isHasParent ) {
    assert(xmlData && "createWinsByXmlData:xmlData is NULL!");

    /* �涨ֻ����һ��MMBase,xml�����ɵ����пؼ������ո��ؼ��������ΨһMMBase */
    MMBase* baseWin = NULL;

    if(xmlData->isNone() == false) {
        baseWin = createWinByXmlData(xmlData);
    }

    if(xmlData->isHasChild()) {
        if(baseWin != NULL) {
            baseWin->setHasChildWin(true);

            /* ���û�и��ؼ������������Ǹ��ؼ������ؼ�Ҫ���ӿؼ�֮ǰ�������� */
            if(isHasParent == false) {
                /* ���ݿؼ����͸��ؼ��������ԣ����ؼ�Ҫ���ӿؼ�֮ǰ�������� */
                dressPropertiesByType(baseWin, xmlData);
            }
        }

        auto cldXmlDataList = xmlData->getCldXmlDataList();

        for (auto cldXmlData : cldXmlDataList)
        {
            MMBase* mmWin = createWinsByXmlData(cldXmlData, true);

            baseWin->addChild(mmWin);
            mmWin->setHasParentWin(true);

            
            /* ���ݿؼ����͸��ؼ��������ԣ����û�и��ؼ������������Ǹ��ؼ������ؼ��Ѿ����ù����ԣ����ظ����ã� */
            if(mmWin->isHasParentWin() == true) {
                dressPropertiesByType(mmWin, cldXmlData);
            }
        }

    }
    return baseWin;
}

MMBase* MMWinSystem::createWinByXmlData( MMWinXmlData* xmlData ) {
    assert(xmlData && "createWinByXmlData:xmlData is NULL!");
 
    EnumWinType enWinType = xmlData->getEnWinType();
    
    /* ���ݿؼ����ʹ����ؼ� */
    MMBase* win = createWinByType(enWinType);

    return win;
}

MMBase* MMWinSystem::createWinByType( EnumWinType enWinType ) {
    /* �ӿؼ���������һ���ؼ� */
    return mWinFactory->createWinByType(enWinType);
}

int MMWinSystem::createUniqueID() {
    m_iWinID += 1;

    return m_iWinID;
}

void MMWinSystem::dressPropertiesByType( MMBase* mmWin, MMWinXmlData* xmlData ) {
    mWinPropertyFactory->dressPropertiesByType(mmWin, xmlData);
}