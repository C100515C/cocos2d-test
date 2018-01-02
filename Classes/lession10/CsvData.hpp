//
//  CsvData.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/3.
//
//

#ifndef CsvData_hpp
#define CsvData_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class CsvData:public Ref{
public:
    CREATE_FUNC(CsvData);
    virtual bool init();
    
    void addLineData(ValueVector lineData);//添加一行
    ValueVector getSingleLineData(int iLine);//获取某一行
    Size getRowColNum();//获取行列大小
private:
    ValueVector m_allLinesVec;//存放所有行数据
};

#endif /* CsvData_hpp */
