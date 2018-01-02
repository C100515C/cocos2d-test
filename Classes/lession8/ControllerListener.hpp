//
//  ControllerListener.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/24.
//
//

#ifndef ControllerListener_hpp
#define ControllerListener_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class ControllerListener {
public:
    virtual void setTagPoint(float x,float y)=0;
    virtual Point getTagPoint()=0;
    
};

#endif /* ControllerListener_hpp */
