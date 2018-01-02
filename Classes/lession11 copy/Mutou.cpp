//
//  Mutou.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/9.
//
//

#include "Mutou.hpp"

bool Mutou::init(){
    if (!Node::init()) {
        return false;
    }
    //默认休息
    currentState = enStateReset;
    
    this->scheduleUpdate();
    
    return true;
}

bool Mutou::isTired(){
    //每次问都说累
    return true;
}

bool Mutou::isWantToWriteArticle(){
    //有百分之十 几率想写 教程
    float p = CCRANDOM_0_1();
    if (p<0.1f) {
        return true;
    }
    return false;
}

void Mutou::writeCode(){
    log("write code...");
}

void Mutou::writeArticle(){
    log("write article");
}

void Mutou::reset(){
    log("reset ");
}

void Mutou::changeState(MutouState state){
   this->currentState = state;
}

void Mutou::update(float delate){
    switch (this->currentState) {
        case enStateWriteCode:
        {
            //如果累了就休息
            if (this->isTired()) {
                this->reset();
                this->changeState(enStateReset);
            }
        }
            break;
        case enStateReset:
        {
            //看看想写啥
            if (this->isWantToWriteArticle()) {
                this->writeArticle();
                this->changeState(enStateWriteArticle);
            }else{
                this->writeCode();
                this->changeState(enStateWriteCode);
            }
            
        }
            break;
        case enStateWriteArticle:
        {
            //如果累了就休息
            if (this->isTired()) {
                this->reset();
                this->changeState(enStateReset);
            }
        }
            break;
            
        default:
            break;
    }
}
