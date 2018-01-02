//
//  MonsterManager.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/20.
//
//

#ifndef MonsterManager_hpp
#define MonsterManager_hpp

#include <stdio.h>
//#include "cocos2d.h"
#include "Monster.hpp"
//USING_NS_CC;

#define MAX_MONSTER_COUNT 10
class MonsterManager : public Node{
public:
    CREATE_FUNC(MonsterManager);
    virtual bool init();
    virtual void update(float delta);
    void bindPlayer(Player *player);
    
private:
    void createMonsters();//创建怪物方法
private:
    Vector<Monster*> m_monsterArr;//存放怪物 数组
    Player *m_player;//玩家对象
};

#endif /* MonsterManager_hpp */
