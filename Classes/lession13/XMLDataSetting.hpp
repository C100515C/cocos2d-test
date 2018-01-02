//
//  XMLDataSetting.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/10/31.
//

#ifndef XMLDataSetting_hpp
#define XMLDataSetting_hpp

#include <stdio.h>
#include "XMLData.hpp"
#include "CommonDefine.h"

class XMLDataSetting: public Ref{
public:
    CREATE_FUNC(XMLDataSetting);
    virtual bool init();
    
    //给xmlData 对象赋值
    void setXmlData(XMLData *xmlData,const char *sName,const char *sText);
    
public:
    //根据xml 节点字符串内容 赋值
    CC_XML_SET(EnWinType);
    CC_XML_SET(iX);
    CC_XML_SET(iY);
    
};

#endif /* XMLDataSetting_hpp */
