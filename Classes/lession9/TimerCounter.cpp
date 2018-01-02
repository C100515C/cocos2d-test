//
//  TimerCounter.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/28.
//
//

#include "TimerCounter.hpp"

bool TimerCounter::init(){
    if (!Node::init()) {
        return false;
    }
    m_time = 0;
    m_isCounting = false;
    this -> scheduleUpdate();

    return true;
}

void TimerCounter::startTime(){
    m_time = 0;
    m_isCounting = true;
    this -> scheduleUpdate();
    
}

void TimerCounter::update(float delate){
//    log("%f",delate);
    if (m_isCounting==false) {
        return;
    }
    m_time += delate;

    m_fTime += delate;
    //达到时间 执行
    if (m_fTime>=m_fCBTime) {
        m_func();
        m_isCounting = false;
    }
    
}

float TimerCounter::getCurrentTime(){
    return m_time;
}

void TimerCounter::startTime(float fCBTime, std::function<void ()> func){
    m_fCBTime = fCBTime;
    m_func = func;
    m_fTime = 0;
    m_isCounting = true;
    

}
