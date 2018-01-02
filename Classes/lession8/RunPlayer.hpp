//
//  RunPlayer.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/24.
//
//

#ifndef RunPlayer_hpp
#define RunPlayer_hpp

#include <stdio.h>
#include "RunEntity.hpp"

class RunPlayer : public RunEntity{
public:
    CREATE_FUNC(RunPlayer);
    virtual bool init();
    void run();
    void bindMap(TMXTiledMap*map);
    virtual void setTagPoint(float x,float y);
private:
    void setViewPointByPlyer();
    TMXTiledMap *m_map;
    
    bool isJumping;
    bool isRotate;
    
    //检测 碰撞的地图层
    cocos2d::TMXLayer *m_meta;
    
    //将像素坐标转为格子坐标
    Point tileCoordForPostion(Point point);
};

#endif /* RunPlayer_hpp */
