//
//  MMNormalWin.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/1.
//

#include "MMNormalWin.hpp"

MMWinNormal::MMWinNormal(){
    m_sprite = NULL;
}

MMWinNormal::~MMWinNormal(){
    
}

bool MMWinNormal::init(){
    if (!MMBase::init()) {
        return false;
    }
   
    return true;
}

void MMWinNormal::setBG(const char *sPath){
    if (m_sprite!=NULL) {
        this ->removeChild(m_sprite);
    }
    
    m_sprite = Sprite ::create(sPath);
    this -> addChild(m_sprite);
    
    Size size = Director::getInstance()->getVisibleSize();
    m_sprite -> setPosition(size.width*0.5, size.height*0.5);
    this -> setContentSize(size);
    
}

void MMWinNormal::setAnchorPoint(const Point &anchorPoint){
    Node::setAnchorPoint(anchorPoint);//
    m_sprite ->setAnchorPoint(anchorPoint);
}

