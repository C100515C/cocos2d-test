/*
    文件名：    MMWinBaseFactory.h
    描　述：    控件抽象工厂
    创建人：    笨木头 (博客：http://www.benmutou.com)
*/
#ifndef __MM_WIN_BASE_FACTORY_H__
#define __MM_WIN_BASE_FACTORY_H__

#include "cocos2d.h"
#include "MMBase.h"
#include "EnumWinType.h"
USING_NS_CC;

class MMWinBaseFactory : public Ref {
public:

    MMBase* createWinByType(EnumWinType enWinType);

protected:
    /* 由子类负责创建控件 */
    virtual MMBase* createWin(EnumWinType enWinType) = 0;
};

#endif