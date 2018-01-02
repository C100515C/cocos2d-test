//
//  StateReset.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/10/23.
//

#ifndef StateReset_hpp
#define StateReset_hpp

#include <stdio.h>
#include "State.hpp"

class MutouT;
class StateReset :public State{
public:
    virtual void execute(MutouT *mutou);
    
};
#endif /* StateReset_hpp */
