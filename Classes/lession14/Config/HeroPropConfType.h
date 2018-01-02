//
//  HeroPropConfType.h
//  Chapter2_4_HelloWorld
//
//  Created by CC on 2017/11/30.
//

#ifndef HeroPropConfType_h
#define HeroPropConfType_h

typedef enum{
    enHeroPropConf_ID,        // 英雄ID
    enHeroPropConf_Name,        // 英雄名字
    enHeroPropConf_Type,        // 英雄类型
    enHeroPropConf_ModelID,        // 英雄模型ID
    enHeroPropConf_BaseAtk,            // 基础攻击力
    enHeroPropConf_AtkSpeed,        // 攻击间隔（单位：秒）
    enHeroPropConf_AtkRange,        // 攻击范围（半径）
    enHeroPropConf_UpgradeAtkBase,    // 升级攻击加成系数
    enHeroPropConf_UpgradeCostBase,    // 升级消耗基础值
    
}EnumHeroPropConfType;

#endif /* HeroPropConfType_h */
