//
//  XMLTest.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/10/27.
//

#include "XMLTest.hpp"
#include "tinyxml.h"
#include "XMLData.hpp"
#include "XMLDataSetting.hpp"
#include "MMLabel.hpp"
#include "MMNormalWin.hpp"
#include "MMWinManager.hpp"

bool XMLTest::init(){
    if (!Layer::init()) {
        return false;
    }
    
//    Size size = Director::getInstance() -> getVisibleSize();
//    Sprite *bg = Sprite ::create("ccback copy.png");
//    bg -> setPosition(size.width/2.0,size.height/2.0);
//    this -> addChild(bg);
    
//    std::string  path = FileUtils::getInstance() ->fullPathForFilename("test13_1.xml");
//    loadXmlText1(path.c_str());
//    loadXmlText2(path.c_str());
    /*
    TiXmlDocument *xmlDoc = new TiXmlDocument();
    //开始解析
    Data fileData = FileUtils::getInstance()->getDataFromFile(path);
    xmlDoc -> Parse((const char *)fileData.getBytes());
    TiXmlElement *root = xmlDoc->RootElement();
    
    //根据标签根节点 创建 XMLData 对象
    XMLData *xmlData = createXMLData(root->FirstChildElement());
    
    Node *win = createWins(xmlData);
    this -> addChild(win);
    
    delete xmlDoc;
    */
    
    //manager
    bool bRet = false;
    do{
        //创建控件
        MMBase *win = MMWinManager::getInstance()->createWinFromXmlData("test13_1.xml");
        this -> addChild(MMWinManager::getInstance()->getDeskTopWin());
        bRet = true;
        
    }while (0);
    
    
    return bRet;
}

Scene * XMLTest::createScene(){
    Scene *scene = Scene::create();
    XMLTest *layer = XMLTest::create();
    scene -> addChild(layer);
    
    return scene;
}

void XMLTest::loadXmlText1(const char *sPath){
    TiXmlDocument *xmlDoc = new TiXmlDocument();
    //读取 xml
    Data fileData = FileUtils::getInstance()->getDataFromFile(sPath);
    
    //开始解析
    xmlDoc -> Parse((const char*)fileData.getBytes());
    
    //获取xml 根节点
    TiXmlElement *rootElement = xmlDoc->RootElement();
    
    //开始读取xml 个个标签
    loadXmlEle(rootElement);
    
    //删除对象
    delete xmlDoc;
}

void XMLTest::loadXmlEle(TiXmlElement *rootElement){
   
    //取根节点的第一个子标签对象
    TiXmlElement *cldElement = rootElement ->FirstChildElement();
    
    //打印标签 名字和标签id属性
    log("%s  id=%s",cldElement->Value(),cldElement->Attribute("id"));
    
    //在取得标签的第一个子对象
    cldElement = cldElement ->FirstChildElement();
    //打印标签 名字和标签id属性
    log("%s:%s",cldElement->Value(),cldElement->GetText());
    
}

void XMLTest::loadXmlText2(const char *sPath){
    TiXmlDocument *doc = new TiXmlDocument();
    
    Data da = FileUtils::getInstance()->getDataFromFile(sPath);
    
    doc ->Parse((const char*)da.getBytes());
    
    TiXmlElement *root = doc->RootElement();
    
    loadXmlEleMMWin(root);
    
    delete doc;
}

void XMLTest::loadXmlEleMMWin(TiXmlElement *rootElement){
    TiXmlElement *element = rootElement->FirstChildElement();
    
    while (element!=NULL) {
        //某些 节点内容可能为空 所以不能获取它的内容 有的可能有
        if (element->GetText() != NULL) {
            log("%s:%s",element->Value(),element->GetText());
            
        }else if (element->FirstChildElement() !=NULL){//查看是否存在子节点
            loadXmlEleMMWin(element);
        }
        
        //下一个同级 节点
        element = element ->NextSiblingElement();
        
    }
    
}

void XMLTest::setWinXMLData(XMLData *xmlData, const char *sName, const char *sText ){
    //将复制 逻辑 单独 放到XMLDateSetting 中
    XMLDataSetting *setting = XMLDataSetting::create();
    setting -> setXmlData(xmlData, sName, sText);
    
    /*
    if (strcmp(sName, "enWinType")==0) {
        if (strcmp(sText, WinType_C_en_Win_None)==0) {
            xmlData ->setwinType(en_Win_None);
        }else if (strcmp(sText, WinType_C_en_Win_Label)==0){
            xmlData ->setwinType(en_Win_Label);

        }else if (strcmp(sText, WinType_C_en_Win_NormalWin)==0){
            xmlData ->setwinType(en_Win_Normal);

        }
        
    }else if (strcmp(sName, "x")==0){
        xmlData -> setiX(atoi(sText));
        
    }else if (strcmp(sName, "y")==0){
        xmlData -> setiY(atoi(sText));

    }*/
}

XMLData *XMLTest::createXMLData(TiXmlElement *xmlElement){
    XMLData *xmlData = NULL;//XMLData::create();
    
    TiXmlElement *cldElement = xmlElement->FirstChildElement();
    log("%s   %d ",__FILE__,__LINE__);
    
    //默认节点为空
    xmlData -> setNone(true);
    
    while (cldElement!=NULL) {
        
        //节点内容为空 所有不获取内容，但是他有子节点
        if (cldElement->GetText()!=NULL) {
            xmlData -> setNone(false);
            //节点赋值
            setWinXMLData(xmlData, cldElement->Value(), cldElement->GetText());
            log("%s   %d:[%s]-[%s] ",__FILE__,__LINE__,cldElement->Value(), cldElement->GetText());
            
        }else{
            
            //如果有子节点，继续解析并且添加到当前节点的子节点列表
            if (cldElement->FirstChildElement() != NULL) {
                xmlData ->addChildNodeXMLData(createXMLData(cldElement));
            }
        }
        
        //下一个同级节点
        cldElement = cldElement -> NextSiblingElement();
    }
    
    
    return xmlData;
}

Node * XMLTest::createWins(XMLData *xmlData){
    WinType enWinType = xmlData ->getwinType();
    Point point = Point(xmlData->getiX(), xmlData->getiY());
    
    //根据不同类型创建 控件
    Node *win = NULL;
    
    switch (enWinType) {
        case en_Win_Normal:
        {
//            win = Sprite::create("tollgateBG.jpg");
            win = MMWinNormal::create();
            ((MMWinNormal*)win) -> setBG("bg.jpg");
//            win -> setAnchorPoint(Point(0,0));
            win -> setPosition(point.x,point.y);
        }
            break;
        case en_Win_Label:
        {
//            win = Label::createWithSystemFont("label","Arial",35);
            win = MMLabel::create();
            ((MMLabel*)win) -> setsText("label");
//            win -> setAnchorPoint(Point(0,0));
            win -> setPosition(point.x,point.y);
        }
            break;
            
        default:
            break;
    }
    
    //创建控件
    if (win!=NULL&&xmlData->isHaveChild()) {
        auto childList = xmlData->getChildNodesList();
        for(auto xmlData:childList){
            win -> addChild(createWins(xmlData));
        }
    }
    
    return win;
}

