//
//  MMWinPropertyFactory.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/3.
//

#ifndef MMWinPropertyFactory_hpp
#define MMWinPropertyFactory_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class MMBase;
class XMLData;
class MMWinNormal;
class MMLabel;
class MMWinPropertyFactory:public Ref{
public:
    CREATE_FUNC(MMWinPropertyFactory);
    virtual bool init();
    
    //根据控件类型给控件设置属性
    void dressPropertiesByType(MMBase*baseWin,XMLData *xmlData);
private:
    //设置控件公共属性 所有控件必须设置
    void dressBaseProperties(MMBase*baseWin,XMLData *xmlData);
    
    void dressMMNormalWin(MMWinNormal *normalWin,XMLData *xmlData);
    void dressMMLabel(MMLabel *label,XMLData *xmlData);

};

#endif /* MMWinPropertyFactory_hpp */
