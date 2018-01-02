//
//  MMWinBaseFactory.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/3.
//

#ifndef MMWinBaseFactory_hpp
#define MMWinBaseFactory_hpp

#include <stdio.h>
#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
#include "CommonDefine.h"

class MMBase;
class MMWinBaseFactory : public Ref{
public:
//    CREATE_FUNC(MMWinBaseFactory);
//    virtual bool init();
    //根据类型创建一个控件
    MMBase *createWinByType(WinType enWinType);
protected:
    //由子类 负责控制创建
    virtual MMBase *createWin(WinType enWinType)=0;
};

#endif /* MMWinBaseFactory_hpp */
