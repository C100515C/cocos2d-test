//
//  Entity.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/19.
//
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class Entity : public Node{
public:
    Entity();
    ~Entity();
    Sprite *getSprite();//获取i 精灵队形
    void bindSprite(Sprite *sprite);//绑定精灵对象
    
private:
    Sprite *m_sprite;

};

#endif /* Entity_hpp */
