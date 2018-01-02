//
//  StateWriteActicle.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/10/23.
//

#include "StateWriteActicle.hpp"
#include "MutouT.hpp"
#include "StateReset.hpp"

void StateWriteActicle::execute(MutouT *mutou){
    if (mutou -> isTired()) {
        mutou -> reset();
        mutou -> changeState(new StateReset());
    }
}
