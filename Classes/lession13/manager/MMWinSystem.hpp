//
//  MMWinSystem.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/3.
//

#ifndef MMWinSystem_hpp
#define MMWinSystem_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
#include "CommonDefine.h"

class MMBase;
class MMDeskTopWin;
class XMLData;
class MMWinBaseFactory;
class MMWinPropertyFactory;
class MMWinSystem:public Ref{
public:
//    CREATE_FUNC(MMWinSystem);
    virtual bool init(MMDeskTopWin* desktopWin);
    MMWinSystem();
    ~MMWinSystem();
    static MMWinSystem *create(MMDeskTopWin* deskTopWin);
    
    //根据 xml 数据创建控件   他可能创建很多个控件但是都会添加到父控件，只有一个最高的级的父控件
    MMBase *createWinsByXmlData(XMLData*xmlData,bool isHasParent);
    
    //根据控件类型给控件设置属性
    void dressPropertiesByType(MMBase*baseWin,XMLData *xmlData);
    
    //创建一个唯一id
    int createUniqueID();
    
private:
    MMDeskTopWin *mDeskTopWin;//桌面
    //控件工厂
    MMWinBaseFactory *mWinFactory;
    //控件添加属性工厂
    MMWinPropertyFactory *mWinPropertyFactory;
    //id
    int m_winID;
private:
    //根据数据创建一个控件
    MMBase *createWinByXmlData(XMLData *xmlData);
    //根据类型创建一个控件
    MMBase *createWinByType(WinType enWinType);

};
#endif /* MMWinSystem_hpp */
