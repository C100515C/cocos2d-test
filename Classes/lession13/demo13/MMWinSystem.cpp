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

    /* 控件工厂 */
    mWinFactory = MMWinFactory::create();
    mWinFactory->retain();

    /* 控件属性加工厂 */
    mWinPropertyFactory = MMWinPropertyFactory::create();
    mWinPropertyFactory->retain();
    return true;
}

MMBase* MMWinSystem::createWinsByXmlData( MMWinXmlData* xmlData, bool isHasParent ) {
    assert(xmlData && "createWinsByXmlData:xmlData is NULL!");

    /* 规定只能有一个MMBase,xml中生成的所有控件的最终父控件都是这个唯一MMBase */
    MMBase* baseWin = NULL;

    if(xmlData->isNone() == false) {
        baseWin = createWinByXmlData(xmlData);
    }

    if(xmlData->isHasChild()) {
        if(baseWin != NULL) {
            baseWin->setHasChildWin(true);

            /* 如果没有父控件，代表自身是父控件，父控件要在子控件之前设置属性 */
            if(isHasParent == false) {
                /* 根据控件类型给控件设置属性，父控件要在子控件之前设置属性 */
                dressPropertiesByType(baseWin, xmlData);
            }
        }

        auto cldXmlDataList = xmlData->getCldXmlDataList();

        for (auto cldXmlData : cldXmlDataList)
        {
            MMBase* mmWin = createWinsByXmlData(cldXmlData, true);

            baseWin->addChild(mmWin);
            mmWin->setHasParentWin(true);

            
            /* 根据控件类型给控件设置属性（如果没有父控件，代表自身是父控件，父控件已经设置过属性，不重复设置） */
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
    
    /* 根据控件类型创建控件 */
    MMBase* win = createWinByType(enWinType);

    return win;
}

MMBase* MMWinSystem::createWinByType( EnumWinType enWinType ) {
    /* 从控件工厂创建一个控件 */
    return mWinFactory->createWinByType(enWinType);
}

int MMWinSystem::createUniqueID() {
    m_iWinID += 1;

    return m_iWinID;
}

void MMWinSystem::dressPropertiesByType( MMBase* mmWin, MMWinXmlData* xmlData ) {
    mWinPropertyFactory->dressPropertiesByType(mmWin, xmlData);
}