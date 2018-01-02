//
//  LessionElevenScene.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/8.
//
//

#ifndef LessionElevenScene_hpp
#define LessionElevenScene_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class LessionElevenScene:public Layer{
public:
    CREATE_FUNC(LessionElevenScene);
    virtual bool init();
   static Scene *createScene();
    

};

#endif /* LessionElevenScene_hpp */
