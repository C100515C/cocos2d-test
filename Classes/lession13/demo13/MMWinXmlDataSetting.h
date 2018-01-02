/*
    文件名：    MMWinXmlDataSetting.h
    描　述：    控件XML属性结构设置器
    创建人：    笨木头 (博客：http://www.benmutou.com)

    创建日期：   2012.12.12
*/
#ifndef __MM_WIN_XML_DATA_SETTING_H__
#define __MM_WIN_XML_DATA_SETTING_H__

/* XML文件的节点名称*/
#define XML_VALUE_enWinType "enWinType"     // 控件类型
#define XML_VALUE_x "x"                     // x坐标
#define XML_VALUE_y "y"                     // y坐标

#include "cocos2d.h"
#include "MMWinXmlData.h"

USING_NS_CC;

/* 普通set函数, 为了减少重复工作。例子:void setXmliX(MMWinXmlData* xmlData, const char* sText); */
#define MM_SET_XML(funName)\
public: void setXml##funName(MMWinXmlData* xmlData, const char* sText);

class MMWinXmlDataSetting : public Ref {
public:
    CREATE_FUNC(MMWinXmlDataSetting);
    virtual bool init();

    /* 给XML data对象赋值 */
    void setWinXmlData(MMWinXmlData* xmlData, const char* sName, const char* sText);
public:
    /* ------------- 根据xml中的节点字符串内容赋值 --------------- */
    MM_SET_XML(EnWinType);/* 设置控件类型 */
    MM_SET_XML(iX);/* 设置X坐标 */
    MM_SET_XML(iY);/* 设置Y坐标 */
};

#endif