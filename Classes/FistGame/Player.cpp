//
//  Player.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/19.
//
//

#include "Player.hpp"

Player :: Player(){
    m_isJumping = false;
    m_HP = 1000;//初始化血量
}

Player :: ~Player(){
    
}

bool Player::init(){
    if (!Node::init()) {
        return false;
    }
    
    return true;
}

void Player::jump(){
    
    if (getSprite()==NULL) {
        return;
    }
    
    if (m_isJumping) {
        return;
    }
    
    m_isJumping = true;
    
    //原地跳跃  250 高度
    auto jump = JumpBy ::create(2, Point(0,0), 250, 1);
    //跳跃完成 回调
    auto callFuc = [&](){
        m_isJumping = false;
    };
    CallFunc *call = CallFunc ::create(callFuc);
    //创建连续 动作
    auto sque = Sequence ::create(jump,call, NULL);
    
    this -> runAction(sque);
}

void Player::hit(){
    if (getSprite()==NULL) {
        return;
    }
    //🏠飘血 特效
    FlowWord *fw = FlowWord :: create();
    this -> addChild(fw);
    fw -> showWord("-5", getSprite()->getPosition());
    
    m_HP -= 5;
    if (m_HP<0) {
        m_HP = 0;
    }
    
    //创建 受伤动作
    auto moveBack = MoveBy :: create(0.1, Point(-20,0));
    auto forwordMove = MoveBy :: create(0.1, Point(20,0));
    
    auto backRotate = RotateBy :: create(0.1, -5,0);
    auto forwordRotate = RotateBy :: create(0.1, 5, 0);
    
    //俩俩动作 组合
    Spawn *action1 = Spawn :: create(moveBack,backRotate, NULL);
    Spawn *action2 = Spawn :: create(forwordMove,forwordRotate ,NULL);
    
    auto actions = Sequence :: create(action1,action2, NULL);
    
    stopAllActions();
    resetData();
    this -> runAction(actions);
}

int Player:: getHP(){
    return m_HP;
}

void Player::resetData(){
    if (m_isJumping) {
        m_isJumping = false;
    }
    Size size = Director :: getInstance() ->getVisibleSize();

    setPosition(200,size.height/4.0);
    setRotation(0);
    setScale(1);
}
