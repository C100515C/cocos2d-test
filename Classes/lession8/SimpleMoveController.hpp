//
//  SimpleMoveController.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/24.
//
//

#ifndef SimpleMoveController_hpp
#define SimpleMoveController_hpp

#include <stdio.h>
#include "RunController.hpp"

class SimpleMoveController : public RunController{
public:
    CREATE_FUNC(SimpleMoveController);
    virtual bool init();
    virtual void update(float delet);
    
    void setSpeed(float speed);
    
private:
    float m_speed;
};

#endif /* SimpleMoveController_hpp */
