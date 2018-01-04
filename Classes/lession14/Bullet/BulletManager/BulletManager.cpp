//
//  BulletManager.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2018/1/4.
//

#include "BulletManager.hpp"

BulletManager::BulletManager(){
   
}

BulletManager::~BulletManager(){}

BulletManager* BulletManager::create(){
    BulletManager *manager = new BulletManager();
    if (manager && manager->init()) {
        manager ->retain();
        manager ->autorelease();
    }else{
        CC_SAFE_DELETE(manager);
        manager = NULL;
    }
    return manager;
}

bool BulletManager::init(){
    if (!Node::init()) {
        return false;
    }
    
    createBullets(_parent);
    
    //循环检查 子弹逻辑
    this ->schedule(schedule_selector(BulletManager::bulletLogicCheck),BULLET_CHECK_Interval);
    
    return true;
}

void BulletManager::bulletLogicCheck(float dt){
    for(auto bullet :m_bulletList){
        if (bullet->isUsed()) {
            auto aim = bullet ->getAim();
            
            if (aim!=NULL) {
                if (bullet->isArrive()) {
                    aim ->hurtMe(bullet->getiAtkValue());
                    bullet ->setUsed(false);
                }
            }
        }
    }
}

void BulletManager::createBullets(cocos2d::Node *parent){
    BulletBase *base = NULL;
    for (int i=0; i<BULLET_MAX_STORE_COUNT; i++) {
        base = NormalBullet::create();
        m_bulletList.pushBack(base);
        base->setUsed(false);
        this-> addChild(base);
    }
}

BulletBase * BulletManager::getAnyUnUsedBullet(){
    for(auto bullet :m_bulletList){
        if (bullet->isUsed()==false) {
            bullet->setUsed(true);
            return bullet;
        }
    }
    return NULL;
}
