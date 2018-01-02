#include "MMWinXmlData.h"
#include "EnumWinType.h"

bool MMWinXmlData::init() {
	m_isNone = false;           /* 标记本身是否为空节点 */

	mEnWinType = en_Win_None;   /* 控件类型 */
	m_iX = 0;                   /* X坐标 */
	m_iY = 0;                   /* Y坐标 */

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
