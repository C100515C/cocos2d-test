//
//  XMLData.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/10/30.
//

#include "XMLData.hpp"

bool XMLData::init(){
    m_isNone = false;
    mWinType = en_Win_None;
    m_iX = 0;
    m_iY = 0;
    return true;
}

void XMLData::addChildNodeXMLData(XMLData *childXMLData){
   this ->mChildNodeList.pushBack(childXMLData);
}

Vector<XMLData*>XMLData::getChildNodesList(){
    return this->mChildNodeList;
}

bool XMLData::isHaveChild(){
    if (this->mChildNodeList.size() >0) {
        return true;
    }else{
        return false;

    }
}
