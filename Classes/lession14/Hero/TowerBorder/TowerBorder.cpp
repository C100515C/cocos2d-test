//
//  TowerBorder.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/30.
//

#include "TowerBorder.hpp"
#include "GlobalPath.h"
#include "HeroG.hpp"

TowerBorder ::TowerBorder(){
    m_iLevel = 1;
    m_iHero = NULL;
}

TowerBorder::~TowerBorder(){}

bool TowerBorder::init(){
    return true;
}

void TowerBorder ::upgrade(){
    if (getSprite()!=NULL) {
        getSprite()->stopAllActions();
    }
    
    std::string sFilePath = StringUtils::format(PATH_BORDER_PIC_HEADER,m_iLevel);
    Sprite *sprite = Sprite::create(sFilePath.c_str());
    bindSprite(sprite);
    
    m_iLevel ++;
    
    if (m_iLevel==2) {
        auto rotate = RotateBy::create(25.0f, 360, 360);
        auto repeat = RepeatForever::create(rotate);
        
        std::string sFilePath1 = StringUtils::format(PATH_BORDER_MAGIC_PIC_HEADER,m_iLevel);
        Sprite *sprite1 = Sprite::create(sFilePath1.c_str());
        sprite1 -> setOpacity(80);
        sprite1 -> runAction(repeat);
        this ->addChild(sprite1,10);
        
    }
}

bool TowerBorder::isClickMe(Point pos){
    Size size = getSprite()->getContentSize();
    Point point = getPosition();
    
    Point start = Point(point.x-size.width/2.0,point.y-size.height/2.0);
    Point end = Point(point.x+size.width/2.0,point.y+size.height/2.0);
    
    if ((pos.x>=start.x&&pos.x<=end.x) && (pos.y<=end.y&&pos.y>=start.y)) {
        return true;
    }
    return false;
}

void TowerBorder::bindHero(HeroG *iHero){
//    deleteHero();
    m_iHero = iHero;
}

HeroG *TowerBorder::getHero(){
    return m_iHero;
}

void TowerBorder::deleteHero(){
    if (m_iHero!=NULL) {
        m_iHero ->removeFromParent();
//        CC_SAFE_DELETE(m_iHero);
        m_iHero = NULL;
    }
}

