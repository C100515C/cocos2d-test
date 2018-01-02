/*
    �ļ�����    MMNormalWin.h
    �衡����    ��ͨ����
    �����ˣ�    ��ľͷ (���ͣ�http://www.benmutou.com)
*/
#ifndef __MM_NORMAL_H__
#define __MM_NORMAL_H__

#include "MMBase.h"

class MMNormalWin : public MMBase {
public:
    MMNormalWin();
    ~MMNormalWin();

    CREATE_FUNC(MMNormalWin);
    virtual bool init();

    virtual void setAnchorPoint(const Point& anchorPoint);

	/* ���ô��ڱ���ͼƬ */
    void setBG(const char* sPath);
    
private:
	/* ��һ��������Ϊ���ڵı��� */
    Sprite* m_sprite;
};

#endif