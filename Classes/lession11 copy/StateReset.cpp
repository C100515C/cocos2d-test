//
//  StateReset.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/10/23.
//

#include "StateReset.hpp"
#include "MutouT.hpp"
#include "StateWriteActicle.hpp"
#include "SateWriteCode.hpp"

void StateReset::execute(MutouT *mutou){
    if (mutou ->isWantToWriteArticle()) {
        mutou -> writeArticle();
        mutou -> changeState(new StateWriteActicle());
    }else{
        mutou -> writeCode();
        mutou -> changeState(new StateWriteCode());
    }
}
