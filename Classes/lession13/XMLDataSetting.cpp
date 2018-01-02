//
//  XMLDataSetting.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/10/31.
//

#include "XMLDataSetting.hpp"

void XMLDataSetting::setXmlEnWinType(XMLData *xmlData, const char *sText){
    if (strcmp(sText, WinType_C_en_Win_None)==0) {
        xmlData -> setwinType(en_Win_None);
    }else if (strcmp(sText, WinType_C_en_Win_NormalWin)==0){
        xmlData -> setwinType(en_Win_Normal);
    }else if (strcmp(sText, WinType_C_en_Win_Label)==0){
        xmlData -> setwinType(en_Win_Label);
    }
}

void XMLDataSetting::setXmliX(XMLData *xmlData, const char *sText){
    xmlData -> setiX(atoi(sText));
}

void XMLDataSetting::setXmliY(XMLData *xmlData, const char *sText){
    xmlData -> setiY(atoi(sText));
}

void XMLDataSetting::setXmlData(XMLData *xmlData, const char *sName, const char *sText){
    if (strcmp(sName, XML_VALUE_enWinType)==0) {
        setXmlEnWinType(xmlData, sText);
    }else if (strcmp(sName, XML_VALUE_x)==0){
        setXmliX(xmlData, sText);
    }else if (strcmp(sName, XML_VALUE_y)==0){
        setXmliY(xmlData, sText);
    }
}

bool XMLDataSetting::init(){
    
    return true;
}


