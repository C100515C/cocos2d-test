/*
    文件名：    MMWinManager.h
    描　述：    控件顶层桌面
    创建人：    笨木头 (博客：http://www.benmutou.com)
*/
#ifndef __MM_DESKTOP_WIN_H__
#define __MM_DESKTOP_WIN_H__

#include "cocos2d.h"
#include "MMBase.h"

USING_NS_CC;

class MMDesktopWin : public MMBase {
public:
    MMDesktopWin();
    ~MMDesktopWin();

    CREATE_FUNC(MMDesktopWin);
    virtual bool init();

public:
    /* 添加一个控件 */
    void addWin(MMBase* mmWin);

    /* 根据ID获取控件 */
    MMBase* getWinByID(int ID);

    /* 删除所有控件 */
    void removeAllWins();
private:
    /* 存放所有控件的字典 */
    Map<int, MMBase*> mWinDict;
};

#endif