//
//  MonsterG.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/12/25.
//

#include "MonsterG.hpp"
#include "CsvUtil.hpp"
#include "GlobalPath.h"
#include "MonsterPropConfType.h"

MonsterG::MonsterG(){
    m_moveController = NULL;
    m_iSpeed = NULL;
}

MonsterG::~MonsterG(){
    
}

bool MonsterG::init(){
    if (!Node::init()) {
        return false;
    }
    
    m_moveController = ControllerSimpleMove::create(this);
    this->addChild(m_moveController);
    
    return true;
}

bool MonsterG::initFromCSVFileByID(int iMonsterID){
    bool ret = false;
    
    do{
        CsvUtil *csvUtil = CsvUtil::getIntance();
        
        std::string sMonsterId = StringUtils::format("%d",iMonsterID);
        
        //寻找 id 所在的行
        int line = csvUtil ->findValueInWithLine(sMonsterId.c_str(),enMonsterPropConf_ID, PATH_CSV_MONSTER_CONF);
        CC_BREAK_IF(line<0);
        
        setID(iMonsterID);
        setiLevel(csvUtil->getInt(line,enMonsterPropConf_Level, PATH_CSV_MONSTER_CONF));
        setmodelID(csvUtil->getInt(line,enMonsterPropConf_ModelID, PATH_CSV_MONSTER_CONF));
        setHP(csvUtil->getInt(line,enMonsterPropConf_HP, PATH_CSV_MONSTER_CONF));
        setiDefense(csvUtil->getInt(line,enMonsterPropConf_Defense, PATH_CSV_MONSTER_CONF));
        setiSpeed(csvUtil->getInt(line,enMonsterPropConf_MoveSpeed, PATH_CSV_MONSTER_CONF));

        CC_BREAK_IF(!init());
        
        ret = true;
    }while (0);
    
    return ret;
}

MonsterG * MonsterG::createFromCSVFileByID(int iMonsterID){
    MonsterG *monster = new MonsterG();
    if (monster&&monster->initFromCSVFileByID(iMonsterID)) {
        monster-> retain();
        monster->autorelease();
    }else{
        CC_SAFE_DELETE(monster);
        monster = NULL;
        
    }
    return monster;
}

void MonsterG::moveByPosList(Vector<PosBase *> posList){
    if (posList.size()<1) {
        return;
    }
    
    m_moveController->moveByPosList(posList,getiSpeed(),getfShowTime());
}
