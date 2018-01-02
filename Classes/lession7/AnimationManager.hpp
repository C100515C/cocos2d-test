//
//  AnimationManager.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/23.
//
//

#ifndef AnimationManager_hpp
#define AnimationManager_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class AnimationManager {
public:
    //根据文件名前缀创建动画
    static Animation* createAnimateWithFrameName(const char *name,float delay,int iLoops);
    
    //根据文件名前缀创建动画，设置动画图片数量
    static Animation* createAnimateWithFrameNameAndNum(const char *name,int num,float delay,int iLoops);

};

#endif /* AnimationManager_hpp */
