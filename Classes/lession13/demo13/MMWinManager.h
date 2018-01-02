/*
    文件名：    MMWinManager.h
    描　述：    控件管理器
              主要负责控件操作的入口,加载XML创建控件等
    创建人：    笨木头 (博客：http://www.benmutou.com)
*/
#ifndef __MM_WIN_MANAGER_H__
#define __MM_WIN_MANAGER_H__

#include "cocos2d.h"
#include "MMDesktopWin.h"
#include "MMWinSystem.h"
#include "tinyxml.h"
#include "MMWinXmlData.h"
#include "MMWinXmlDataSetting.h"
#include "MMBase.h"
USING_NS_CC;

class MMWinManager : public Ref {
public:
    MMWinManager();
    ~MMWinManager();

    static MMWinManager* getInstance();
    virtual bool init();

    /* 获取桌面 */
    MMDesktopWin* getDesktopWin();

    /* 获取控件生成器 */
    MMWinSystem* getWinSystem();
public:
    /* 根据XML文件,创建控件 */
    MMBase* createWinsFromXML(const char* sXmlPath);
private:
    /* 读取XML元素,生成一个xml控件属性结构对象 */
    MMWinXmlData* createXmlData(TiXmlElement* xmlElement);

    /* 给XML data对象赋值 */
    void setWinXmlData(MMWinXmlData* xmlData, const char* sName, const char* sText);
private:
    static MMWinManager* mWinManager;

private:
    /* 控件顶级桌面 */
    MMDesktopWin* mDesktopWin;

    /* 控件生成器 */
    MMWinSystem* mWinSystem;

    /* xml属性结构设置器 */
    MMWinXmlDataSetting* mWinXmlDataSetting;
};

#endif
