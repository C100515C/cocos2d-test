//
//  StateWriteActicle.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/10/23.
//

#ifndef StateWriteActicle_hpp
#define StateWriteActicle_hpp

#include <stdio.h>
#include "State.hpp"

class MutouT;
class StateWriteActicle: public State{
public:
    virtual void execute(MutouT *mutou);
};

#endif /* StateWriteActicle_hpp */
