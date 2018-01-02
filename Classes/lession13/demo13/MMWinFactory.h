/*
    �ļ�����    MMWinFactory.h
    �衡����    �ؼ����� ��Ҫ���𴴽��ؼ�
    �����ˣ�    ��ľͷ (���ͣ�http://www.benmutou.com)
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