//
//  BulletManager.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2018/1/4.
//

#ifndef BulletManager_hpp
#define BulletManager_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

#define BULLET_MAX_STORE_COUNT 10
#define BULLET_CHECK_Interval 1
#include "NormalBullet.hpp"

class BulletManager:public Node{
public:
    BulletManager();
    ~BulletManager();
    
    static BulletManager *create();
    bool init();
    
    /**
     存缓存中获取 任意未使用的子弹

     @return return value description
     */
    BulletBase *getAnyUnUsedBullet();
    
private:
    Vector<BulletBase *>m_bulletList;
    
    /**
     创建缓存子弹

     @param parent parent description
     */
    void createBullets(Node *parent);
    
    /**
     子弹逻辑

     @param dt dt description
     */
    void bulletLogicCheck(float dt);
};

#endif /* BulletManager_hpp */
