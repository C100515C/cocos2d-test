//
//  LessionElevenScene.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/8.
//
//

#include "LessionElevenScene.hpp"
#include "MutouT.hpp"
#include "StateReset.hpp"

Scene *LessionElevenScene::createScene(){
    Scene *scene = Scene::create();
    LessionElevenScene *layer = LessionElevenScene::create();
    scene->addChild(layer);
    return scene;
}

bool LessionElevenScene::init(){
    if (!Layer::init()) {
        return false;
    }
    
    MutouT *mutou = MutouT::create();
    mutou ->changeState(new StateReset());
    this->addChild(mutou);
    
    return true;
}
