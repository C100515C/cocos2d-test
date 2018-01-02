//
//  RunController.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/24.
//
//

#ifndef RunController_hpp
#define RunController_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ControllerListener.hpp"

USING_NS_CC;

class RunController:public Node{
public:
    void setControllerListener(ControllerListener *contollerListener);
protected:
    ControllerListener *m_controllerListener;
};

#endif /* RunController_hpp */
