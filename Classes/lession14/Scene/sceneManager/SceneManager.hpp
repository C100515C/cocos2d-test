//
//  SceneManager.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/27.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class SceneManager : public Ref{
public:
    //场景枚举
    typedef enum {
        en_TollgateScene,//关卡场景
        en_TollgateEditorScene,//关卡编辑
        en_WinScene,//胜利
        en_GameOverScene//结束
        
    }EnumSceneType;
    
    static SceneManager* getInstance();
    virtual bool init();
    void changeScene(EnumSceneType sceneType);
    
private:
    static SceneManager *m_shareManager;
    
};

#endif /* SceneManager_hpp */
