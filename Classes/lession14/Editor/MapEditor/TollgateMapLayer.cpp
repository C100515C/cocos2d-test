//
//  TollgateMapLayer.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/28.
//

#include "TollgateMapLayer.hpp"
//音乐播放库
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"

#include "HeroManagerG.hpp"
#include "MonsterManagerG.hpp"
#include "MonsterG.hpp"

#define HOME_LAYER_LVL 3
#define MONSTER_LAYER_LVL 15
#define BULLET_LAYER_LVL 20
#define HERO_LAYER_LVL 10

TollgateMapLayer::~TollgateMapLayer(){}

TollgateMapLayer::TollgateMapLayer(){
    m_currentLevel = 1;
}

bool TollgateMapLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    
    bool bRet = false;
    
    do{
        //读取关卡
        loadConfig();
        
        //创建英雄管理
        m_heroManager = HeroManagerG::createWithLevel(m_currentLevel);
        this ->addChild(m_heroManager,HERO_LAYER_LVL);
        
        //创建 怪物管理类
        m_monsterManager = MonsterManagerG::createWithLevel(m_currentLevel);
        this -> addChild(m_monsterManager,MONSTER_LAYER_LVL);
        
        this->schedule(schedule_selector(TollgateMapLayer::logic));
        
        bRet = true;
    }while(0);
    
    return true;
}

void TollgateMapLayer::logic(float dt){
    m_heroManager->logic(dt,m_monsterManager->getMonsterList());
}

void TollgateMapLayer::loadConfig(){
    Size size = Director::getInstance()->getVisibleSize();
    //加载 背景音乐
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(StringUtils::format("tollgate_%d.mp3",m_currentLevel).c_str(),true);
    
    //加载背景图
    Sprite *bgSprite = Sprite::create(StringUtils::format("level_%d.jpg",m_currentLevel).c_str());
    bgSprite->setPosition(size.width/2.0, size.height/2.0);
    this -> addChild(bgSprite,1);
}

