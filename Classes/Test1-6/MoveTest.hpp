//
//  MoveTest.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/14.
//
//

#ifndef MoveTest_hpp
#define MoveTest_hpp

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;

class MoveTest : public Layer{
public:
    static Scene * createMoveTest();
    bool init();
    CREATE_FUNC(MoveTest);
    
    void popBack();
    void moveEnd();
};


#endif /* MoveTest_hpp */
