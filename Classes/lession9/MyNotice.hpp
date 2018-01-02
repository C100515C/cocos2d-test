//
//  MyNotice.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/28.
//
//

#ifndef MyNotice_hpp
#define MyNotice_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class MyNotice : public Ref{
public:
    virtual bool init();
    CREATE_FUNC(MyNotice);

    static MyNotice* getInstance();
    
    //添加观察者
    void addOberver(const std::string &myName,std::function<void(Ref*)>func);
    //发送通知
    void postMessage(const std::string &myName,Ref *pData);
    
private:
    static MyNotice *m_no;
//    std::function<void(Ref*)>m_func;
    //存放 注册观察者的消息名字及对应观察者列表
    std::map<std::string, std::vector<std::function<void(Ref*)>>> m_funcMap;
};

#endif /* MyNotice_hpp */
