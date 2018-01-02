/*
    文件名：    MMWinXmlData.h
    描　述：    xml中的控件属性结构
    创建人：    笨木头 (博客：http://www.benmutou.com)
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

	/* 添加子节点 */
	void addCldXmlData(MMWinXmlData* cldXmlData);

	/* 获取子节点列表<MMWinXmlData*> */
    Vector<MMWinXmlData*> getCldXmlDataList();

	/* 是否有子节点 */
	bool isHasChild();

private:
	/* 子节点列表<MMWinXmlData*> */
    Vector<MMWinXmlData*> mCldXmlDataList;

	CC_PRIVATE_BOOL(m_isNone, None);/* 标记本身是否为空节点(没有内容,但可以有子节点) */

	CC_PRIVATE(EnumWinType, mEnWinType, EnWinType);/* 控件类型 */ 
	CC_PRIVATE(int, m_iX, iX);                  /* X坐标 */
	CC_PRIVATE(int, m_iY, iY);                  /* Y坐标 */

};


#endif