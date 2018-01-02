//
//  LT_stringUtil.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/2.
//
//

#include "LT_stringUtil.hpp"

LT_stringUtil *LT_stringUtil::m_share =NULL;

bool LT_stringUtil::init(){
    return true;
}


LT_stringUtil * LT_stringUtil::getIntance(){
    if (m_share==NULL) {
        m_share =new LT_stringUtil();
        if (m_share && m_share ->init()) {
            m_share ->autorelease();
            m_share -> retain();
        }else{
            CC_SAFE_DELETE(m_share);
            m_share = NULL;
        }
    }
    return m_share;
}

ValueVector LT_stringUtil::split(const char *srcStr, const char *sSep){
    ValueVector stringList;
    size_t size = strlen(srcStr);
    //将数据转出 字符串对象
    Value str = Value(srcStr);
    
    size_t startIndex = 0;
    int endIndex = 0;
    
    endIndex = (int) str.asString().find(sSep);
    
    std::string lineStr;
    while (endIndex>0) {
        //截取 一行 字符串
        lineStr = str.asString().substr(startIndex,endIndex);
        stringList.push_back(Value(lineStr));//存入列表
        str = Value(str.asString().substr(endIndex+1,size));//取剩下部分字符串
        
        endIndex = (int)str.asString().find(sSep);//查找下一个分隔符位置
    }
    
    //剩下部分 也存进去
    if (str.asString().compare("")!=0) {
        stringList.push_back(Value(str.asString()));
    }
    
    return stringList;
}
