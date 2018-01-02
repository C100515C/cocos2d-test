//
//  RunEntity.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/24.
//
//

#ifndef RunEntity_hpp
#define RunEntity_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ControllerListener.hpp"
#include "RunController.hpp"
USING_NS_CC;

class RunEntity : public Node,public ControllerListener{
public:
    void bindSprite(Sprite*sprite);
    Sprite *getSprite();
    
    //设置控制器
    void setController(RunController *controller);
    //实现ControllerListener 接口方法
    virtual void setTagPoint(float x,float y);
    virtual Point getTagPoint();
    
private:
    Sprite *m_sprite;
    RunController *m_runController;
};

#endif /* RunEntity_hpp */
