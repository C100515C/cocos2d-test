//
//  RunEntity.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/24.
//
//

#include "RunEntity.hpp"

void RunEntity::bindSprite(cocos2d::Sprite *sprite){
    m_sprite = sprite;
    this -> addChild(m_sprite);
}

Sprite * RunEntity::getSprite(){
    return m_sprite;
}

void RunEntity::setController(RunController *controller){
    this -> m_runController = controller;
    m_runController ->setControllerListener(this);
}
void RunEntity::setTagPoint(float x, float y){
    this ->setPosition(x, y);
}

Point RunEntity::getTagPoint(){
    return this->getPosition();
}
