//
//  BulletBase.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2018/1/4.
//

#include "BulletBase.hpp"

BulletBase::BulletBase(){
    m_aim = NULL;
    m_iSpeed = SPEED;
    m_isUsed = false;
    m_iAtkValue = 1;
    m_isArrived = false;
}
BulletBase::~BulletBase(){}

void BulletBase::setUsed(bool m_isUsed){
    this -> m_isUsed = m_isUsed;
    setVisible(this->m_isUsed);
}

bool BulletBase::isUsed(){
    return this->m_isUsed;
}

void BulletBase::lockAim(EntityG *entity){
    if (entity!=NULL) {
        m_aim = entity;
        onLockAim(m_aim);
    }
}

EntityG *BulletBase::getAim(){
    return this->m_aim;
}

bool BulletBase::isArrive(){
    return this->m_isArrived;
}
