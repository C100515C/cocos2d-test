//
//  MyNotice.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/28.
//
//

#include "MyNotice.hpp"

MyNotice * MyNotice::m_no = NULL;

MyNotice * MyNotice::getInstance(){
    if (m_no==NULL) {
        m_no = MyNotice::create();
        m_no ->retain();
    }
    
    return m_no;
}

bool MyNotice::init(){
    return true;
}

void MyNotice::addOberver(const std::string &myName, std::function<void (Ref *)> func){
    //查找是否存在 注册myName 的消息列表
    if (m_funcMap.find(myName) !=m_funcMap.end()) {
        //已经有人注册同样名字的
        std::vector<std::function<void(Ref*)>> funcs = m_funcMap.at(myName);
        //将新注册的添加进去
        funcs.push_back(func);
    }else{
        //不存在 该列表  新建一个
        std::vector<std::function<void(Ref*)>> funs;
        //函数添加进列表
        funs.push_back(func);
        
        //保存到 map
        m_funcMap[myName] = funs;
    }
}

void MyNotice::postMessage(const std::string &myName, cocos2d::Ref *pData){
    //查找是否存在 注册myName 的消息列表
    if (m_funcMap.find(myName) !=m_funcMap.end()) {
        //已经有人注册同样名字的
        std::vector<std::function<void(Ref*)>> funcs = m_funcMap.at(myName);
        for(auto func:funcs){
            func(pData);
        }
    }
}
