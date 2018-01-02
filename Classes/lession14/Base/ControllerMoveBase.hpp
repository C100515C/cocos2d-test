//
//  ControllerMoveBase.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2018/1/2.
//

#ifndef ControllerMoveBase_hpp
#define ControllerMoveBase_hpp

#include <stdio.h>
#include "ControllerBase.hpp"
#include "CommDefine.h"
#include "EntityG.hpp"

class ControllerMoveBase:public ControllerBase{
public:
    ControllerMoveBase();
    ~ControllerMoveBase();
    
    CC_SYNTHESIZE(int, m_iSpeed, iSpeed);
    
protected:
    EntityG *m_entity;//实体对象
    bool m_isMoving;//是否在移动
    bool m_isXLeft;//是否是x方向向左移动
    bool m_isYUp;//是否是y方向向上移动
    int m_iCheckMoveSpeed;//检查间隔时间 越短越快
    
    /**
     给定当前坐标和目标坐标计算下一个目标坐标

     @param curPos curPos description
     @param destPos destPos description
     @return return value description
     */
    Point getNextPos(Point curPos,Point destPos);
    
};


#endif /* ControllerMoveBase_hpp */
