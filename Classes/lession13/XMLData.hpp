//
//  XMLData.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/10/30.
//

#ifndef XMLData_hpp
#define XMLData_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "CommonDefine.h"
//#include "GlobalDefine.h"
//#include "EnumWinType.h"
USING_NS_CC;

class XMLData : public Ref{
public:
    CREATE_FUNC(XMLData);
    virtual bool init();
    
    //添加子节点
    void addChildNodeXMLData(XMLData *childXMLData);
    
    //获取 子节点列表
    Vector<XMLData *> getChildNodesList();
    
    //判断是否有子节点
    bool isHaveChild();
    
private:
    Vector<XMLData*> mChildNodeList;//子节点列表
    
    CC_PRIVATE_BOOL(m_isNone, None);//标记本身是否为空
    CC_PRIVATE(WinType, mWinType, winType);//控件类型

    CC_PRIVATE(int, m_iX, iX);//x 坐标
    CC_PRIVATE(int, m_iY, iY);//y 坐标

    
};

#endif /* XMLData_hpp */
