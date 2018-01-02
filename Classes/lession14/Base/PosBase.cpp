//
//  PosBase.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/8.
//

#include "PosBase.hpp"

PosBase::PosBase(){
    m_pos = Point(0,0);
    m_isDebug = false;
}

PosBase::~PosBase(){}

PosBase *PosBase::create(Point pos){
    PosBase *tPos = new PosBase();
    
    if(tPos && tPos->init(pos)){
        tPos ->autorelease();
//        tPos -> retain();
    }else{
        CC_SAFE_DELETE(tPos);
        tPos = NULL;
    }
    
    return tPos;
}

PosBase *PosBase::create(Point pos, bool isDebug){
    PosBase *tPos = new PosBase();
    if (tPos && tPos ->init(pos, isDebug)) {
        tPos ->autorelease();
//        tPos -> retain();
    }else{
        CC_SAFE_DELETE(tPos);
        tPos = NULL;
    }
    return tPos;
}

bool PosBase::init(Point pos){
    bool bRet = false;
    do{
        setPos(pos);
        bRet = true;
    }while(0);
    
    return bRet;
}

bool PosBase::init(Point pos, bool isDebug){
    bool bRet = false;
    do{
        CC_BREAK_IF(!init(pos));
        m_isDebug = isDebug;
        bRet = true;
    }while(0);
    
    return bRet;
}

bool PosBase::isClickMe(Point pos){
    return false;
}

void PosBase::setDebug(bool isDebug){
    this ->m_isDebug = isDebug;
}


