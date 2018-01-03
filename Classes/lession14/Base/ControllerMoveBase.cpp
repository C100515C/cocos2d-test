//
//  ControllerMoveBase.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2018/1/2.
//

#include "ControllerMoveBase.hpp"

ControllerMoveBase ::ControllerMoveBase(){
    m_entity = NULL;
    m_isYUp = false;
    m_isXLeft = false;
    m_isMoving = false;
    m_iSpeed = SPEED;
    m_iCheckMoveSpeed = CHECK_MOVE_SPEED_LEVEL1;
    
}
ControllerMoveBase::~ControllerMoveBase(){
    
}

Point ControllerMoveBase::getNextPos(Point curPos, Point destPos){
    
    //判断移动方向
    if (curPos.x >destPos.x) {
        m_isXLeft = true;
    }else{
        m_isXLeft = false;
    }
    
    if (curPos.y>destPos.y){
        m_isYUp = false;
    }else{
        m_isYUp = true;
    }
    
    //根据方向 和速度 改变 当前坐标值
    if (m_isXLeft==false &&curPos.x<destPos.x) {
        curPos.x += m_iSpeed;
        if (curPos.x>destPos.x) {
            curPos.x = destPos.x;
        }
        
    }else if (m_isXLeft==true &&curPos.x>destPos.x){
        curPos.x -= m_iSpeed;
        if (curPos.x<destPos.x) {
            curPos.x = destPos.x;
        }
        
    }else if (m_isYUp==true &&curPos.y<destPos.y){
        curPos.y += m_iSpeed;
        if (curPos.y>destPos.y) {
            curPos.y = destPos.y;
        }
        
    }else if(m_isYUp==false && curPos.y>destPos.y){
        curPos.y -= m_iSpeed;
        if (curPos.y<destPos.y) {
            curPos.y = destPos.y;
        }
        
    }
    
    return curPos;
    
}

