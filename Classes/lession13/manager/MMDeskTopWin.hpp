//
//  MMDeskTopWin.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/3.
//

#ifndef MMDeskTopWin_hpp
#define MMDeskTopWin_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
#include "MMBase.hpp"

class MMDeskTopWin:public MMBase{
public:
    CREATE_FUNC(MMDeskTopWin);
    virtual bool init();
    MMDeskTopWin();
    ~MMDeskTopWin();
public:
    //添加控件
    void addWin(MMBase *mmWin);
    //通过id 获取控件
    MMBase *getWinByID(int id);
    //移除所有的控件
    void removeAllWins();
    
private:
    //存放所有控件字典
    Map<int,MMBase*> mWinsDict;
};
#endif /* MMDeskTopWin_hpp */
