//
//  MMWinFactory.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/3.
//

#ifndef MMWinFactory_hpp
#define MMWinFactory_hpp

#include <stdio.h>
#include "MMWinBaseFactory.hpp"

class MMWinFactory : public MMWinBaseFactory{
public:
    CREATE_FUNC(MMWinFactory);
    virtual bool init();
protected:
    virtual MMBase *createWin(WinType enWinType);
    
};
#endif /* MMWinFactory_hpp */
