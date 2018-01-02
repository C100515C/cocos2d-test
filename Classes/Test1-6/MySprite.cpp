
//
//  MySprite.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/11.
//
//

#include "MySprite.hpp"

MySprite * MySprite :: createSprite(){
    MySprite *sprite = MySprite ::create();
    
    return sprite;
}

bool MySprite:: init(){
    this -> setName("CloseNormal.png");
    this -> setColor(Color3B(200, 100, 33));
    this  -> setPosition(100, 100);
    
    return  true;
}
