//
//  TollgateScene.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/19.
//
//

#ifndef TollgateScene_hpp
#define TollgateScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
using namespace cocostudio::timeline;
using namespace cocos2d::ui;

#include "extensions/cocos-ext.h"

USING_NS_CC_EXT;
USING_NS_CC;

class Player;
class TollgateScene : public Layer{

public:
    static Scene *createScene();
    virtual bool init();
    CREATE_FUNC(TollgateScene);
    virtual void update(float delta);
private:
    void initBG();//初始化 关卡
    void loadUI();
    void jumpEvent(Ref *ref, Widget::TouchEventType type);
private:
    Sprite *m_bgSprite1;//背景 1
    Sprite *m_bgSprite2;//背景2
    Sprite *m_bgSprite3;//背景3
    
    Player *m_player;//主角
    
    int m_score;
    Text *m_scoreLab;
    LoadingBar *m_hpPropress;
};

#endif /* TollgateScene_hpp */
