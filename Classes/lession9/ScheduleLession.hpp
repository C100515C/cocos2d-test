//
//  ScheduleLession.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/27.
//
//

#ifndef ScheduleLession_hpp
#define ScheduleLession_hpp

#include <stdio.h>
#include "TimerCounter.hpp"
#include "cocos2d.h"
USING_NS_CC;

class ScheduleLession: public Layer{
public:
    CREATE_FUNC(ScheduleLession);
    virtual bool init();
    static Scene *createScene();
    virtual void update(float delate);
    
    void myUpdate(float delate);
    
    void myCallBack(float delay);
    
    void countTime(float dt);
    
    void logic(float dt);
    void doSomething(float dt);
    
    //观察者模式
    //发布消息
    void sendMsg(float dt);
        
private:
    float m_fTotalTime;//update函数执行间隔累加时间
    float m_fCountTime;//利用update 函数进行计时，累计的时间
    TimerCounter *m_timerCounter;
};

#endif /* ScheduleLession_hpp */
