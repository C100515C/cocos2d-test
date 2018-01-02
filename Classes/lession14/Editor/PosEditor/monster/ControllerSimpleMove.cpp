//
//  ControllerSimpleMove.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2018/1/2.
//

#include "ControllerSimpleMove.hpp"

ControllerSimpleMove::ControllerSimpleMove(){
    m_moveSpanTime = 0;
    m_moveTimeCount = 0;
}
ControllerSimpleMove::~ControllerSimpleMove(){
    CC_SAFE_RELEASE(m_curDestPos);
}

ControllerSimpleMove * ControllerSimpleMove::create(EntityG *entity){
    ControllerSimpleMove *move = new ControllerSimpleMove();
    if (move && move->init(entity)) {
        move->retain();
        move->autorelease();
    }else{
        CC_SAFE_DELETE(move);
        move = NULL;
    }
    return move;
}

bool ControllerSimpleMove::init(EntityG *entity){
    if (!Node::init()) {
        return false;
    }
    this->m_entity = entity;
    
    this->schedule(schedule_selector(ControllerSimpleMove::checkMoveUpdate));
    
    return true;
    
}

void ControllerSimpleMove::checkMoveUpdate(float dt){
    if (m_isMoving) {
        m_moveTimeCount += dt*1000;
        if (m_moveTimeCount>=m_moveSpanTime) {
            m_moveTimeCount = 0;
            moveOneStep();
        }
    }
}

void ControllerSimpleMove::moveOneStep(){
    Sprite *sprite = m_entity->getSprite();
    if (sprite!=NULL) {
        Point entityPos = m_entity->getPosition();
        Point curDestPos = m_curDestPos->getPos();
        
        //获取下一个移动坐标
        entityPos = getNextPos(entityPos, curDestPos);
        
        //移动实体
        m_entity ->setPosition(entityPos);
        
        //达到当前位置 后开始下一个目的
        if (entityPos.x==curDestPos.x&&entityPos.y==curDestPos.y) {
            if (m_movePosList.size()>0) {
                nextMovePos();
            }
        }
    }
}

void ControllerSimpleMove::nextMovePos(){
    if (m_movePosList.size()<1) {
        return;
    }
    m_curDestPos = m_movePosList.at(0);
    m_movePosList.erase(0);
}

void ControllerSimpleMove::moveByPosList(Vector<PosBase *> posList){
    if (posList.size()<1) {
        return;
    }
    this->m_movePosList.clear();
    this->m_movePosList.pushBack(posList);
    
    nextMovePos();
    this->m_isMoving=true;
    
}

void ControllerSimpleMove::moveByPosList(Vector<PosBase *> posList, int iSpeed){
    this->m_iSpeed = iSpeed;
    moveByPosList(posList);
}

void ControllerSimpleMove::moveByPosList(Vector<PosBase *> posList, int iSpeed, int iSpanTime){
    this->m_moveSpanTime = iSpanTime;
    moveByPosList(posList,iSpeed);
}

void ControllerSimpleMove::moveByPos(PosBase *pos){
    if (m_isMoving==false &&pos!=NULL) {
        Vector<PosBase*>posList;
        posList.pushBack(pos);
        moveByPosList(posList);
    }
}

