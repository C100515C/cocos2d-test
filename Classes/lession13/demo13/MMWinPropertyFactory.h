/*
    文件名：    MMWinPropertyFactory.h
    描　述：    控件属性加工厂 主要负责设置控件的属性
    创建人：    笨木头 (博客：http://www.benmutou.com)
*/
#ifndef __MM_WIN_PROPERTY_FACTORY_H__
#define __MM_WIN_PROPERTY_FACTORY_H__

#include "cocos2d.h"
#include "MMBase.h"
#include "EnumWinType.h"
#include "MMWinXmlData.h"
USING_NS_CC;

class MMNormalWin;
class MMLabel;
class MMWinPropertyFactory : public Ref {
public:
    CREATE_FUNC(MMWinPropertyFactory);
    virtual bool init();

public:
    /* 给控件设置属性(穿衣服~) */
    void dressPropertiesByType( MMBase* mmWin, MMWinXmlData* xmlData );

private:
    /* 设置控件公共属性,所有控件都必须设置 */
    void dressBaseProperties(MMBase* mmWin, MMWinXmlData* xmlData);

private:
	void dressMMNormalWin(MMNormalWin* mmNormalWin, MMWinXmlData* xmlData);
	void dressMMLabel(MMLabel* mmLabel, MMWinXmlData* xmlData);
};

#endif