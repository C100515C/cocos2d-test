/*
    �ļ�����    MMWinManager.h
    �衡����    �ؼ���������
    �����ˣ�    ��ľͷ (���ͣ�http://www.benmutou.com)
*/
#ifndef __MM_DESKTOP_WIN_H__
#define __MM_DESKTOP_WIN_H__

#include "cocos2d.h"
#include "MMBase.h"

USING_NS_CC;

class MMDesktopWin : public MMBase {
public:
    MMDesktopWin();
    ~MMDesktopWin();

    CREATE_FUNC(MMDesktopWin);
    virtual bool init();

public:
    /* ���һ���ؼ� */
    void addWin(MMBase* mmWin);

    /* ����ID��ȡ�ؼ� */
    MMBase* getWinByID(int ID);

    /* ɾ�����пؼ� */
    void removeAllWins();
private:
    /* ������пؼ����ֵ� */
    Map<int, MMBase*> mWinDict;
};

#endif