//
//  TowerPos.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/8.
//

#include "TowerPos.hpp"

//void TowerPos::draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated){
//    if (m_isDebug) {
//        _customCommand.init(_globalZOrder);
//        _customCommand.func = CC_CALLBACK_0(TowerPos::onDraw, this,transform,transformUpdated);
//        renderer -> addCommand(&_customCommand);
//    }
//}
void TowerPos::draw(Renderer *renderer, const kmMat4 &transform,uint32_t transformUpdated){
    if (m_isDebug) {
        _customCommand.init(_globalZOrder);
        _customCommand.func = CC_CALLBACK_0(TowerPos::onDraw, this,transform,transformUpdated);
        renderer -> addCommand(&_customCommand);
    }
}

void TowerPos::onDraw(const kmMat4 &transform, bool transformUpdated){
    kmGLPushMatrix();
    kmGLLoadMatrix(&transform);
    
    glLineWidth(5.0f);//设置线条宽度
    
    //绘制矩形
    Point srcPos = Point(m_pos.x-Tower_RADIUS,m_pos.y+Tower_RADIUS);
    Point destPos = Point(m_pos.x+Tower_RADIUS,m_pos.y-Tower_RADIUS);

    DrawPrimitives::drawRect(srcPos, destPos);//绘制矩形
    
    glLineWidth(1);//恢复线条宽度
    kmGLPopMatrix();
}

bool TowerPos::isClickMe(Point pos){
    
    Point srcPos = Point(m_pos.x-Tower_RADIUS,m_pos.y+Tower_RADIUS);
    Point destPos = Point(m_pos.x+Tower_RADIUS,m_pos.y-Tower_RADIUS);
    
    if (pos.x>=srcPos.x && pos.x<=destPos.x && pos.y<=srcPos.y && pos.y>=destPos.y) {
        return true;
    }
    return false;
}

TowerPos::TowerPos(){
    m_pos = Point(0,0);
    m_isDebug = false;
}

TowerPos::~TowerPos(){}

TowerPos *TowerPos::create(Point pos){
    TowerPos *tPos = new TowerPos();
    
    if(tPos && tPos->init(pos)){
        tPos ->autorelease();
//        tPos -> retain();
    }else{
        CC_SAFE_DELETE(tPos);
        tPos = NULL;
    }
    
    return tPos;
}

TowerPos *TowerPos::create(Point pos, bool isDebug){
    TowerPos *tPos = new TowerPos();
    if (tPos && tPos ->init(pos, isDebug)) {
        tPos ->autorelease();
//        tPos -> retain();
    }else{
        CC_SAFE_DELETE(tPos);
        tPos = NULL;
    }
    return tPos;
}

bool TowerPos::init(Point pos){
    bool bRet = false;
    do{
        setPos(pos);
        bRet = true;
    }while(0);
    
    
    
    return bRet;
}

bool TowerPos::init(Point pos, bool isDebug){
    bool bRet = false;
    do{
        CC_BREAK_IF(!init(pos));
        m_isDebug = isDebug;
        bRet = true;
    }while(0);
    
    return bRet;
}

