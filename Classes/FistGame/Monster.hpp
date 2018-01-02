//
//  Monster.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/20.
//
//

#ifndef Monster_hpp
#define Monster_hpp

#include <stdio.h>
#include "Entity.hpp"
class Player;
class Monster : public Entity{
public:
    Monster();
    ~Monster();
    CREATE_FUNC(Monster);
    virtual bool init();
    
    bool isCollideWithPlayer(Player *player);//检测是否碰撞

private:
    bool m_isActive;//判断 活动状态
    
public:
    void show();
    void hide();
    void reset();//重置怪我数据
    bool isActive();//获得活动状态
    
};

#endif /* Monster_hpp */
