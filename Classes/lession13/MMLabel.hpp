//
//  MMLabel.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/1.
//

#ifndef MMLabel_hpp
#define MMLabel_hpp

#include <stdio.h>
#include "MMBase.hpp"

class MMLabel :public MMBase{
public:
    MMLabel();
    ~MMLabel();
    
    CREATE_FUNC(MMLabel);
    virtual bool init();
    virtual void setAnchorPoint(const Point &anchorPoint);
    
    void setsText(const char *sText);//设置标签内容
    void setsText(int iValue);//设置标签内容，内容为数字
    void setFontSize(int fontSize);//设置字体大小
    void setFontColor(int r,int g,int b);//设置字体颜色
    
private:
    Label *m_label;
};


#endif /* MMLabel_hpp */
