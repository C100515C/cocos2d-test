//
//  PosLoadUtil.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/16.
//

#ifndef PosLoadUtil_hpp
#define PosLoadUtil_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
#include "CommDefine.h"

class PosBase;
class PosLoadUtil : public Node{
public:
    static PosLoadUtil *getIntance();
    virtual bool init();
    /*
     根据坐标从plist中取出的配置文件 获取 坐标对象
     sFilePath 文件路劲
     container 存放坐标对象的容器
     level 如果存在容器 代表在容器中的层级
     isDebug 是否调试
     */
    Vector<PosBase*> loadPosWithFile(
     const char *sFilePath,
     PosType enPosType,
     Node *container,
     int level,
     bool isDebug
     );
    
private :
    static PosLoadUtil *m_posLoadUtil;

};

#endif /* PosLoadUtil_hpp */
