/*
    文件名：    MMLabel.h
    描　述：    标签控件
    创建人：    笨木头 (博客：http://www.benmutou.com)
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

	/* 设置标签内容 */
    void setsText(const char* sText);

	/* 设置标签内容，内容为数字 */
    void setsText(int iValue);

	/* 设置标签文字大小 */
    void setiFontSize(int iFontSize);

	/* 设置标签文字颜色 */
    void setColorRGB(int r, int g, int b);
private:
    Label* m_label;
};

#endif