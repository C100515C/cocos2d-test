//
//  ControllerSimpleMove.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2018/1/2.
//

#ifndef ControllerSimpleMove_hpp
#define ControllerSimpleMove_hpp

#include <stdio.h>
#include "ControllerMoveBase.hpp"
#include "PosBase.hpp"

class ControllerSimpleMove : public ControllerMoveBase{
public:
    ControllerSimpleMove();
    ~ControllerSimpleMove();
    
    static ControllerSimpleMove *create(EntityG *entity);
    bool init(EntityG *entity);
    
    void checkMoveUpdate(float dt);
    
    //按照给定的坐标移动
    void moveByPosList(Vector<PosBase*> posList);
    void moveByPosList(Vector<PosBase*> posList,int iSpeed);
    void moveByPosList(Vector<PosBase*> posList,int iSpeed,int iSpanTime);
    
    void moveByPos(PosBase *pos);

private:
    void moveOneStep();
    void nextMovePos();
private:
    Vector<PosBase *> m_movePosList;
    PosBase *m_curDestPos;
    int m_moveSpanTime;//间隔时间
    int m_moveTimeCount;//移动计时
};

#endif /* ControllerSimpleMove_hpp */
