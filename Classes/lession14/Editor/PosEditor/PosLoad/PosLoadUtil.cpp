//
//  PosLoadUtil.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/16.
//

#include "PosLoadUtil.hpp"
#include "TowerPos.hpp"
#include "MonsterPos.hpp"

PosLoadUtil *PosLoadUtil::m_posLoadUtil = NULL;
PosLoadUtil *PosLoadUtil::getIntance(){
    if(m_posLoadUtil==NULL){
        m_posLoadUtil = new PosLoadUtil();
        if(m_posLoadUtil&&m_posLoadUtil->init()){
            m_posLoadUtil -> autorelease();

        }else{
            CC_SAFE_DELETE_ARRAY(m_posLoadUtil);
            m_posLoadUtil = NULL;
        }
    }
    
    return m_posLoadUtil;
}

bool PosLoadUtil::init(){
    
    if (!Node::init()) {
        return false;
    }
    
    return true;
}

Vector<PosBase*> PosLoadUtil::loadPosWithFile(const char *sFilePath,
                                              PosType enPosType,
                                              Node *container,
                                              int level,
                                              bool isDebug){
    
    Vector<PosBase*> posList;
    
    ValueMap fileDataMap = FileUtils::getInstance()->getValueMapFromFile(sFilePath);
    
    size_t size = fileDataMap.size();
    
    for(int i=1; i<=size; i++){
        Value value = fileDataMap.at(StringUtils::toString(i));
        ValueMap map = value.asValueMap();
        
        //创建 posbase对象
        PosBase *base;
        switch (enPosType) {
            case enTowerPos:
                base = TowerPos::create(Point(map["x"].asInt(),map["y"].asInt()), isDebug);
                break;
            case enMonsterPos:
                base = MonsterPos::create(Point(map["x"].asInt(),map["y"].asInt()), isDebug);
                break;
            default:
                break;
        }
        posList.pushBack(base);
        
        if(container!=NULL){
            container -> addChild(base,level);
        }
    }
    
    return posList;
}
