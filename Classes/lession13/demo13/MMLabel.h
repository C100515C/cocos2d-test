/*
    �ļ�����    MMLabel.h
    �衡����    ��ǩ�ؼ�
    �����ˣ�    ��ľͷ (���ͣ�http://www.benmutou.com)
*/
#ifndef __MM_LABEL_H__
#define __MM_LABEL_H__

#include "MMBase.h"

class MMLabel : public MMBase {
public:
    MMLabel();
    ~MMLabel();

    CREATE_FUNC(MMLabel);
    virtual bool init();

    virtual void setAnchorPoint(const Point& anchorPoint);

	/* ���ñ�ǩ���� */
    void setsText(const char* sText);

	/* ���ñ�ǩ���ݣ�����Ϊ���� */
    void setsText(int iValue);

	/* ���ñ�ǩ���ִ�С */
    void setiFontSize(int iFontSize);

	/* ���ñ�ǩ������ɫ */
    void setColorRGB(int r, int g, int b);
private:
    Label* m_label;
};

#endif