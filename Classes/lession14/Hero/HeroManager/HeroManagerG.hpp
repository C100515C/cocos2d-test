//
//  HeroManagerG.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/28.
//

#ifndef HeroManagerG_hpp
#define HeroManagerG_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

#define TOWER_POS_LAYER_LVL 5 //塔坐标层次
#define TOWER_BORDER_LAYER_LVL 8 //炮台层次
#define TOWER_LYAER_LVL 10 //塔层次

class PosBase;
class TowerBorder;
class MonsterG;
class HeroManagerG : public Node{
public:
    HeroManagerG();
    ~HeroManagerG();
    static HeroManagerG *createWithLevel(int iCurrentLevel);
    bool initWithLevel(int iCurrentLevel);
    void logic(float dt,Vector<MonsterG*>monsterList);

private:
    Vector<PosBase*>m_towerPosList;//存放所有塔坐标对象
    Vector<TowerBorder*>m_towerBordersList;//存放所有炮台对象
    
    void createTowerBorder(int iCurrentLevel);//创建炮台
    void createTowerPos(Point pos);//创建塔坐标对象
    /**
     查找点击炮台

     @param pos pos description
     @return return value description
     */
    TowerBorder *findClickTowerBorder(Point pos);
};

#endif /* HeroManagerG_hpp */
