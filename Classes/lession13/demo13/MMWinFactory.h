/*
    文件名：    MMWinFactory.h
    描　述：    控件工厂 主要负责创建控件
    创建人：    笨木头 (博客：http://www.benmutou.com)
*/
#ifndef __MM_WIN_FACTORY_H__
#define __MM_WIN_FACTORY_H__

#include "MMWinBaseFactory.h"

class MMWinFactory : public MMWinBaseFactory {
public:
    CREATE_FUNC(MMWinFactory);
    virtual bool init();

protected:
    virtual MMBase* createWin( EnumWinType enWinType );
};

#endif