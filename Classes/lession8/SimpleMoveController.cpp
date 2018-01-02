
//
//  SimpleMoveController.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/24.
//
//

#include "SimpleMoveController.hpp"

bool SimpleMoveController::init(){
    if (!RunController::init()) {
        return false;
    }
    
    this ->m_speed = 0;
    
    this -> scheduleUpdate();
    
    return true;
}

void SimpleMoveController::update(float delet){

    if (m_controllerListener==NULL) {
        return;
    }
    
    Point pos = m_controllerListener->getTagPoint();
    
    pos.x += m_speed;
    
    m_controllerListener ->setTagPoint(pos.x, pos.y);
}

void SimpleMoveController::setSpeed(float speed){
    this ->m_speed = speed;
}
