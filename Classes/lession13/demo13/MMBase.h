/*
    �ļ�����    MMWinSyetem.h
    �衡����    ľͷ�Ŀؼ�����
    �����ˣ�    ��ľͷ (���ͣ�http://www.benmutou.com)
*/
#ifndef __MM_BASE_H__
#define __MM_BASE_H__

#include "cocos2d.h"
#include "EnumWinType.h"
#include "GlobalDefine.h"

USING_NS_CC;

/*
 * @class
 * 
 * ����Сľ���Զ���Ŀؼ�����
 * ��ʵ����û������ĵط�,�Ҽ̳���Node
 *
 * �ǵ�,���е�ľͷ�Զ���ؼ�������̳�MMBase.
 */
class MMBase : public Node {
public:
    MMBase();
    ~MMBase();

private:
    CC_PRIVATE(int, m_ID, ID);				/* �ؼ�ID */
    CC_PRIVATE(int, m_iOrder, iOrder);		/* ��� */
	CC_PRIVATE(EnumWinType, mEnWinType, EnWinType);		/* �ؼ����� */ 
    CC_PRIVATE_BOOL(m_isHasParentWin, HasParentWin);  /* �Ƿ��и��ؼ� */
    CC_PRIVATE_BOOL(m_isHasChildWin, HasChildWin);    /* �Ƿ����ӿؼ� */
};

#endif