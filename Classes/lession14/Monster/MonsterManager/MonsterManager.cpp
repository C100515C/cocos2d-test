//
//  MonsterManager.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/12/25.
//

#include "MonsterManager.hpp"
#include "MonsterG.hpp"
#include "MonsterPos.hpp"
#include "PosBase.hpp"
#include "PosLoadUtil.hpp"
#include "GlobalPath.h"
#include "CsvUtil.hpp"

MonsterManager::MonsterManager(){
    m_fShowTimeCount = 0;
}
MonsterManager::~MonsterManager(){
    
}

MonsterManager *MonsterManager::createWithLevel(int iCurLevel){
    MonsterManager *monsterManager  = new MonsterManager();
    if (monsterManager &&monsterManager->initWithLevel(iCurLevel)) {
        monsterManager->autorelease();
//        monsterManager->retain();
    }else{
        CC_SAFE_DELETE(monsterManager);
        monsterManager = NULL;
    }
    return monsterManager;
}

bool MonsterManager::initWithLevel(int iCurLevel){
    
    if (!Node::init()) {
        return false;
    }
    
    //创建 怪物对象
    createMonster(iCurLevel);
    
    return true;
}

Vector<MonsterG*>MonsterManager::getMonsterList(){
    return m_monsterList;
}

int MonsterManager::getNotShowMonsterCount(){
    return (int)m_notShowMonster.size();
}

MonsterPos *MonsterManager::getMonsterEndPos(){
    return (MonsterPos*)m_monsterPosList.at(m_monsterPosList.size()-1);
}

MonsterPos *MonsterManager::getMonsterStartPos(){
    return (MonsterPos*)m_monsterPosList.at(0);
}

void MonsterManager::createMonster(int iCurLevel){
    //加载怪物坐标对象
    std::string path = StringUtils::format(PATH_MONSTERPOS_PLIST_HEADER,iCurLevel);
    path = DOCUMENT_PATH(path);
    
    auto posList = PosLoadUtil::getIntance()->loadPosWithFile(path.c_str(), enMonsterPos, this, 10, false);
    m_monsterPosList.pushBack(posList);
    
    //读取配置文件
    std::string path1 = StringUtils::format(PATH_MONSTER_PLIST_HEADER,iCurLevel);
    path1 = DOCUMENT_PATH(path1);
    ValueMap fileDataMap = FileUtils::getInstance()->getValueMapFromFile(path1.c_str());
    
    int size = (int)fileDataMap.size();
    for (int i=1; i<=size; i++) {
        Value value = fileDataMap.at(StringUtils::toString(i));
        ValueMap valueMap = value.asValueMap();
        
        int id = valueMap.at("id").asInt();
        float showTime = valueMap.at("showTime").asFloat();
        
        auto monster = MonsterG::createFromCSVFileByID(id);
        monster->setfShowTime(showTime);
        monster->setVisible(false);
        
        //设置精灵
        std::string monsterPic = StringUtils::format(PATH_MONSTER_PIC_HEADER,monster->getmodelID());
        monster->bindSprite(Sprite::create(monsterPic.c_str()));
        
        //保存怪物
        m_monsterList.pushBack(monster);
        
        //保存怪物到未出场 列表
        m_notShowMonster.pushBack(monster);
        
        this ->addChild(monster);
    }
    
    //检查是否有新怪物出场
    this->schedule(schedule_selector(MonsterManager::showMonster));
    
}

void MonsterManager::showMonster(float dt){
    int iNotShowMonsterCount = (int)m_notShowMonster.size();
    if (iNotShowMonsterCount>0) {
        m_fShowTimeCount += dt;
    }
    
    //获取怪物第一个坐标
    auto monsterFirstPos = getMonsterStartPos();
    
    Vector<MonsterG*> wantToDeleteMonster;
    
    for (auto monster : m_notShowMonster) {
        
        //时间到达怪物出厂 让怪物出场
        if (m_fShowTimeCount>=monster->getfShowTime()) {
            //添加怪物到删除列表
            wantToDeleteMonster.pushBack(monster);
           
            monster ->setPosition(monsterFirstPos->getPos());
            monster-> setVisible(true);
            
            //让怪物走指定路线
            monster ->moveByPosList(m_monsterPosList);
        }
    }
    
    for(auto monster : wantToDeleteMonster ){
        m_notShowMonster.eraseObject(monster);
    }
}
