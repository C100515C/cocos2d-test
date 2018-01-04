//
//  NormalBullet.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2018/1/4.
//

#include "NormalBullet.hpp"
#include "GlobalPath.h"

NormalBullet::NormalBullet(){
    m_iSpeed = SPEED;
}

NormalBullet::~NormalBullet(){}

bool NormalBullet::init(){
    
    if (!EntityG::init()) {
        return false;
    }
    bool ret = false;
    do{
        Sprite *sprite = Sprite::create(PATH_BULLET_PIC_NORMAL);
        CC_BREAK_IF(!sprite);
        CC_BREAK_IF(!init(sprite));
        
        ret = true;
    }while(0);
    
    return ret;
}

NormalBullet *NormalBullet::create(cocos2d::Sprite *sprite){
    NormalBullet *bullet = new NormalBullet();
    if (bullet && bullet->init(sprite)) {
        bullet->retain();
        bullet->autorelease();
    }else{
        CC_SAFE_DELETE(bullet);
        bullet = NULL;
    }
    
    return bullet;
}

bool NormalBullet::init(cocos2d::Sprite *sprite){
    
    bindSprite(sprite);
    
    return true;
}

void NormalBullet::onLockAim(EntityG *aim){
    m_isArrived = false;
    
    Point aimWorldPos = aim->getParent()->convertToWorldSpace(aim->getPosition());
    Point destPos = this->getParent()->convertToNodeSpace(aimWorldPos);
    
    auto moveTo = MoveTo::create(0.5f, destPos);
    auto func = CallFunc::create([&](){
        moveEnd();
    });
    
    auto action = Sequence::create(moveTo,func, NULL);
    this -> runAction(action);
}

void NormalBullet::moveEnd(){
    m_isArrived = true;
}
