//
//  LessionTenScene.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/2.
//
//

#ifndef LessionTenScene_hpp
#define LessionTenScene_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class LessionTen : public Layer{
public :
    CREATE_FUNC(LessionTen);
    virtual bool init();
    static Scene * createScene();
    
private:
    void getStore(float delay);
    void readJson();
    
};

#endif /* LessionTenScene_hpp */
