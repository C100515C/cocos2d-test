//
//  HeroG.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/30.
//

#include "HeroG.hpp"
#include "CsvUtil.hpp"
#include "CommDefine.h"
#include "HeroPropConfType.h"
#include "GlobalPath.h"
#include "MonsterG.hpp"
#include "BulletManager.hpp"

HeroG::HeroG(){
    m_isAtkCoolDown = false;
    m_atkMonster = NULL;
    m_bulletManager = NULL;
}
HeroG::~HeroG(){
    
}

HeroG *HeroG::create(cocos2d::Sprite *sprite){
    HeroG * hero = new HeroG();
    if (hero&&hero->init(sprite)) {
        hero->autorelease();
        
    }else{
        CC_SAFE_DELETE(hero);
        hero = NULL;
    }
    
    return hero;
}

bool HeroG::init(cocos2d::Sprite *sprite){
    if (!EntityG::init()) {
        return false;
    }
    bool ref = false;
    do {
        CC_BREAK_IF(!sprite);
        bindSprite(sprite);
        
        //创建子弹管理类对象
        m_bulletManager = BulletManager::create();
        this->addChild(m_bulletManager);
        
        ref = true;
    } while (0);
    
    
    return ref;
}

HeroG *HeroG::createFromCSVFileByID(int iHeroID){
    
    HeroG * hero = new HeroG();
    if (hero&&hero->initFromCSVFileByID(iHeroID)) {
        hero->autorelease();
//        hero->retain();
    }else{
        CC_SAFE_DELETE(hero);
        hero = NULL;
    }
    
    return hero;
    
}

bool HeroG::initFromCSVFileByID(int iHeroID){
    
    if (!EntityG::init()) {
        return false;
    }
    bool ref = false;
    do {
        CsvUtil *csvUtil = CsvUtil::getIntance();
        std::string sHeroID = StringUtils::toString(iHeroID);
        
        //查找id所在的行
        int iLine = csvUtil ->findValueInWithLine(sHeroID.c_str(),enHeroPropConf_ID , PATH_CSV_HERO_CONF);
        
        CC_BREAK_IF(iLine<0);
        
        setID(iHeroID);
        setmodelID(csvUtil->getInt(iLine, enHeroPropConf_ModelID, PATH_CSV_HERO_CONF));
        setiBaseAtk(csvUtil->getInt(iLine, enHeroPropConf_BaseAtk, PATH_CSV_HERO_CONF));
        setiCurrentAtk(getiBaseAtk());
        setiAtkSpeed(csvUtil->getInt(iLine, enHeroPropConf_AtkSpeed, PATH_CSV_HERO_CONF));
        setiAtkRange(csvUtil->getInt(iLine, enHeroPropConf_AtkRange, PATH_CSV_HERO_CONF));
        setiUpgradeAtkBase(csvUtil->getInt(iLine, enHeroPropConf_UpgradeAtkBase, PATH_CSV_HERO_CONF));
        setiUpgradeCostBase(csvUtil->getInt(iLine, enHeroPropConf_UpgradeCostBase, PATH_CSV_HERO_CONF));

        Sprite *sprite = Sprite::create(StringUtils::format(PATH_HERO_PIC_HEADER,iHeroID).c_str());

        CC_BREAK_IF(!sprite);
        bindSprite(sprite);
        
        //创建子弹管理类对象
        m_bulletManager = BulletManager::create();
        this->addChild(m_bulletManager);
        
        ref = true;
        
    } while (0);
    
    
    return ref;

    
}

void HeroG::upgrade(){
}

void HeroG::checkAtkMonster(float ft, Vector<MonsterG *> monsterList){
    if (m_atkMonster!=NULL) {
        if (m_atkMonster->isDead()) {
            monsterList.eraseObject(m_atkMonster);
            m_atkMonster = NULL;
            return;
        }
        
        //攻击冷却结束
        if (m_isAtkCoolDown==false) {
            atk();
        }
        
        //判断怪物是否离开范围
        checkAimIsOutOfRange(monsterList);
        
    }else{
        chooseAim(monsterList);
    }
    
    
}

void HeroG::atk(){
    BulletBase *bullet = m_bulletManager->getAnyUnUsedBullet();
    if (bullet!=NULL) {
        //根据英雄数据设置子弹属性
        Point heroWorldPos = this->getParent()->convertToWorldSpace(this->getPosition());
        bullet ->setPosition(bullet->getParent()->convertToNodeSpace(heroWorldPos));
        bullet -> setiAtkValue(this->getiCurrentAtk());
        bullet->lockAim(m_atkMonster);
        
        //攻击冷却标记 不能在攻击
        m_isAtkCoolDown = true;
//        log("atk");
        this->schedule(schedule_selector(HeroG::atkCoolDown),getiSpeed()/1000.0f);
    }
    
}

void HeroG::atkCoolDown(float dt){
    m_isAtkCoolDown = false;
}

void HeroG::chooseAim(Vector<MonsterG *>monsterList){
    for(auto monster:monsterList){
        if (monster->isVisible() && isInAtkRange(monster->getPosition())) {
            
            chooseAtkMonster(monster);
            break;
        }
    }
}

void HeroG::checkAimIsOutOfRange(Vector<MonsterG *>monsterList){
    if (m_atkMonster!=NULL) {
        if (isInAtkRange(m_atkMonster->getPosition())==false) {
            missAtkMonster();
        }
    }
}

void HeroG::missAtkMonster(){
    m_atkMonster = NULL;
    log("Monster miss");
}

bool HeroG::isInAtkRange(Point point){
    int atkRange = getiAtkRange();
    
    Point hPoint = this->getPosition();
    
    float length = point.getDistanceSq(hPoint);//两点之间的距离 没开根号的结果 所以下面要攻击距离的平方
    if (length<= atkRange*atkRange) {
        return true;
    }
    
    return false;
}

void HeroG::chooseAtkMonster(MonsterG* monster){
    m_atkMonster = monster;
}

