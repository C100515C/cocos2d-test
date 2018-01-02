//
//  State.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/9.
//
//

#ifndef State_hpp
#define State_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class MutouT;
class State{
public:
    virtual void execute(MutouT *mutou)=0;//某种状态下执行某个操作
};

#endif /* State_hpp */
