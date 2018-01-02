//
//  MonsterManager.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/12/25.
//

#ifndef MonsterManager_hpp
#define MonsterManager_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class PosBase;
class MonsterG;
class MonsterPos;
class MonsterManager: public Node{
public:
    MonsterManager();
    ~MonsterManager();
    
    static MonsterManager * createWithLevel(int iCurLevel);//
    bool initWithLevel(int iCurLevel);//
    
    void createMonster(int iCurLevel);//读取配置文件创建怪物
    int getNotShowMonsterCount();//获得未出场怪物数量
    MonsterPos *getMonsterStartPos();//获得怪物起点坐标 
    MonsterPos *getMonsterEndPos();//获得怪物终点坐标
    Vector<MonsterG*>getMonsterList();//获得怪物对象列表
    
private:
    Vector<MonsterG *>m_monsterList;//存放所有怪物对象
    Vector<MonsterG *>m_notShowMonster;//存放未出场怪物
    Vector<PosBase *>m_monsterPosList;//存放怪物坐标对象
    float m_fShowTimeCount;//计算怪物出厂时间
    void showMonster(float dt);//检查 是否有新怪物出厂
    
};

#endif /* MonsterManager_hpp */
