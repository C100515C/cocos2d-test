//
//  MutouT.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/10/23.
//

#ifndef MutouT_hpp
#define MutouT_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class State;
class MutouT:public Node{
public:
    CREATE_FUNC(MutouT);
    virtual bool init();
    
    
    bool isTired();//判断是否写代码累了
    bool isWantToWriteArticle();//判断是否想写教程
    
    void writeCode();//写代码
    void writeArticle();//写教程
    void reset();//休息
    
    void changeState(State *state);//切换状态
    
    virtual void update(float delate);
private:
    State *currentState;//当前状态类

};
#endif /* MutouT_hpp */
