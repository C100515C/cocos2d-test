//
//  MMWinManager.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/2.
//

#ifndef MMWinManager_hpp
#define MMWinManager_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
#include "MMWinSystem.hpp"
#include "MMDeskTopWin.hpp"

class XMLData;
class MMBase;
//class MMDeskTopWin;
//class MMWinSystem;
class TiXmlElement;
class XMLDataSetting;

class MMWinManager : public Ref{
public:
    MMWinManager();
    ~MMWinManager();
    static MMWinManager *getInstance();
    virtual bool init();
    
    //获取桌面
    MMDeskTopWin *getDeskTopWin();
    
    //获取控件生成器
    MMWinSystem *getWinSystem();
    
public:
    //根据xml 文件，创建控件
    MMBase *createWinFromXmlData(const char *sName);
    
private:
    //读取xml元素，生成xml控件结构属性对象
    XMLData *createXmlData(TiXmlElement*xmlElement);
    //为xmldata 对象赋值
    void setWinXmlData(XMLData*xmlData,const char *sName,const char *sText);
    
private:
    static MMWinManager *mWinManager;
    
private:
    //控件顶级桌面
    MMDeskTopWin *mDeskTopWin;
    //控件生成
    MMWinSystem *mWinSystem;
    //xml 属性结构设置器
    XMLDataSetting *mXMLDataSetting;
};

#endif /* MMWinManager_hpp */
