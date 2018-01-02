 #include "MMWinManager.h"
#include "tinyxml.h"
#include "MMWinXmlData.h"
#include "MMWinXmlDataSetting.h"


MMWinManager* MMWinManager::mWinManager = NULL;


MMWinManager::MMWinManager() {

}

MMWinManager::~MMWinManager() {
    CC_SAFE_RELEASE_NULL(mWinXmlDataSetting);
    CC_SAFE_RELEASE_NULL(mWinSystem);
    CC_SAFE_RELEASE_NULL(mDesktopWin);
}


MMWinManager* MMWinManager::getInstance() {
    if(mWinManager == NULL) {
        mWinManager = new MMWinManager();

        if(mWinManager && mWinManager->init()) {
            mWinManager->autorelease();
            mWinManager->retain();
        }
        else {
            CC_SAFE_DELETE(mWinManager);
            mWinManager = NULL;
        }
    }

    return mWinManager;
}

bool MMWinManager::init() {
    mWinXmlDataSetting = MMWinXmlDataSetting::create();
    mWinXmlDataSetting->retain();

    mDesktopWin = MMDesktopWin::create();
    mDesktopWin->retain();

    mWinSystem = MMWinSystem::create(mDesktopWin);
    mWinSystem->retain();

    return true;
}

MMBase* MMWinManager::createWinsFromXML( const char* sXmlPath ) {
    TiXmlDocument* xmlDoc = new TiXmlDocument();

    Data fileData = FileUtils::getInstance()->getDataFromFile(sXmlPath);
    xmlDoc->Parse((const char*)fileData.getBytes());

    TiXmlElement* rootElement = xmlDoc->RootElement();
    MMWinXmlData* xmlData = createXmlData(rootElement->FirstChildElement());

    delete xmlDoc;

    /* ���ɿؼ� */
    MMBase* baseWin = mWinSystem->createWinsByXmlData(xmlData, false);

    if(baseWin->isHasChildWin() == false) {
        mWinSystem->dressPropertiesByType(baseWin, xmlData);
    }

    /* ��Ӹ��ؼ��������� */        
    mDesktopWin->addChild(baseWin, baseWin->getiOrder());

    return baseWin;
}

MMWinXmlData* MMWinManager::createXmlData( TiXmlElement* xmlElement ) {
    MMWinXmlData* xmlData = MMWinXmlData::create();
    TiXmlElement* cldElement = xmlElement->FirstChildElement();

    log("%s %d: ----------------------------", __FILE__, __LINE__);

    /* Ĭ�Ͻڵ�Ϊ�սڵ� */
    xmlData->setNone(true);

    while(cldElement != NULL) {
        /* MMCld�ڵ������Ϊ��,���Բ���ȡ��������,���������ӽڵ� */
        if(cldElement->GetText() != NULL) {
            xmlData->setNone(false);

            /* ���ڵ㸳ֵ */
            setWinXmlData(xmlData, cldElement->Value(), cldElement->GetText());

            CCLog("%s %d:[%s]-[%s]", __FILE__, __LINE__, cldElement->Value(), cldElement->GetText());
        }
        else {
            /* ������ӽڵ�,���������,������ӵ���ǰ�ڵ���ӽڵ��б� */
            if(cldElement->FirstChildElement() != NULL) {
                xmlData->addCldXmlData(createXmlData(cldElement));
            }
        }

        /* ��һ��ͬ���ڵ� */
        cldElement = cldElement->NextSiblingElement();
    }

    return xmlData;
}

void MMWinManager::setWinXmlData( MMWinXmlData* xmlData, const char* sName, const char* sText ) {
    mWinXmlDataSetting->setWinXmlData(xmlData, sName, sText);
}

MMDesktopWin* MMWinManager::getDesktopWin() {
    return this->mDesktopWin;
}

MMWinSystem* MMWinManager::getWinSystem() {
    return this->mWinSystem;
}
