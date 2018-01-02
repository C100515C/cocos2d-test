/*
    �ļ�����    MMWinPropertyFactory.h
    �衡����    �ؼ����Լӹ��� ��Ҫ�������ÿؼ�������
    �����ˣ�    ��ľͷ (���ͣ�http://www.benmutou.com)
*/
#ifndef __MM_WIN_PROPERTY_FACTORY_H__
#define __MM_WIN_PROPERTY_FACTORY_H__

#include "cocos2d.h"
#include "MMBase.h"
#include "EnumWinType.h"
#include "MMWinXmlData.h"
USING_NS_CC;

class MMNormalWin;
class MMLabel;
class MMWinPropertyFactory : public Ref {
public:
    CREATE_FUNC(MMWinPropertyFactory);
    virtual bool init();

public:
    /* ���ؼ���������(���·�~) */
    void dressPropertiesByType( MMBase* mmWin, MMWinXmlData* xmlData );

private:
    /* ���ÿؼ���������,���пؼ����������� */
    void dressBaseProperties(MMBase* mmWin, MMWinXmlData* xmlData);

private:
	void dressMMNormalWin(MMNormalWin* mmNormalWin, MMWinXmlData* xmlData);
	void dressMMLabel(MMLabel* mmLabel, MMWinXmlData* xmlData);
};

#endif