/*
    文件名：    MMWinSyetem.h
    描　述：    木头的控件基类
    创建人：    笨木头 (博客：http://www.benmutou.com)
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
 * 这是小木我自定义的控件基类
 * 其实它并没有神奇的地方,我继承了Node
 *
 * 是的,所有的木头自定义控件都必须继承MMBase.
 */
class MMBase : public Node {
public:
    MMBase();
    ~MMBase();

private:
    CC_PRIVATE(int, m_ID, ID);				/* 控件ID */
    CC_PRIVATE(int, m_iOrder, iOrder);		/* 层次 */
	CC_PRIVATE(EnumWinType, mEnWinType, EnWinType);		/* 控件类型 */ 
    CC_PRIVATE_BOOL(m_isHasParentWin, HasParentWin);  /* 是否有父控件 */
    CC_PRIVATE_BOOL(m_isHasChildWin, HasChildWin);    /* 是否有子控件 */
};

#endif