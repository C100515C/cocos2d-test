//
//  MyScene_7.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/22.
//
//

#ifndef MyScene_7_hpp
#define MyScene_7_hpp

#include <stdio.h>

#include "cocos2d.h"
USING_NS_CC;

class MyScene_7 : public Layer{
public :
    CREATE_FUNC(MyScene_7);
    static Scene *createScene();
    virtual bool init();
private:
    Animate *createAnimation();
    Animate *createAnimation1();

    
};

#endif /* MyScene_7_hpp */
