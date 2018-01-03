//
//  MonsterG.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/12/25.
//

#ifndef MonsterG_hpp
#define MonsterG_hpp

#include <stdio.h>
#include "EntityG.hpp"
#include "PosBase.hpp"
#include "ControllerSimpleMove.hpp"

class MonsterG: public EntityG{
public:
    MonsterG();
    ~MonsterG();
    static MonsterG* create(Sprite *sprite);
    bool init(Sprite *sprite);
    
    //给定怪物 ID，从配置文件中读取数据
    static MonsterG *createFromCSVFileByID(int iMonsterID);
    bool initFromCSVFileByID(int iMonsterID);
    
    CREATE_FUNC(MonsterG);
    bool init();
    
public:
    //升级
    void upgrade();
    void moveByPosList(Vector<PosBase*>posList);
private:
    ControllerSimpleMove *m_moveController;
    CC_PRIVATE(int, m_iLevel, iLevel);
    CC_PRIVATE(float, m_showTime, fShowTime);//出场时间
};

#endif /* MonsterG_hpp */
