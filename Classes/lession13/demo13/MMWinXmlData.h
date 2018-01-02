/*
    �ļ�����    MMWinXmlData.h
    �衡����    xml�еĿؼ����Խṹ
    �����ˣ�    ��ľͷ (���ͣ�http://www.benmutou.com)
*/
#ifndef __MM_WIN_XML_DATA_H__
#define __MM_WIN_XML_DATA_H__

#include "cocos2d.h"
#include "EnumWinType.h"
#include "GlobalDefine.h"
USING_NS_CC;

class MMWinXmlData : public Ref {
public:
	CREATE_FUNC(MMWinXmlData);
	virtual bool init();

	/* ����ӽڵ� */
	void addCldXmlData(MMWinXmlData* cldXmlData);

	/* ��ȡ�ӽڵ��б�<MMWinXmlData*> */
    Vector<MMWinXmlData*> getCldXmlDataList();

	/* �Ƿ����ӽڵ� */
	bool isHasChild();

private:
	/* �ӽڵ��б�<MMWinXmlData*> */
    Vector<MMWinXmlData*> mCldXmlDataList;

	CC_PRIVATE_BOOL(m_isNone, None);/* ��Ǳ����Ƿ�Ϊ�սڵ�(û������,���������ӽڵ�) */

	CC_PRIVATE(EnumWinType, mEnWinType, EnWinType);/* �ؼ����� */ 
	CC_PRIVATE(int, m_iX, iX);                  /* X���� */
	CC_PRIVATE(int, m_iY, iY);                  /* Y���� */

};


#endif