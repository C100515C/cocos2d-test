//
//  CsvUtil.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/8.
//
//

#ifndef CsvUtil_hpp
#define CsvUtil_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "CsvData.hpp"
#include "LT_stringUtil.hpp"

USING_NS_CC;

class CsvUtil:public Ref{
public:
    static CsvUtil *getIntance();
    virtual bool init();
    
    void laodFile(const char *sPath);
    Value getValue(int row,int col ,const char *csvPath);
    const std::string getString(int row,int col ,const char *csvPath);
    const int getInt(int row,int col ,const char *csvPath);
    const Size getFileRowColNum(const char *csvPath);
    
    const int findValueInWithLine(const char* chValue,int colNum,const char*csvPath);//根据列 值 查找所在行
private:
    static CsvUtil *m_share;
    Map<std::string, CsvData*> mCsvMap;//存放
    
};

#endif /* CsvUtil_hpp */
