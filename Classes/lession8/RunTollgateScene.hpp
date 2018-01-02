//
//  RunTollgateScene.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/24.
//
//

#ifndef RunTollgateScene_hpp
#define RunTollgateScene_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class RunTollgateScene : public Layer{
public:
    static Scene *createScene();
    CREATE_FUNC(RunTollgateScene);
    virtual bool init();
private:
    void addPlayer(TMXTiledMap*map);

};

#endif /* RunTollgateScene_hpp */
