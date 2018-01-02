//
//  EntityG.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/28.
//

#include "EntityG.hpp"
EntityG::~EntityG(){
    
}
EntityG::EntityG(){
    m_sprite = NULL;
    m_sName = "";
    m_iLevel = 1;
    m_isDead = false;
    m_HP = 1;
    m_iSpeed = 1;
    m_iDefense = 1;
    
}

void EntityG::bindSprite(Sprite *sprite){
    if (this->m_sprite !=NULL) {
        this->removeAllChildrenWithCleanup(true);
    }
    
    this->m_sprite = sprite;
    this ->addChild(m_sprite);
    Size size = this->m_sprite->getContentSize();
    this ->setContentSize(size);
//    m_sprite ->setPosition(size.width/2.0, size.height/2.0);
    
    onBindSprite();
}

Sprite *EntityG::getSprite(){
    return this->m_sprite;
}

void EntityG::hurtMe(int iHurtValue){
    if (m_isDead) {
        return;
    }
    
    //当伤害值小于 等于防御 伤害值最小 为1
    if (iHurtValue<=getiDefense()) {
        iHurtValue = 1;
    }
    
    int currtentHP = getHP();
    int affterHurtHP = currtentHP - iHurtValue;
    
    onHurt(iHurtValue);

    if (affterHurtHP>0) {
        setHP(affterHurtHP);
    }else{
        m_isDead = true;
        onDead();
    }
}

bool EntityG::isDead(){
    return this->m_isDead;
}

void EntityG::onDead(){
    
}

void EntityG::onBindSprite(){
    
}

void EntityG::onHurt(int iHurtValue){
    
}
