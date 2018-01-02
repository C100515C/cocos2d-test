//
//  EntityG.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/28.
//

#ifndef EntityG_hpp
#define EntityG_hpp

#include <stdio.h>
#include "CommDefine.h"
#include "cocos2d.h"
USING_NS_CC;

class EntityG : public Node{
public:
    ~EntityG();
    EntityG();
    
    
    /**
     绑定 精灵

     @param sprite sprite
     */
    void bindSprite(Sprite *sprite);
    
    /**
     获取精灵

     @return return value description
     */
    Sprite *getSprite();
    
    /**
     被攻击

     @param iHurtValue 伤害值
     */
    void hurtMe(int iHurtValue);
    
    /**
     是否死亡

     @return return value description
     */
    bool isDead();
    
protected:
    virtual void onDead();
    virtual void onBindSprite();
    virtual void onHurt(int iHurtValue);
    
private:
    Sprite *m_sprite;
    
    CC_SYNTHESIZE(int, m_ID, ID);//实体id
    CC_SYNTHESIZE(int , m_modelID, modelID);//资源id 模型 id
    CC_SYNTHESIZE(std::string, m_sName, sName);//名字
    CC_SYNTHESIZE(int, m_HP, HP);//血量
    CC_SYNTHESIZE(int, m_iDefense, iDefense);//防御
    CC_SYNTHESIZE(int, m_iSpeed,iSpeed);//移动速度
    CC_SYNTHESIZE(int, m_iLevel, iLevel);//等级
    
    bool m_isDead;//是否死亡
};

#endif /* EntityG_hpp */
