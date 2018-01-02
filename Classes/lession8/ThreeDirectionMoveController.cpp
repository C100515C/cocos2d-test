//
//  ThreeDirectionMoveController.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/25.
//
//

#include "ThreeDirectionMoveController.hpp"

bool ThreeDirectionMoveController::init(){
    if (!RunController::init()) {
        return false;
    }
    m_YSpeed = 0;
    m_XSpeed = 0;
    
    registerTouchEvent();
    
    this -> scheduleUpdate();
    
    return true;
}

void ThreeDirectionMoveController::update(float delet){
    if (m_controllerListener==NULL) {
        return;
    }
    
    //让移动对象 在 x y 方向移动
    Point currentPoint = m_controllerListener->getTagPoint();
    currentPoint.x += m_XSpeed;
    currentPoint.y += m_YSpeed;
    
    m_controllerListener ->setTagPoint(currentPoint.x, currentPoint.y);
    
}

void ThreeDirectionMoveController::setXSpeed(int xSpeed){
    this ->m_XSpeed = xSpeed;
}

void ThreeDirectionMoveController::setYSpeed(int ySpeed){
    this ->m_YSpeed = ySpeed;
}

void ThreeDirectionMoveController::registerTouchEvent(){

    auto listener = EventListenerTouchOneByOne :: create();
    
    listener ->onTouchBegan = [](Touch *touch,Event *event){
        return true;
    };
    
    listener ->onTouchMoved =[&](Touch *touch,Event *event){
        //获取点击 坐标
        Point touchPoint = Director::getInstance()->convertToGL(touch->getLocationInView());
        //被控制对象坐标
        Point playerPoint = m_controllerListener->getTagPoint();
        
        //判断是上移动  还是下 移动
        int isSpeed=0;
        if (touchPoint.y>playerPoint.y) {
            isSpeed = 1;
        }else{
            isSpeed = -1;
        }
        
        setYSpeed(isSpeed);
    };
    
    listener -> onTouchEnded = [&](Touch *touch,Event *event){
        setYSpeed(0);
    };
    
    auto listenerManager = Director ::getInstance() ->getEventDispatcher();
    listenerManager ->addEventListenerWithSceneGraphPriority(listener, this);
    
    
}




