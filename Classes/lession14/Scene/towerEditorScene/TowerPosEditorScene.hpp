//
//  TowerPosEditorScene.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/8.
//

#ifndef TowerPosEditorScene_hpp
#define TowerPosEditorScene_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class TowerPosEditorScene : public Layer{
public:
    TowerPosEditorScene();
    ~TowerPosEditorScene();
    
    static Scene *createScene();
    
    CREATE_FUNC(TowerPosEditorScene);
    virtual bool init();
};

#endif /* TowerPosEditorScene_hpp */
