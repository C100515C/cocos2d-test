//
//  TowerPosEditorScene.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/8.
//

#include "TowerPosEditorScene.hpp"
#include "TowerPos.hpp"
#include "TowerPosEditorLayer.hpp"
#include "TowerPosEditorOperateLayer.hpp"

#include "I18N.hpp"

TowerPosEditorScene::~TowerPosEditorScene(){}
TowerPosEditorScene::TowerPosEditorScene(){}

Scene *TowerPosEditorScene::createScene(){
    Scene *scene = Scene::create();

    TowerPosEditorLayer *layer = TowerPosEditorLayer::create();
    scene -> addChild(layer,1);
    
    TowerPosEditorOperateLayer *operate = TowerPosEditorOperateLayer::create(layer);
    scene -> addChild(operate,2);
 
    log("%s",I18N::getInstance()->getcStringByKey(en_strKey_public_confirm));
    
    return scene;
}

bool TowerPosEditorScene::init(){
    if(!Layer::init()){
        return  false;
    }
    
    return true;
}


