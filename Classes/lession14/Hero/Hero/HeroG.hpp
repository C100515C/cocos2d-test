//
//  HeroG.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/30.
//

#ifndef HeroG_hpp
#define HeroG_hpp

#include <stdio.h>
#include "EntityG.hpp"

class BulletManager;
class MonsterG;
class HeroG : public EntityG{
public:
    HeroG();
    ~HeroG();
    static HeroG* create(Sprite *sprite);
    bool init(Sprite *sprite);
    
    //给定英雄 ID，从配置文件中读取数据
    static HeroG *createFromCSVFileByID(int iHeroID);
    bool initFromCSVFileByID(int iHeroID);
    
    CC_PRIVATE(int, m_iBaseAtk, iBaseAtk);//基础攻击力
    CC_PRIVATE(int, m_iCurrentAtk, iCurrentAtk);//当前攻击力
    CC_PRIVATE(int, m_iAtkSpeed, iAtkSpeed);//攻击速度
    CC_PRIVATE(int, m_iAtkRang, iAtkRange);//攻击范围
    CC_PRIVATE(int, m_iUpgradeCostBase, iUpgradeCostBase);//升级消耗基础值
    CC_PRIVATE(int, m_iUpgradeAtkBase, iUpgradeAtkBase);//升级攻击增加系数
    CC_PRIVATE(bool, m_isAtkCoolDown, isAtkCoolDown);//攻击冷却

    //升级
    void  upgrade();
    
    //检查 攻击怪物
    void checkAtkMonster(float ft, Vector<MonsterG *>monsterList);
private:
    MonsterG* m_atkMonster;
    void chooseAim(Vector<MonsterG *>monsterList);
    void checkAimIsOutOfRange(Vector<MonsterG *>monsterList);
    void atk();
    bool isInAtkRange(Point point);
    void chooseAtkMonster(MonsterG* monster);
    void atkCoolDown(float dt);
    void missAtkMonster();
    BulletManager* m_bulletManager;
};

#endif /* HeroG_hpp */
