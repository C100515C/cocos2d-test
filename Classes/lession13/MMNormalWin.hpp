//
//  MMNormalWin.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/1.
//

#ifndef MMNormalWin_hpp
#define MMNormalWin_hpp

#include <stdio.h>
#include "MMBase.hpp"

class MMWinNormal:public MMBase{
public:
    MMWinNormal();
    ~MMWinNormal();
    
    CREATE_FUNC(MMWinNormal);
    virtual bool init();
    virtual void setAnchorPoint(const Point &anchorPoint);
    
    void setBG(const char *sPath);//设置背景窗口图片
private:
    Sprite *m_sprite;//背景 窗口精灵
};

#endif /* MMNormalWin_hpp */
