//
//  MMWinManager.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/2.
//

#include "MMWinManager.hpp"

#include "XMLDataSetting.hpp"
#include "MMBase.hpp"
#include "tinyxml.h"
#include "XMLData.hpp"

MMWinManager * MMWinManager::mWinManager = NULL;

MMWinManager *MMWinManager::getInstance(){
    if (mWinManager==NULL) {
        mWinManager = new  MMWinManager();
        if (mWinManager &&mWinManager->init()) {
            mWinManager -> autorelease();
//            mWinManager->retain();
            
        }else{
            CC_SAFE_DELETE(mWinManager);
            mWinManager = NULL;
        }
    }
   
    return mWinManager;
}

MMWinManager::MMWinManager(){
    
}

bool MMWinManager::init(){
    mDeskTopWin = MMDeskTopWin::create();
    mDeskTopWin -> retain();
    
    mWinSystem = MMWinSystem::create(mDeskTopWin);
    mWinSystem -> retain();
    
    mXMLDataSetting = XMLDataSetting::create();
    mXMLDataSetting ->retain();
    
    return true;
}

MMWinManager::~MMWinManager(){
    CC_SAFE_RELEASE_NULL(mXMLDataSetting);
    CC_SAFE_RELEASE_NULL(mWinSystem);
    CC_SAFE_RELEASE_NULL(mDeskTopWin);

}

MMBase* MMWinManager::createWinFromXmlData(const char *sName){
    std::string  path = FileUtils::getInstance() ->fullPathForFilename(sName);
    
    TiXmlDocument *doc = new TiXmlDocument();
    Data fileData = FileUtils::getInstance()->getDataFromFile(path);
    doc -> Parse((const char *)fileData.getBytes());
    
    TiXmlElement *root = doc->RootElement();
    XMLData *xmlData = createXmlData(root->FirstChildElement());
    delete doc;
    
    //生成控件
    MMBase *baseWin = mWinSystem->createWinsByXmlData(xmlData,false);
    if (baseWin->isHasChildWin()==false) {
        mWinSystem ->dressPropertiesByType(baseWin,xmlData);
    }
    
    //添加父控件到桌面
    mDeskTopWin -> addChild(baseWin,baseWin->getmOrder());
    
    return baseWin;
}

XMLData *MMWinManager::createXmlData(TiXmlElement *xmlElement){
    XMLData *xmlData = XMLData::create();
    TiXmlElement *cldElement = xmlElement -> FirstChildElement();
    
    xmlData -> setNone(true);//设置默认节点
    
    while (cldElement!=NULL) {
        if (cldElement->GetText()!=NULL) {
            xmlData ->setNone(false);
            setWinXmlData(xmlData, cldElement->Value(), cldElement->GetText());
        }else{
            if (cldElement->FirstChildElement()!=NULL) {
                xmlData ->addChildNodeXMLData(createXmlData(cldElement));
            }
        }
        //同级下一个 节点
        cldElement = cldElement ->NextSiblingElement();
    }
    
    return xmlData;
}

void MMWinManager::setWinXmlData(XMLData *xmlData, const char *sName, const char *sText){
    mXMLDataSetting ->setXmlData(xmlData, sName, sText);
}

MMDeskTopWin* MMWinManager::getDeskTopWin(){
    return this -> mDeskTopWin;
}

MMWinSystem* MMWinManager::getWinSystem(){
    return this ->mWinSystem;
}

