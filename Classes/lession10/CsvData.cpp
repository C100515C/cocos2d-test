//
//  CsvData.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/3.
//
//

#include "CsvData.hpp"

bool CsvData::init(){
    return true;
}

void CsvData::addLineData(ValueVector lineData){
    m_allLinesVec.push_back(Value(lineData));
}

cocos2d::ValueVector CsvData::getSingleLineData(int iLine){
   cocos2d::ValueVector line = m_allLinesVec.at(iLine).asValueVector();
    return line;
}

Size CsvData::getRowColNum(){
    Size size;
    size.width = m_allLinesVec.size();
    if (size.width>0) {
        size.height = m_allLinesVec.at(0).asValueVector().size();
    }
    return size;
}
