//
//  MMWinSystem.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/3.
//

#include "MMWinSystem.hpp"
#include "MMBase.hpp"
#include "MMDeskTopWin.hpp"
#include "XMLData.hpp"
//#include "MMWinBaseFactory.hpp"
#include "MMWinFactory.hpp"
#include "MMWinPropertyFactory.hpp"

bool MMWinSystem::init(MMDeskTopWin *desktopWin){
    
    desktopWin->retain();
    this->mDeskTopWin = desktopWin;
    
    mWinFactory = MMWinFactory::create();
    mWinFactory->retain();
    
    mWinPropertyFactory = MMWinPropertyFactory::create();
    mWinPropertyFactory->retain();
    
    return true;
}

MMWinSystem::MMWinSystem()
: m_winID(0),
mDeskTopWin(NULL),
mWinFactory(NULL),
mWinPropertyFactory(NULL) {
    
}

MMWinSystem::~MMWinSystem() {
    CC_SAFE_RELEASE(mDeskTopWin);
    CC_SAFE_RELEASE(mWinFactory);
    CC_SAFE_RELEASE(mWinPropertyFactory);
}

MMWinSystem *MMWinSystem::create(MMDeskTopWin* deskTopWin){
    MMWinSystem* winSystem = new MMWinSystem();
    
    if(winSystem && winSystem->init(deskTopWin)) {
        winSystem->autorelease();
    }
    else {
        CC_SAFE_DELETE(winSystem);
        winSystem = NULL;
    }
    
    return winSystem;
}

MMBase *MMWinSystem::createWinsByXmlData(XMLData *xmlData, bool isHasParent){
    assert(xmlData && "createWinsByXmlData:xmlData is NULL!");

    //只能 有一个 basewin  所有控件最终都只能有一个总的父控件
    MMBase *baseWin = NULL;
    if(xmlData->isNone()==false){
        baseWin = createWinByXmlData(xmlData);
    }
    
    if (xmlData->isHaveChild()) {
        if (baseWin != NULL) {
            baseWin -> setHasChildWin(true);
            
            if (isHasParent==false) {
                //根据类型给控件设置属性 父控件要在子控件之前设置属性
                dressPropertiesByType(baseWin, xmlData);
            }
        }
        //如果没有父控件，则自身是父控件 父控件要在子控件之前设置属性
        auto cldXmlDataList = xmlData->getChildNodesList();
        for(auto xmlCldData:cldXmlDataList){
            MMBase *mmWin = createWinsByXmlData(xmlCldData,true);
            baseWin ->addChild(mmWin);
            mmWin ->setHasParentWin(true);
            //根据类型给控件设置属性 如果没有父控件，则自身是父控件 父控件要在子控件之前设置属性 在之前已经设置了
            if (mmWin->isHasParentWin()==true) {
                dressPropertiesByType(mmWin, xmlCldData);
            }
        }
    }
    
    return baseWin;
}

MMBase * MMWinSystem::createWinByXmlData(XMLData *xmlData){
    assert(xmlData&&"createWinByXmlData:xmlData is NULL");
    
    WinType type = xmlData ->getwinType();
    MMBase *baseWin = createWinByType(type);
    return baseWin;
}

MMBase *MMWinSystem::createWinByType(WinType enWinType){
    return mWinFactory ->createWinByType(enWinType);
}

void MMWinSystem::dressPropertiesByType(MMBase *baseWin, XMLData *xmlData){
    mWinPropertyFactory ->dressPropertiesByType(baseWin,xmlData);
}

int MMWinSystem::createUniqueID(){
    m_winID += 1;
    return m_winID;
}

