//
//  NormalBullet.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2018/1/4.
//

#ifndef NormalBullet_hpp
#define NormalBullet_hpp

#include <stdio.h>
#include "BulletBase.hpp"

class NormalBullet : public BulletBase{
public:
    NormalBullet();
    ~NormalBullet();
    
    CREATE_FUNC(NormalBullet);
    virtual bool init();
    
    static NormalBullet *create(Sprite *sprite);
    bool init(Sprite *sprite);
    
protected:
    virtual void onLockAim(EntityG *aim);
private:
    void moveEnd();
};

#endif /* NormalBullet_hpp */
