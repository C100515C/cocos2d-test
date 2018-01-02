/*
    文件名：    MMNormalWin.h
    描　述：    普通窗口
    创建人：    笨木头 (博客：http://www.benmutou.com)
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

	/* 设置窗口背景图片 */
    void setBG(const char* sPath);
    
private:
	/* 用一个精灵作为窗口的表现 */
    Sprite* m_sprite;
};

#endif