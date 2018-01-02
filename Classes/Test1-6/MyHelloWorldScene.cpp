//
//  MyHelloWorldScene.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/9.
//
//

#include "MyHelloWorldScene.hpp"

Scene *MyHelloWorldScene ::createScene(){
    /*创建一个场景对象*/
    auto scene = Scene::create();
    
    /*
     创建一个MyHelloWorldScene 对象
     */
    auto layer = MyHelloWorldScene::create();
    
    /*
     将MyHelloWorldScene对象添加到场景中
     */
    scene ->addChild(layer);
    
    return scene;
}

bool MyHelloWorldScene::init(){
    /*
     创建一个精灵 并添加到场景中
     */
    auto sprite = Sprite::create("HelloWorld.png");
    sprite ->setPosition(250, 150);
    this -> addChild(sprite);
    
    return true;
    
}
