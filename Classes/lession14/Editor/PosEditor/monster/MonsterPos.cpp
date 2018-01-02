//
//  MonsterPos.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/20.
//

#include "MonsterPos.hpp"


void MonsterPos::draw(Renderer *renderer, const kmMat4 &transform,uint32_t transformUpdated){
    if (m_isDebug) {
        _customCommand.init(_globalZOrder);
        _customCommand.func = CC_CALLBACK_0(MonsterPos::onDraw, this,transform,transformUpdated);
        renderer -> addCommand(&_customCommand);
    }
}

void MonsterPos::onDraw(const kmMat4 &transform, bool transformUpdated){
    kmGLPushMatrix();
    kmGLLoadMatrix(&transform);
    
    glLineWidth(5.0f);//设置线条宽度
    
    //绘制矩形
//    Point srcPos = Point(m_pos.x-RADIUS,m_pos.y+RADIUS);
//    Point destPos = Point(m_pos.x+RADIUS,m_pos.y-RADIUS);
    
    DrawPrimitives::drawCircle(m_pos, Monster_RADIUS, 360, 20, false);//绘制圆形
    
    glLineWidth(1);//恢复线条宽度
    kmGLPopMatrix();
}

bool MonsterPos::isClickMe(Point pos){
    
    Point srcPos = Point(m_pos.x-Monster_RADIUS,m_pos.y+Monster_RADIUS);
    Point destPos = Point(m_pos.x+Monster_RADIUS,m_pos.y-Monster_RADIUS);
    
    if (pos.x>=srcPos.x && pos.x<=destPos.x && pos.y<=srcPos.y && pos.y>=destPos.y) {
        return true;
    }
    return false;
}

MonsterPos::MonsterPos(){
    m_pos = Point(0,0);
    m_isDebug = false;
}

MonsterPos::~MonsterPos(){}

MonsterPos *MonsterPos::create(Point pos){
    MonsterPos *tPos = new MonsterPos();
    
    if(tPos && tPos->init(pos)){
        tPos ->autorelease();
        //        tPos -> retain();
    }else{
        CC_SAFE_DELETE(tPos);
        tPos = NULL;
    }
    
    return tPos;
}

MonsterPos *MonsterPos::create(Point pos, bool isDebug){
    MonsterPos *tPos = new MonsterPos();
    if (tPos && tPos ->init(pos, isDebug)) {
        tPos ->autorelease();
        //        tPos -> retain();
    }else{
        CC_SAFE_DELETE(tPos);
        tPos = NULL;
    }
    return tPos;
}

bool MonsterPos::init(Point pos){
    bool bRet = false;
    do{
        setPos(pos);
        bRet = true;
    }while(0);
    
    
    
    return bRet;
}

bool MonsterPos::init(Point pos, bool isDebug){
    bool bRet = false;
    do{
        CC_BREAK_IF(!init(pos));
        m_isDebug = isDebug;
        bRet = true;
    }while(0);
    
    return bRet;
}

