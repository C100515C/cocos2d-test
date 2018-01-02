//
//  TowerPos.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/8.
//

#ifndef TowerPos_hpp
#define TowerPos_hpp

#include <stdio.h>
#include "PosBase.hpp"
#include "CommDefine.h"

class TowerPos : public PosBase{
public:
    TowerPos();
    ~TowerPos();
    
    static TowerPos *create(Point pos);
    static TowerPos *create(Point pos,bool isDebug);
    
    bool init(Point pos);
    bool init(Point pos,bool isDebug);
    
    virtual bool isClickMe(Point pos) override;//判断是否进入范围
    virtual void draw(Renderer *renderer, const kmMat4 &transform,uint32_t transformUpdated);
private:
    
    void onDraw(const kmMat4 &transform,bool transformUpdated);
    CustomCommand _customCommand;
    
};

#endif /* TowerPos_hpp */
