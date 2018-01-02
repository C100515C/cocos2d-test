//
//  TowerBorder.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/30.
//

#ifndef TowerBorder_hpp
#define TowerBorder_hpp

#include <stdio.h>
#include"EntityG.hpp"

class HeroG;
class TowerBorder:public EntityG{
public:
    CREATE_FUNC(TowerBorder);
    virtual bool init();
    
    TowerBorder();
    ~TowerBorder();
    
    void upgrade();
    
    
    /**
     是否进入范围

     @param pos pos description
     @return return value description
     */
    bool isClickMe(Point pos);
    
    void bindHero(HeroG *iHero);
    HeroG *getHero();
    void deleteHero();
private:
    HeroG *m_iHero;
};
#endif /* TowerBorder_hpp */
