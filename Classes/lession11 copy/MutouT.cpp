//
//  MutouT.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/10/23.
//

#include "MutouT.hpp"
#include "State.hpp"
//#include "StateWriteActicle.hpp"
//#include "StateReset.hpp"
//#include "SateWriteCode.hpp"

bool MutouT::init(){
    if (!Node::init()) {
        return false;
    }
    //默认休息
    currentState = NULL;
    
    this->scheduleUpdate();
    
    return true;
}

bool MutouT::isTired(){
    //每次问都说累
    return true;
}

bool MutouT::isWantToWriteArticle(){
    //有百分之十 几率想写 教程
    float p = CCRANDOM_0_1();
    if (p<0.1f) {
        return true;
    }
    return false;
}

void MutouT::writeCode(){
    log("write code...");
}

void MutouT::writeArticle(){
    log("write article");
}

void MutouT::reset(){
    log("reset ");
}

void MutouT::changeState(State *state){
    CC_SAFE_DELETE(currentState);
    currentState = state;
}

void MutouT::update(float delate){
    currentState ->execute(this);
}
