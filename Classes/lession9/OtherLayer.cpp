//
//  OtherLayer.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/28.
//
//

#include "OtherLayer.hpp"

bool OtherLayer::init(){

    if (!Layer::init()) {
        return false;
    }
    
    //添加观察者
    NotificationCenter::getInstance() -> addObserver(this, callfuncO_selector(OtherLayer::getMsg), "test", (Ref*)"ddd");
    
    
    return true;

}

void OtherLayer::getMsg(cocos2d::Ref *pData){
    log("我来了：%s",&pData);
}
