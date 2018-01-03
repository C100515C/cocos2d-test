//
//  HeroManagerG.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/28.
//

#include "HeroManagerG.hpp"
#include "PosLoadUtil.hpp"
#include "GlobalPath.h"
#include "TowerPos.hpp"
#include "TowerBorder.hpp"
#include "HeroG.hpp"
#include "MonsterG.hpp"

//#include "CommDefine.h"

HeroManagerG::HeroManagerG(){}

HeroManagerG::~HeroManagerG(){}

HeroManagerG *HeroManagerG::createWithLevel(int iCurrentLevel){
    
    HeroManagerG *heroManager = new HeroManagerG();
    if (heroManager && heroManager->initWithLevel(iCurrentLevel)) {
        heroManager->autorelease();
        
    }else{
        CC_SAFE_DELETE(heroManager);
        heroManager = NULL;
    }
    
    return heroManager;
}

bool HeroManagerG::initWithLevel(int iCurrentLevel){
    if (!Node::init()) {
        return false;
    }
    
    //加载塔坐标对象
    std::string path = StringUtils::format(PATH_TOWERPOS_PLIST_HEADER,iCurrentLevel);
//    //进入Documents目录下
//    std::string pathToSave=FileUtils::getInstance()->getWritablePath();
//    //添加到finder文件夹
//    path = pathToSave+path;
    path = DOCUMENT_PATH(path);
    
    Vector<PosBase*> posList = PosLoadUtil::getIntance()->loadPosWithFile(path.c_str(), enTowerPos, this, 10, false);
    m_towerPosList.pushBack(posList);
    
    //创建炮台
    createTowerBorder(iCurrentLevel);
    
    
    //添加监听
    EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
    
    listener->onTouchBegan = [](Touch *touch,Event *event)->bool{
        return true;
    };
    
    listener->onTouchEnded = [&](Touch *touch,Event *event)->void{
        Point point = Director::getInstance()->convertToGL(touch->getLocationInView());
        
        //找到被点击的towerborder
        TowerBorder *towerBorder = findClickTowerBorder(point);
        
        if (towerBorder==NULL) {
            return;
        }

        if (towerBorder->getHero()==NULL) {
            HeroG *hero = HeroG::createFromCSVFileByID(1);
            hero->setPosition(towerBorder->getPosition());
            this -> addChild(hero,TOWER_LYAER_LVL);

            towerBorder->bindHero(hero);
        }
        
    };
    
    _eventDispatcher -> addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void HeroManagerG::createTowerBorder(int iCurrentLevel){
    for(auto tPos:m_towerPosList){
        TowerBorder *border = TowerBorder::create();
        border ->upgrade();
        border ->setPosition(tPos->getPos());
        this -> addChild(border,TOWER_BORDER_LAYER_LVL);
        
        m_towerBordersList.pushBack(border);
    }
    
    
}

void HeroManagerG::createTowerPos(Point pos){
    PosBase *pos1 = TowerPos::create(pos);
    this -> addChild(pos1,TOWER_POS_LAYER_LVL);
    m_towerPosList.pushBack(pos1);
}

TowerBorder *HeroManagerG::findClickTowerBorder(Point pos){
    for(auto towerBorder:m_towerBordersList){
        if (towerBorder->isClickMe(pos)) {
            return towerBorder;
        }
    }
    return NULL;
}

void HeroManagerG::logic(float dt, Vector<MonsterG *> monsterList){
    for (auto border:m_towerBordersList) {
        if (border->getHero()!=NULL) {
            border->getHero()->checkAtkMonster(dt, monsterList);
        }
    }
}


