//
//  SceneManager.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/27.
//

#include "SceneManager.hpp"
#include "TowerPosEditorScene.hpp"
#include "TollgateSceneG.hpp"

SceneManager *SceneManager::m_shareManager = NULL;
SceneManager * SceneManager::getInstance(){
    if(m_shareManager==NULL){
        
        m_shareManager = new SceneManager();
        
        if(m_shareManager&& m_shareManager->init()){
            m_shareManager -> autorelease();
            m_shareManager -> retain();
        }else{
            CC_SAFE_DELETE(m_shareManager);
            m_shareManager = NULL;
        }
    }
    
    return m_shareManager;
}

bool SceneManager::init(){
    
    
    return true;
}

void SceneManager::changeScene(EnumSceneType sceneType){
    Scene *pScene = NULL;
    
    switch (sceneType) {
        case en_TollgateScene:
        {
            pScene = TollgateSceneG::createScene();
        }
            break;
        case en_TollgateEditorScene:
        {
            pScene = TowerPosEditorScene::createScene();

        }
            break;
        case en_WinScene:
        {
            
        }
            break;
        case en_GameOverScene:
        {
            
        }
            break;
        default:
            break;
    }
    
    if (pScene ==NULL) {
        return;
    }
    
    Director *director = Director::getInstance();
    Scene *currentScene = director->getRunningScene();
    if(currentScene==NULL){
        director -> runWithScene(pScene);
    }else{
        director -> replaceScene(pScene);
    }
    
}
