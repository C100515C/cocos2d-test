//
//  BulletBase.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2018/1/4.
//

#ifndef BulletBase_hpp
#define BulletBase_hpp

#include <stdio.h>
#include "EntityG.hpp"

class BulletBase:public EntityG{
public:
    BulletBase();
    ~BulletBase();
    
    
    /**
     锁定 目标

     @param entity entity description
     */
    void lockAim(EntityG *entity);
    
    /**
     获取目标

     @return return value description
     */
    EntityG *getAim();
    bool isArrive();
    
    
    /**
     设置是否在使用

     @param m_isUsed m_isUsed description
     */
    void setUsed(bool m_isUsed);
    bool isUsed();
    
protected:
    
    /**
     锁定目标是 调用 子类重写

     @param aim aim description
     */
    virtual void onLockAim(EntityG *aim)=0;
    bool m_isArrived;//是否到达目标
private:
    bool m_isUsed;
    EntityG *m_aim;//目标
    
    CC_SYNTHESIZE(int, m_iAtkValue, iAtkValue);//攻击力
    CC_SYNTHESIZE(int,m_iSpeed,iSpeed);//速度
};

#endif /* BulletBase_hpp */
