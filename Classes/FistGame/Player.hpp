//
//  Player.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/19.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Entity.hpp"
#include "FlowWord.hpp"

#define JUMP_ACTION_TAG 1

class Player : public Entity{
public:
    Player();
    ~Player();
    CREATE_FUNC(Player);
    bool init();
    void jump();//跳跃
    
    void hit();//受攻击
    int getHP();
    void resetData();
private:
    bool m_isJumping;//标记 主角是否在跳
    int m_HP;//主角 血量

};

#endif /* Player_hpp */
