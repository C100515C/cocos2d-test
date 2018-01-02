
//
//  CommonDefine.h
//  Chapter2_4_HelloWorld
//
//  Created by CC on 2017/11/1.
//

#ifndef CommonDefine_h
#define CommonDefine_h

//创建生成 varType类型 私有变量 并且生成 set  get 方法
#define CC_PRIVATE(varType,varName,funName)\
private:varType varName;\
public:varType get##funName(void) const{return varName;}\
public:void set##funName(varType var){varName = var;}\

//生成 bool 私有变量 并且生成 set  get 方法
#define CC_PRIVATE_BOOL(varName,funName)\
private:bool varName;\
public:bool is##funName(void) const{return varName;}\
public:void set##funName(bool var){varName = var;}\

//xml 文件节点名称
#define XML_VALUE_enWinType "enWinType"
#define XML_VALUE_x "x"
#define XML_VALUE_y "y"

//声明set方法
#define CC_XML_SET(funName)\
public:void setXml##funName(XMLData *xmlData,const char *sText);\

//xml 名称字符串
#define WinType_C_en_Win_None "MMNone" //无
#define WinType_C_en_Win_NormalWin "MMNormalWin" //普通窗口
#define WinType_C_en_Win_Label "MMLabel" //表签

typedef enum{
    en_Win_None,
    en_Win_Normal,
    en_Win_Label
} WinType;


#endif /* CommonDefine_h */
