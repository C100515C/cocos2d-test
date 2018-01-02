/*
    �ļ�����    MMWinBaseFactory.h
    �衡����    �ؼ����󹤳�
    �����ˣ�    ��ľͷ (���ͣ�http://www.benmutou.com)
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
    /* �����ฺ�𴴽��ؼ� */
    virtual MMBase* createWin(EnumWinType enWinType) = 0;
};

#endif