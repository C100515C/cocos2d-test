/*
    �ļ�����    MMWinXmlDataSetting.h
    �衡����    �ؼ�XML���Խṹ������
    �����ˣ�    ��ľͷ (���ͣ�http://www.benmutou.com)

    �������ڣ�   2012.12.12
*/
#ifndef __MM_WIN_XML_DATA_SETTING_H__
#define __MM_WIN_XML_DATA_SETTING_H__

/* XML�ļ��Ľڵ�����*/
#define XML_VALUE_enWinType "enWinType"     // �ؼ�����
#define XML_VALUE_x "x"                     // x����
#define XML_VALUE_y "y"                     // y����

#include "cocos2d.h"
#include "MMWinXmlData.h"

USING_NS_CC;

/* ��ͨset����, Ϊ�˼����ظ�����������:void setXmliX(MMWinXmlData* xmlData, const char* sText); */
#define MM_SET_XML(funName)\
public: void setXml##funName(MMWinXmlData* xmlData, const char* sText);

class MMWinXmlDataSetting : public Ref {
public:
    CREATE_FUNC(MMWinXmlDataSetting);
    virtual bool init();

    /* ��XML data����ֵ */
    void setWinXmlData(MMWinXmlData* xmlData, const char* sName, const char* sText);
public:
    /* ------------- ����xml�еĽڵ��ַ������ݸ�ֵ --------------- */
    MM_SET_XML(EnWinType);/* ���ÿؼ����� */
    MM_SET_XML(iX);/* ����X���� */
    MM_SET_XML(iY);/* ����Y���� */
};

#endif