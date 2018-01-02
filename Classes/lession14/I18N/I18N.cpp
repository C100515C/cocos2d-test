//
//  I18N.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/27.
//

#include "I18N.hpp"
#include "CsvUtil.hpp"
#include "GlobalPath.h"

I18N *I18N::m_i18n=NULL;

I18N *I18N::getInstance(){
    if (m_i18n==NULL) {
        m_i18n = new I18N();
        if(m_i18n&&m_i18n->init()){
            m_i18n ->autorelease();
            m_i18n ->retain();
        }else{
            CC_SAFE_DELETE(m_i18n);
            m_i18n = NULL;
        }
    }
    return m_i18n;
}

bool I18N::init(){
    
    loadStringFromComf(PATH_PUBLIC);
    
    return true;
}

const char * I18N::getcStringByKey(EnumStrKey key){
    return mStringMap.at(key).c_str();
}

const char *I18N::getcStringByIntKey(int key){
    return mStringMap.at(key).c_str();

}

void I18N::loadStringFromComf(const char *sPath){
    CsvUtil::getIntance()->laodFile(sPath);
    
    Size size = CsvUtil::getIntance()->getFileRowColNum(sPath);
    int row = size.width;
    int col = size.height;
    
    //如果 列数小于2 证明配置文件有问题
    if (col<2) {
        return;
    }
    
    //将配置文件的所有字符串放入map  忽略第一行
    for (int i=1; i<row; i++) {
        int key = CsvUtil::getIntance()->getInt(i, 0, sPath);
        std::string value = CsvUtil::getIntance()->getString(i, 1,sPath);
        mStringMap[key] = value;
    }
    
}


