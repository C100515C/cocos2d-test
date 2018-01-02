//
//  TollgateScene.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/28.
//

#ifndef TollgateSceneG_hpp
#define TollgateSceneG_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

#define TAG_MAP_LAYER 1 //关卡地图图层tag
#define TAG_DATA_LAYER 2 //关卡地图数据层tag

class TollgateSceneG : public Layer{
public:
    CREATE_FUNC(TollgateSceneG);
    virtual bool init();
    static Scene *createScene();
};

#endif /* TollgateScene_hpp */
