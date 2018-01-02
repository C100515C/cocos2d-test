//
//  Monster.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/20.
//
//

#include "Monster.hpp"
#include "Player.hpp"

Monster::Monster(){
    
   this-> m_isActive = false;
}

Monster::~Monster(){
}

bool Monster::init(){

    if (!Entity::init()) {
        return false;
    }
    
    return true;
}

void Monster::show(){
    if (getSprite()==NULL) {
        return;
    }
    
    this -> setVisible(true);
    this -> m_isActive = true;
}

void Monster::hide(){
    if (getSprite()==NULL) {
        return;
    }
    this -> setVisible(false);
    this -> reset();
    this -> m_isActive = false;
    
}

void Monster::reset(){
    if (getSprite()==NULL) {
        return;
    }
    
    this -> setPosition(800+CCRANDOM_0_1()*500, 200-CCRANDOM_0_1()*100);
    
    
}

bool Monster::isActive(){
    return this -> m_isActive;
}

bool Monster::isCollideWithPlayer(Player *player){
    Rect rect = player -> getBoundingBox();
    
    Point point = this->getPosition();
    
    return rect.containsPoint(point);
}

