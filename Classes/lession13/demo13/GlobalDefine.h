/*
    �ļ�����    GlobalDefine.h
    �衡����    ���õĺ궨��
    �����ˣ�    ��ľͷ (���ͣ�http://www.benmutou.com)
*/

#define CC_PRIVATE(varType, varName, funName)\
private: varType varName;\
public: varType get##funName(void) const { return varName; }\
public: void set##funName(varType var){ varName = var; }

/* ����bool˽�б���������get��set���� */
#define CC_PRIVATE_BOOL(varName, funName)\
private: bool varName;\
public: bool is##funName(void) const { return varName; }\
public: void set##funName(bool var){ varName = var; }