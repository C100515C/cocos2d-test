//
//  TollgateMapLayer.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/28.
//

#ifndef TollgateMapLayer_hpp
#define TollgateMapLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class HeroManagerG;
class TollgateMapLayer : public Layer{
public:
    TollgateMapLayer();
    ~TollgateMapLayer();
    CREATE_FUNC(TollgateMapLayer);
    virtual bool init();
    
private:
    int m_currentLevel;//当前关卡
    
    /**
     读取配置文件
     */
    void loadConfig();
    
    HeroManagerG *m_heroManager;
};
#endif /* TollgateMapLayer_hpp */
