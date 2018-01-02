//
//  MonsterManager.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/20.
//
//

#include "MonsterManager.hpp"
#include "Player.hpp"

bool MonsterManager::init(){
    if (!Node::init()) {
        return false;
    }
    createMonsters();
    this ->scheduleUpdate();
    
    return true;
}

void MonsterManager::createMonsters(){
    Monster *monster = NULL;
    Sprite *sprite = NULL;
    
    for (int i=0; i<MAX_MONSTER_COUNT; i++) {
        //创建怪物
        monster = Monster::create();
        sprite = Sprite::create("monster.png");
        monster -> bindSprite(sprite);
        monster -> reset();
        
        this -> addChild(monster);
        
        m_monsterArr.pushBack(monster);
        
    }
}

void MonsterManager::update(float delta){
    for(auto monster : m_monsterArr){
        if (monster->isActive()) {
            monster -> setPositionX(monster->getPositionX()-4);
            if (monster->getPositionX()<0) {
                monster ->hide();
            }else if (monster->isCollideWithPlayer(m_player)) {
                m_player -> hit();
                monster ->hide();
            }
        }else{
            
            monster -> show();
        }
    
    }
    
}

void MonsterManager::bindPlayer(Player *player){
    m_player = player;
}
