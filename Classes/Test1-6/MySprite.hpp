//
//  MySprite.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/11.
//
//

#ifndef MySprite_hpp
#define MySprite_hpp

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;

class MySprite : public Sprite{
    
public:
    static MySprite * createSprite();
    virtual bool init();
    CREATE_FUNC(MySprite);
};

#endif /* MySprite_hpp */
