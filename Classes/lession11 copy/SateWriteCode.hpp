//
//  SateWriteCode.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/9.
//
//

#ifndef SateWriteCode_hpp
#define SateWriteCode_hpp

#include <stdio.h>
#include "State.hpp"

class MutouT;
class StateWriteCode: public State{
public:
    virtual void execute(MutouT *mutou);
};

#endif /* SateWriteCode_hpp */
