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

HeroG::HeroG(){}
HeroG::~HeroG(){}

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
        
        ref = true;
        
    } while (0);
    
    
    return ref;

    
}

void HeroG::upgrade(){
    
}
