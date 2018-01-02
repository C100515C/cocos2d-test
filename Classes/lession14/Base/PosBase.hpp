//
//  PosBase.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/8.
//

#ifndef PosBase_hpp
#define PosBase_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
//坐标 基础类
class PosBase : public Layer{
public:
    PosBase();
    ~PosBase();
    
    static PosBase *create(Point pos);
    static PosBase *create(Point pos,bool isDebug);
    
    bool init(Point pos);
    bool init(Point pos,bool isDebug);

    CC_SYNTHESIZE(Point,m_pos,Pos);//生成坐标成员
    
    virtual bool isClickMe(Point pos);//判断是否进入范围
    void setDebug(bool isDebug);//开启或者关闭调试模式

protected:
    bool m_isDebug;//判断调试模式
    
};

#endif /* PosBase_hpp */
