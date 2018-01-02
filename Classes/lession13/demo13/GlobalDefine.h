/*
    文件名：    GlobalDefine.h
    描　述：    常用的宏定义
    创建人：    笨木头 (博客：http://www.benmutou.com)
*/

#define CC_PRIVATE(varType, varName, funName)\
private: varType varName;\
public: varType get##funName(void) const { return varName; }\
public: void set##funName(varType var){ varName = var; }

/* 创建bool私有变量，包括get和set方法 */
#define CC_PRIVATE_BOOL(varName, funName)\
private: bool varName;\
public: bool is##funName(void) const { return varName; }\
public: void set##funName(bool var){ varName = var; }