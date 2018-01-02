//
//  SateWriteCode.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/9.
//
//

#include "SateWriteCode.hpp"
#include "MutouT.hpp"
#include "StateReset.hpp"

void StateWriteCode::execute(MutouT *mutou){
    if (mutou -> isTired()) {
        mutou -> reset();
        mutou -> changeState(new StateReset());
    }
}
