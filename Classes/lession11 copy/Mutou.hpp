//
//  Mutou.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/9.
//
//

#ifndef Mutou_hpp
#define Mutou_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

typedef enum{
    enStateWriteCode,
    enStateWriteArticle,
    enStateReset,
}MutouState;

class Mutou:public Node{
public:
    CREATE_FUNC(Mutou);
    virtual bool init();
    
    MutouState currentState;//当前状态
    
    bool isTired();//判断是否写代码累了
    bool isWantToWriteArticle();//判断是否想写教程
    
    void writeCode();//写代码
    void writeArticle();//写教程
    void reset();//休息
    
    void changeState(MutouState state);//切换状态
    
    virtual void update(float delate);
};

#endif /* Mutou_hpp */
