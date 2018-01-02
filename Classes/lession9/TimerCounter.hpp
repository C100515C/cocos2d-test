//
//  TimerCounter.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/28.
//
//

#ifndef TimerCounter_hpp
#define TimerCounter_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class TimerCounter : public Node{
public:
    CREATE_FUNC(TimerCounter);
    virtual bool init();
    virtual void update(float delate);
    
    void startTime();
    float getCurrentTime();
    
    //开始自己是 设置 回调时间和回调执行函数
    void startTime(float fCBTime, std::function<void()> func);
    
private:
    float m_time;
    
    float m_fCBTime;//用于计时
    float m_fTime;//回调时间
    float m_isCounting;//标记是否在计时
    std::function<void()> m_func;//回调函数

};

#endif /* TimerCounter_hpp */
