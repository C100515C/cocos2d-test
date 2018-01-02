//
//  MonsterPos.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/20.
//

#ifndef MonsterPos_hpp
#define MonsterPos_hpp

#include <stdio.h>
#include "PosBase.hpp"
#include "CommDefine.h"

class MonsterG;
class MonsterPos : public PosBase{
public:
    MonsterPos();
    ~MonsterPos();
    
    static MonsterPos *create(Point pos);
    static MonsterPos *create(Point pos,bool isDebug);
    
    bool init(Point pos);
    bool init(Point pos,bool isDebug);
    
    virtual bool isClickMe(Point pos) override;//判断是否进入范围
    virtual void draw(Renderer *renderer, const kmMat4 &transform,uint32_t transformUpdated);
    
private:
    
    void onDraw(const kmMat4 &transform,bool transformUpdated);
    CustomCommand _customCommand;
    
    MonsterG *m_monster;
};
#endif /* MonsterPos_hpp */
