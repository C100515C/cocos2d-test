//
//  FirstGame.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/18.
//
//

#ifndef FirstGame_hpp
#define FirstGame_hpp

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;

class FirstGame : public Scene{
public:
    static Scene * createScene();
    bool init();
    CREATE_FUNC(FirstGame);
    
private:
    void push();
};


#endif /* FirstGame_hpp */
