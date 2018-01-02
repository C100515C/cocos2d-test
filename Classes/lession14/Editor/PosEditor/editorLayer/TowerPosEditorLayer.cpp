//
//  TowerPosEditorLayer.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/8.
//

#include "TowerPosEditorLayer.hpp"
#include "TowerPos.hpp"
#include "MonsterPos.hpp"
#include "PosLoadUtil.hpp"

TowerPosEditorLayer::TowerPosEditorLayer(){
    m_iCurLevel = 1;
    m_enMode = enTowerPos;
}

TowerPosEditorLayer::~TowerPosEditorLayer(){}

bool TowerPosEditorLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    
    //监听触摸事件
    auto listener = EventListenerTouchOneByOne::create();
    listener -> onTouchBegan = [](Touch *touch,Event *event){
        return true;
    };
    
    listener -> onTouchEnded = [&](Touch *touch,Event *event){
        Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());
        //判断是什么坐标
        switch (m_enMode) {
            case enTowerPos:
                editTowrPos(pos);

                break;
            case enMonsterPos:
                editMonsterPos(pos);
                
                break;
            default:
                break;
        }
    };
    
    _eventDispatcher ->addEventListenerWithSceneGraphPriority(listener, this);
    
    loadConfigFile();
    
    return true;
}

void TowerPosEditorLayer::editTowrPos(Point pos){
    
    PosBase *existPos = findExistTowerPos(pos);
    if (existPos!=NULL) {
        deleteTowerPos(existPos);
    }else{
        createTowerPos(pos);
    }
}

void TowerPosEditorLayer::editMonsterPos(Point pos){
    PosBase *existPos = findExistMonsterPos(pos);
    
    if (existPos!=NULL) {
        deleteMonsterPos(existPos);
    }else{
        createMonsterPos(pos);
    }

}

PosBase *TowerPosEditorLayer::findExistTowerPos(Point pos){
    
    for(PosBase *exist:m_towerPosList){
        if (exist->isClickMe(pos)) {
            return exist;
        }
    }
    
    return NULL;
}

PosBase *TowerPosEditorLayer::findExistMonsterPos(Point pos){
    
    for(PosBase *exist:m_monsterPosList){
        if (exist->isClickMe(pos)) {
            return exist;
        }
    }
    
    return NULL;
}


void TowerPosEditorLayer::createTowerPos(Point pos){
    PosBase *basePos = TowerPos::create(pos,true);
    this -> addChild(basePos,10);
    m_towerPosList.pushBack(basePos);
}

void TowerPosEditorLayer::createMonsterPos(Point pos){
    PosBase *basePos = MonsterPos::create(pos,true);
    this -> addChild(basePos,10);
    m_monsterPosList.pushBack(basePos);
}

void TowerPosEditorLayer::deleteTowerPos(PosBase *existPos){
    this ->removeChild(existPos);
    m_towerPosList.eraseObject(existPos);
}

void TowerPosEditorLayer::deleteMonsterPos(PosBase *existPos){
    this ->removeChild(existPos);
    m_monsterPosList.eraseObject(existPos);
}

void TowerPosEditorLayer::deleleAllTowerPos(){
    this ->removeAllChildrenWithCleanup(true);
    m_towerPosList.clear();
    m_monsterPosList.clear();
}

void TowerPosEditorLayer::outPutPosToPlistFile(){
    ValueMap fileDataMap;
    std::string sFilePath;
    int index = 1;
    
    //各个属性
    //添加 炮台文件
    for(auto posBase:m_towerPosList){
        ValueMap data;
        data["x"] = posBase->getPos().x;
        data["y"] = posBase->getPos().y;
        
        fileDataMap[StringUtils::toString(index)] = Value(data);
        index ++;
    }
    
    //文件名字
    __String *name = __String::createWithFormat("towerPos_level_%d.plist",m_iCurLevel);
    //进入Documents目录下
    std::string pathToSave=FileUtils::getInstance()->getWritablePath();
    //添加到finder文件夹
    sFilePath = pathToSave+name->getCString();
    FileUtils::getInstance()->isFileExist(sFilePath);
    FileUtils::getInstance()->writeToFile(fileDataMap, sFilePath);
    
    //添加 怪兽文件
    index = 1;
    fileDataMap.clear();
    for(auto posBase:m_monsterPosList){
        ValueMap data;
        data["x"] = posBase->getPos().x;
        data["y"] = posBase->getPos().y;
        
        fileDataMap[StringUtils::toString(index)] = Value(data);
        index ++;
    }
    //文件名字
    name = __String::createWithFormat("monsterPos_level_%d.plist",m_iCurLevel);
    //进入Documents目录下
    pathToSave=FileUtils::getInstance()->getWritablePath();
    //添加到finder文件夹
    sFilePath = pathToSave+name->getCString();
    FileUtils::getInstance()->isFileExist(sFilePath);
    FileUtils::getInstance()->writeToFile(fileDataMap, sFilePath);
}

void TowerPosEditorLayer::loadConfigFile(){
    //获取屏幕尺寸
    Size size = Director::getInstance()->getVisibleSize();
    
    //添加背景地图
    std::string bgName = StringUtils::format("level_%d.jpg",m_iCurLevel);
    Sprite *bgSprite = Sprite::create(bgName.c_str());
    if (bgSprite==NULL) {
        return;
    }
    bgSprite -> setPosition(size.width/2.0, size.height/2.0);
    this -> addChild(bgSprite,1);
    
    //加载塔坐标对象
    std::string sFilePath;
    //文件名字
    __String *name = __String::createWithFormat("towerPos_level_%d.plist",m_iCurLevel);
    //进入Documents目录下
    std::string pathToSave=FileUtils::getInstance()->getWritablePath();
    //添加到finder文件夹
    sFilePath = pathToSave+name->getCString();
    Vector<PosBase*> posList = PosLoadUtil::getIntance()->loadPosWithFile(sFilePath.c_str(), enTowerPos,this, 3, true);
    m_towerPosList.pushBack(posList);
    
    //加载怪兽坐标对象
    name = __String::createWithFormat("monsterPos_level_%d.plist",m_iCurLevel);
    //进入Documents目录下
    pathToSave=FileUtils::getInstance()->getWritablePath();
    //添加到finder文件夹
    sFilePath = pathToSave+name->getCString();
    Vector<PosBase*> posList1 = PosLoadUtil::getIntance()->loadPosWithFile(sFilePath.c_str(),enMonsterPos ,this, 3, true);
    m_monsterPosList.pushBack(posList1);
    
}

void TowerPosEditorLayer::changeMode(){
    this ->m_enMode = (this->m_enMode==enTowerPos)?enMonsterPos:enTowerPos;
}

void TowerPosEditorLayer::nextLevel(){
    deleleAllTowerPos();
    m_iCurLevel ++;
    
    loadConfigFile();
}

void TowerPosEditorLayer::previousLevel(){
    if(m_iCurLevel==1)return;
    deleleAllTowerPos();
    m_iCurLevel --;
    loadConfigFile();
}

Vector<PosBase*> TowerPosEditorLayer::getMonstersPos(){
    return this -> m_monsterPosList;
}
