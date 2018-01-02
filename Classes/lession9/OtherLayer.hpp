//
//  OtherLayer.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/28.
//
//

#ifndef OtherLayer_hpp
#define OtherLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class OtherLayer: public Layer{

public:
    CREATE_FUNC(OtherLayer);
    virtual bool init();
    
private:
    void getMsg(Ref *pData);
    
};

#endif /* OtherLayer_hpp */
