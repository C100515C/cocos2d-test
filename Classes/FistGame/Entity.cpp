//
//  Entity.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/19.
//
//

#include "Entity.hpp"

Entity :: Entity(){
    m_sprite = NULL;
}

Entity :: ~Entity(){
    
}

Sprite * Entity::getSprite(){
    return this->m_sprite;
}

void Entity::bindSprite(Sprite *sprite){
    this-> m_sprite = sprite;
    this-> addChild(m_sprite);
    
    Size size = m_sprite -> getContentSize();
    m_sprite -> setPosition(size.width*0.5, size.height*0.5);
    this -> setContentSize(size);
    
}


