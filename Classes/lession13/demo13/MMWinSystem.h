/*
    �ļ�����    MMWinSyetem.h
    �衡����    ����ؼ������߼�
    �����ˣ�    ��ľͷ (���ͣ�http://www.benmutou.com)
*/
#ifndef __MM_WIN_SYSTEM_H__
#define __MM_WIN_SYSTEM_H__

#include "cocos2d.h"
#include "MMBase.h"
#include "MMWinXmlData.h"
#include "EnumWinType.h"
#include "MMDesktopWin.h"
#include "MMWinBaseFactory.h"
#include "MMWinPropertyFactory.h"

USING_NS_CC;

class MMWinSystem : public Ref {
public:
    MMWinSystem();
    ~MMWinSystem();

    static MMWinSystem* create(MMDesktopWin* desktopWin);
    virtual bool init(MMDesktopWin* desktopWin);

    /*
        ����XML�ṹ���ݴ����ؼ�.
        ���п��ܴ����ܶ���ؼ�,�����ն�����ӵ�һ�����ؼ���.
        ���仰˵,xml�ļ���ֻ�������һ����߸��ؼ�,���ܳ���ͬ����ĸ��ؼ�.
    */
    MMBase* createWinsByXmlData(MMWinXmlData* xmlData, bool isHasParent);

    /* ���ݿؼ����͸��ؼ���������(�����·�һ��) */
    void dressPropertiesByType(MMBase* mmWin, MMWinXmlData* xmlData);

    /* ����һ��ΨһID */
    int createUniqueID();
private:/* ---------- ���� ---------- */

    /* ���� */
    MMDesktopWin* mDesktopWin;

    /* �ؼ����� */
    MMWinBaseFactory* mWinFactory;

    /* �ؼ����Լӹ��� */
    MMWinPropertyFactory* mWinPropertyFactory;

    /* �ؼ�ID */
    int m_iWinID;

private:/* ---------- ���� ---------- */

    /* ����XML�ṹ���ݴ���һ���ؼ� */
    MMBase* createWinByXmlData(MMWinXmlData* xmlData);

    /* ���ݿؼ����ʹ���һ���ؼ� */
    MMBase* createWinByType(EnumWinType enWinType);

};

#endif