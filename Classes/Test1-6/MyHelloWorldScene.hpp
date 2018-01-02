//
//  MyHelloWorldScene.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/9.
//
//

#ifndef MyHelloWorldScene_hpp
#define MyHelloWorldScene_hpp

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;

class MyHelloWorldScene : public Layer{
  
public:
    
    /**
     通过静态的scene函数，创建一个场景对象

     @return scene
     */
    static Scene *createScene();
    /*
     MyHelloWorldScene 的初始化工作都在init中进行
     */
    virtual bool init();
    
    /* 
     通过宏CREATE_FUNC定义create函数
     */
    CREATE_FUNC(MyHelloWorldScene);
};

#endif /* MyHelloWorldScene_hpp */
