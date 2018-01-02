//
//  CsvUtil.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/8.
//
//

#include "CsvUtil.hpp"

CsvUtil *CsvUtil::m_share = NULL;
bool CsvUtil::init(){
    
    return true;
}

CsvUtil *CsvUtil::getIntance(){
    if (m_share==NULL) {
        m_share = new CsvUtil();
        if (m_share &&m_share->init()) {
            m_share->autorelease();
            m_share->retain();
        }else{
            CC_SAFE_DELETE(m_share);
            m_share = NULL;
        }
    }
    return m_share;
}

void CsvUtil::laodFile(const char *sPath){
    //存放 csv 对象
    CsvData *csvData = CsvData::create();
    
    //将数据 一行一行保存 通过换行符 区分行
    std::string str = FileUtils::getInstance()->getStringFromFile(sPath);
    CCASSERT(str.c_str(), "csv配置文件为空");
    ValueVector lineList = LT_stringUtil::getIntance()->split(str.c_str(), "\n");
    
    //每一行 按逗号拆分
    for(auto value:lineList){
        ValueVector tArr = LT_stringUtil::getIntance()->split(value.asString().c_str(), ",");
        //添加到 csvData对象中
        csvData ->addLineData(tArr);

    }
    //添加列表到字典中
    mCsvMap.insert(sPath, csvData);
}

const Size CsvUtil::getFileRowColNum(const char *csvPath){
    //取出 csvData
    CsvData *csvData = mCsvMap.at(csvPath);
    
    //判断如果csvData对象不存在，先加载文件
    if (csvData==NULL) {
        this->laodFile(csvPath);
        csvData = mCsvMap.at(csvPath);
    }
    
    Size size = csvData->getRowColNum();
    
    return size;
}

Value CsvUtil::getValue(int row, int col, const char *csvPath){
    
    //取出 csvData
    CsvData *csvData = mCsvMap.at(csvPath);
    
    //判断如果csvData对象不存在，先加载文件
    if (csvData==NULL) {
        this->laodFile(csvPath);
        csvData = mCsvMap.at(csvPath);
    }
    
    ValueVector line = csvData->getSingleLineData(row);
    Value value = line.at(col);
    
    return value;
}

const std::string CsvUtil::getString(int row, int col, const char *csvPath){
    Value value = getValue(row, col, csvPath);
    return value.asString();
}

const int CsvUtil::getInt(int row, int col, const char *csvPath){
    Value value = getValue(row, col, csvPath);
    
    size_t d = value.asString().find("\"");
    size_t t = value.asString().find_last_of("\"");
    std::string tmpStr = value.asString();
    if (tmpStr.length()==0) {
        return -1;
    }
    if (d!= std::string::npos ) {
        tmpStr = tmpStr.substr(d+1,tmpStr.length());
    }
    if (t!=std::string::npos) {
        tmpStr = tmpStr.substr(0,t-1);
    }
    value = Value(tmpStr);
    
    return value.asInt();
}

const int CsvUtil::findValueInWithLine(const char *chValue, int colNum, const char *csvPath){
    //取出 csvData
    CsvData *csvData = mCsvMap.at(csvPath);
    
    //判断如果csvData对象不存在，先加载文件
    if (csvData==NULL) {
        this->laodFile(csvPath);
        csvData = mCsvMap.at(csvPath);
    }

    ValueVector tmp;
    Size size = csvData->getRowColNum();
    for (int i=0; i<size.width; i++) {
        ValueVector row = csvData->getSingleLineData(i);
        tmp.push_back(row.at(colNum));
    }
    int rt = -1;
    for (int i=0; i<tmp.size(); i++) {
        Value value = tmp.at(i);
        size_t d = value.asString().find("\"");
        size_t t = value.asString().find_last_of("\"");
        std::string tmpStr = value.asString();
        if (d==0&&t==tmpStr.length()-1) {
            tmpStr = tmpStr.substr(1,tmpStr.length()-2);
        }
        if (tmpStr.compare(Value(chValue).asString())==0) {
            rt = i;
            break;
        }
    }
    
    return rt;//返回-1 标示没找到
}


