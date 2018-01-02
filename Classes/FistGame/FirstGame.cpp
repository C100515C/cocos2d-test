
//
//  FirstGame.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/18.
//
//

#include "FirstGame.hpp"
#include "TollgateScene.hpp"

Scene * FirstGame :: createScene(){
    Scene *scene = Scene :: create();
    FirstGame *layer = FirstGame ::create();
    scene -> addChild(layer);
    
    return scene;
}

bool FirstGame::init(){
    if (!Scene::init()){
        return false;
    }
    
    Label *name = Label::createWithSystemFont("Game cc", "Arial", 25);
    name -> setPosition(50, 50);
    this -> addChild(name);
    
    Size size = Director :: getInstance() -> getVisibleSize();
    MenuItemImage *imageItem = MenuItemImage ::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_0(FirstGame::push, this));
        
    Menu *menu = Menu ::create(imageItem, NULL);
    menu -> setPosition(size.width/2.0, size.height/2.0);
    this -> addChild(menu);
    
    return true;

}

void FirstGame::push(){
    Director :: getInstance() -> pushScene(TollgateScene::createScene());
}
