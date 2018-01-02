//
//  CommDefine.h
//  Chapter2_4_HelloWorld
//
//  Created by CC on 2017/11/8.
//

#ifndef CommDefine_h
#define CommDefine_h

typedef enum {
    enTowerPos,//炮台坐标
    enMonsterPos//怪兽坐标
} PosType;

typedef enum{
    en_none,
    en_strKey_public_confirm = 1,//确定 1
    en_strKey_public_monster,//怪物 2
    en_strKey_public_TowerSoul,//塔魂 3
    en_strKey_public_Magic,//魔力 4
    en_Max
    
}EnumStrKey;

//位置坐标范围半径
#define Tower_RADIUS 32
#define Monster_RADIUS 8

//创建生成 varType类型 私有变量 并且生成 set  get 方法
#define CC_PRIVATE(varType,varName,funName)\
private:varType varName;\
public:varType get##funName(void) const{return varName;}\
public:void set##funName(varType var){varName = var;}\

//消息派发
#define NOTIFY cocos2d::NotificationCenter::getInstance()

//移动间隔时间
#define CHECK_MOVE_SPEED_LEVEL1 0.1f
#define CHECK_MOVE_SPEED_LEVEL2 0.04f
#define CHECK_MOVE_SPEED_LEVEL3 0.03f

#define SPEED 1

#endif /* CommDefine_h */
