//
//  ThreeDirectionMoveController.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/25.
//
//

#ifndef ThreeDirectionMoveController_hpp
#define ThreeDirectionMoveController_hpp

#include <stdio.h>
#include "RunController.hpp"

class ThreeDirectionMoveController : public RunController{
public:
    CREATE_FUNC(ThreeDirectionMoveController);
    virtual bool init();
    virtual void update(float delet);
    
    //设置 速度
    void setXSpeed(int xSpeed);
    void setYSpeed(int ySpeed);
    
private:
    int m_XSpeed;
    int m_YSpeed;
    
    //注册屏幕 触摸事件
    void registerTouchEvent();
};

#endif /* ThreeDirectionMoveController_hpp */
