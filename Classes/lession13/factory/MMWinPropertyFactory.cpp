//
//  MMWinPropertyFactory.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/3.
//

#include "MMWinPropertyFactory.hpp"
#include "MMNormalWin.hpp"
#include "MMLabel.hpp"
#include "XMLData.hpp"
//#include "MMBase.hpp"

bool MMWinPropertyFactory::init(){
    return true;
}

void MMWinPropertyFactory::dressPropertiesByType(MMBase *baseWin, XMLData *xmlData){
    switch (baseWin->getEnWinType()) {
        case en_Win_None:
            break;
            
        case en_Win_Normal:
            dressMMNormalWin((MMWinNormal*)baseWin, xmlData);
            break;
            
        case en_Win_Label:
            dressMMLabel((MMLabel*)baseWin, xmlData);

            break;
            
        default:
            break;
    }
    //设置基础属性
    dressBaseProperties(baseWin, xmlData);
    
}

void MMWinPropertyFactory::dressBaseProperties(MMBase *baseWin, XMLData *xmlData){
    MMBase *parent = NULL;
    if (baseWin->isHasParentWin()) {
        parent = (MMBase*)baseWin->getParent();
    }
    
    baseWin -> setPositionX(xmlData->getiX());
    baseWin -> setPositionY(xmlData->getiY());
}

void MMWinPropertyFactory::dressMMNormalWin(MMWinNormal *normalWin, XMLData *xmlData){
    normalWin ->setBG("bg.jpg");
}

void MMWinPropertyFactory::dressMMLabel(MMLabel *label, XMLData *xmlData){
    label -> setsText("测试");
}





