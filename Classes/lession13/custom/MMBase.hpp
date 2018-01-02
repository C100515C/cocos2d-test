//
//  MMBase.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/1.
//

#ifndef MMBase_hpp
#define MMBase_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "CommonDefine.h"
USING_NS_CC;

class MMBase:public Node{
public:
    MMBase();
    ~MMBase();
private:
    CC_PRIVATE(int, m_ID, ID);//控件 id
    CC_PRIVATE(int, m_iOrder, mOrder);//控件的层次
    CC_PRIVATE(WinType, mEnWinType, EnWinType);//控件类型
    CC_PRIVATE_BOOL(m_isHasParentWin, HasParentWin);//判断是否有父控件
    CC_PRIVATE_BOOL(m_isHasChildWin, HasChildWin);//是否有子控件
    
};

#endif /* MMBase_hpp */
