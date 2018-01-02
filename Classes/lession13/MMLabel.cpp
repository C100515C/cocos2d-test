//
//  MMLabel.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/1.
//

#include "MMLabel.hpp"

MMLabel::MMLabel(){
    m_label = NULL;
}

MMLabel::~MMLabel(){
    
}

bool MMLabel::init(){
    if (!MMBase::init()) {
        return false;
    }
    m_label = Label :: createWithSystemFont("", "Arial", 24);
    this -> addChild(m_label);
    return true;
}

void MMLabel::setsText(const char *sText){
    m_label -> setString(sText);
}

void MMLabel::setsText(int iValue){
    m_label -> setString(StringUtils::toString(iValue).c_str());
}

void MMLabel::setFontSize(int fontSize){
    m_label -> setSystemFontSize(fontSize);
    
}

void MMLabel::setAnchorPoint(const Point &anchorPoint){
    Node::setAnchorPoint(anchorPoint);
    m_label -> setAnchorPoint(anchorPoint);
}

void MMLabel::setFontColor(int r, int g, int b){
    m_label -> setTextColor(Color4B(r, g, b, 1));
}

