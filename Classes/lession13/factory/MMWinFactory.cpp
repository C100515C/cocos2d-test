//
//  MMWinFactory.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/3.
//

#include "MMWinFactory.hpp"
#include "MMLabel.hpp"
#include "MMNormalWin.hpp"

bool MMWinFactory::init(){
    return true;
}

MMBase *MMWinFactory ::createWin(WinType enWinType){
    MMBase *baseWin = NULL;
    switch (enWinType) {
        case en_Win_None:
            break;
        case en_Win_Normal:
        {
            baseWin = MMWinNormal::create();
        }
            break;
        case en_Win_Label:
        {
            baseWin = MMLabel::create();
        }
            break;
        default:
            break;
    }
    
    if (baseWin!=NULL) {
        baseWin ->setEnWinType(enWinType);
    }
    
    return baseWin;
}
