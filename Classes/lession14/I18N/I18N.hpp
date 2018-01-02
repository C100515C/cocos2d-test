//
//  I18N.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/27.
//

#ifndef I18N_hpp
#define I18N_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "CommDefine.h"
USING_NS_CC;

class I18N :public Ref{
public:
    static I18N *getInstance();
    virtual bool init();
    
    //根据 key 值获取字符串 值
    const char * getcStringByKey(EnumStrKey key);
    
    //根据整数 key 值获取字符串 值
    const char *getcStringByIntKey(int key);
    
private:
    
    /**
     获取 文件中的字符串放入字典

     @param sPath csv 文件路径
     */
    void loadStringFromComf(const char *sPath);
    
    //I18N对象
    static I18N* m_i18n;
    //游戏中用到的字符串字典
    std::map<int,std::string> mStringMap;
};



#endif /* I18N_hpp */
