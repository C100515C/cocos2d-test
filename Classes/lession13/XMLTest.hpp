//
//  XMLTest.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/10/27.
//

#ifndef XMLTest_hpp
#define XMLTest_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class XMLData;
class TiXmlElement;
class XMLTest : public Layer{
public:
    virtual bool init();
    CREATE_FUNC(XMLTest);
    static Scene *createScene();
    
    //创建自定义表情 属性对象
    XMLData *createXMLData(TiXmlElement *xmlElement);
    
    //设置 某个具体的标签
    void setWinXMLData(XMLData* xmlData,const char *sName,const char *sText);
    
private:
    void loadXmlText1(const char *sPath);//xml 读取测试1 Hello TinyXml
    void loadXmlEle(TiXmlElement *rootElement);//读取xml普通文件
    
    void loadXmlText2(const char *sPath);
    void loadXmlEleMMWin(TiXmlElement *rootElement);
    
    //创建控件
    Node * createWins(XMLData*xmlData);

};

#endif /* XMLTest_hpp */
