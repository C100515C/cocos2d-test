//
//  LT_stringUtil.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/2.
//
//

#ifndef LT_stringUtil_hpp
#define LT_stringUtil_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class LT_stringUtil : public Ref
{
public:
    static LT_stringUtil *getIntance();
    virtual bool init();
    
    //用分隔符 分割字符串 将结果存到列表中，列表中是value 对象
    ValueVector split(const char *srcStr,const char *sSep);
    
private:
    static LT_stringUtil *m_share;

};

#endif /* LT_stringUtil_hpp */
