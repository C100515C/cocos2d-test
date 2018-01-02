/*
    文件名：    MMWinSyetem.h
    描　述：    负责控件创建逻辑
    创建人：    笨木头 (博客：http://www.benmutou.com)
*/
#ifndef __MM_WIN_SYSTEM_H__
#define __MM_WIN_SYSTEM_H__

#include "cocos2d.h"
#include "MMBase.h"
#include "MMWinXmlData.h"
#include "EnumWinType.h"
#include "MMDesktopWin.h"
#include "MMWinBaseFactory.h"
#include "MMWinPropertyFactory.h"

USING_NS_CC;

class MMWinSystem : public Ref {
public:
    MMWinSystem();
    ~MMWinSystem();

    static MMWinSystem* create(MMDesktopWin* desktopWin);
    virtual bool init(MMDesktopWin* desktopWin);

    /*
        根据XML结构数据创建控件.
        它有可能创建很多个控件,但最终都会添加到一个父控件里.
        换句话说,xml文件里只允许出现一个最高父控件,不能出现同级别的父控件.
    */
    MMBase* createWinsByXmlData(MMWinXmlData* xmlData, bool isHasParent);

    /* 根据控件类型给控件设置属性(就像穿衣服一样) */
    void dressPropertiesByType(MMBase* mmWin, MMWinXmlData* xmlData);

    /* 创建一个唯一ID */
    int createUniqueID();
private:/* ---------- 属性 ---------- */

    /* 桌面 */
    MMDesktopWin* mDesktopWin;

    /* 控件工厂 */
    MMWinBaseFactory* mWinFactory;

    /* 控件属性加工厂 */
    MMWinPropertyFactory* mWinPropertyFactory;

    /* 控件ID */
    int m_iWinID;

private:/* ---------- 方法 ---------- */

    /* 根据XML结构数据创建一个控件 */
    MMBase* createWinByXmlData(MMWinXmlData* xmlData);

    /* 根据控件类型创建一个控件 */
    MMBase* createWinByType(EnumWinType enWinType);

};

#endif