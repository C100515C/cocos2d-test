/*
    �ļ�����    MMWinManager.h
    �衡����    �ؼ�������
              ��Ҫ����ؼ����������,����XML�����ؼ���
    �����ˣ�    ��ľͷ (���ͣ�http://www.benmutou.com)
*/
#ifndef __MM_WIN_MANAGER_H__
#define __MM_WIN_MANAGER_H__

#include "cocos2d.h"
#include "MMDesktopWin.h"
#include "MMWinSystem.h"
#include "tinyxml.h"
#include "MMWinXmlData.h"
#include "MMWinXmlDataSetting.h"
#include "MMBase.h"
USING_NS_CC;

class MMWinManager : public Ref {
public:
    MMWinManager();
    ~MMWinManager();

    static MMWinManager* getInstance();
    virtual bool init();

    /* ��ȡ���� */
    MMDesktopWin* getDesktopWin();

    /* ��ȡ�ؼ������� */
    MMWinSystem* getWinSystem();
public:
    /* ����XML�ļ�,�����ؼ� */
    MMBase* createWinsFromXML(const char* sXmlPath);
private:
    /* ��ȡXMLԪ��,����һ��xml�ؼ����Խṹ���� */
    MMWinXmlData* createXmlData(TiXmlElement* xmlElement);

    /* ��XML data����ֵ */
    void setWinXmlData(MMWinXmlData* xmlData, const char* sName, const char* sText);
private:
    static MMWinManager* mWinManager;

private:
    /* �ؼ��������� */
    MMDesktopWin* mDesktopWin;

    /* �ؼ������� */
    MMWinSystem* mWinSystem;

    /* xml���Խṹ������ */
    MMWinXmlDataSetting* mWinXmlDataSetting;
};

#endif
