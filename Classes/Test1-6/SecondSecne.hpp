//
//  SecondSecne.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/10.
//
//

#ifndef SecondSecne_hpp
#define SecondSecne_hpp

#include <stdio.h>
#include "cocos2d.h"
/*
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;*/

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
using namespace cocostudio::timeline;
using namespace cocos2d::ui;
//using namespace cocostudio;

USING_NS_CC;

using namespace cocos2d;

class SecondSecne : public Layer{
public:
    static Scene * createScene();
    virtual bool init();
    CREATE_FUNC(SecondSecne);
    void popScene ();
    void menuClicked();
    void hideTitle(Ref*r,Widget::TouchEventType tp);
    void changeLoadingBar(Ref*r,Widget::TouchEventType tp);
    
    ImageView *img;
    LoadingBar *hpBar;
};

#endif /* SecondSecne_hpp */
