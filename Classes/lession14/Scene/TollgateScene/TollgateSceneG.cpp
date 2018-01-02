//
//  TollgateScene.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/28.
//

#include "TollgateSceneG.hpp"
#include "TollgateMapLayer.hpp"

Scene *TollgateSceneG::createScene(){
    Scene *scene = Scene::create();
    
    TollgateSceneG *tgLayer = TollgateSceneG::create();
    
    TollgateMapLayer *mapLayer = TollgateMapLayer::create();
    scene ->addChild(mapLayer,1,TAG_MAP_LAYER);
    scene ->addChild(tgLayer,3);
    
    return scene;
}

bool TollgateSceneG::init(){
    if (!Layer::init()) {
        return false;
    }
    
    return true;
}
