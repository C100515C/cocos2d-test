#include "MMWinXmlData.h"
#include "EnumWinType.h"

bool MMWinXmlData::init() {
	m_isNone = false;           /* ��Ǳ����Ƿ�Ϊ�սڵ� */

	mEnWinType = en_Win_None;   /* �ؼ����� */
	m_iX = 0;                   /* X���� */
	m_iY = 0;                   /* Y���� */

	return true;
}

void MMWinXmlData::addCldXmlData( MMWinXmlData* cldXmlData )
{
	this->mCldXmlDataList.pushBack(cldXmlData);
}

Vector<MMWinXmlData*> MMWinXmlData::getCldXmlDataList() {
	return this->mCldXmlDataList;
}

bool MMWinXmlData::isHasChild() {
	if(mCldXmlDataList.size() > 0) {
		return true;
	}
	else {
		return false;
	}
}
