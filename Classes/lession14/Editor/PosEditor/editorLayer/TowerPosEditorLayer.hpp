//
//  TowerPosEditorLayer.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/8.
//

#ifndef TowerPosEditorLayer_hpp
#define TowerPosEditorLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
#include "CommDefine.h"

class PosBase;
class TowerPosEditorLayer : public Layer{
public:
    TowerPosEditorLayer();
    ~TowerPosEditorLayer();
    
    virtual bool init();
    CREATE_FUNC(TowerPosEditorLayer);
    
    void outPutPosToPlistFile();//plist 配置坐标
    void loadConfigFile();//根据 当前关卡 加载文件 给pos位置赋值
    void changeMode();
    //关卡切换
    void nextLevel();
    void previousLevel();
    Vector<PosBase*> getMonstersPos();
private:
    int m_iCurLevel;//当前关卡
    PosType m_enMode; //当前模型 是怪物还是 塔
    void deleleAllTowerPos();//删除所有

    Vector<PosBase*> m_towerPosList;//存放所有的塔对象
    void editTowrPos(Point pos);//编辑 塔坐标
    PosBase *findExistTowerPos(Point pos);//根据坐标查到塔
    void createTowerPos(Point pos);//根据坐标创建塔
    void deleteTowerPos(PosBase *existPos);//删除塔对象
    
    Vector<PosBase*> m_monsterPosList;//存放所有的怪物对象
    void editMonsterPos(Point pos);//编辑 怪物标
    PosBase *findExistMonsterPos(Point pos);//根据坐标查到怪物
    void createMonsterPos(Point pos);//根据坐标创建怪物
    void deleteMonsterPos(PosBase *existPos);//删除怪物对象
    
    
};

#endif /* TowerPosEditorLayer_hpp */
