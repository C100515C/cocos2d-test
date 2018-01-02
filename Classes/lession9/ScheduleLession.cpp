//
//  ScheduleLession.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/27.
//
//

#include "ScheduleLession.hpp"
//#include "OtherLayer.hpp"
#include "MyNotice.hpp"

Scene *ScheduleLession::createScene(){
    Scene *scene = Scene::create();
    ScheduleLession *layer = ScheduleLession::create();
    scene ->addChild(layer);
    
//    OtherLayer *otherLayer = OtherLayer::create();
//    scene ->addChild(otherLayer);
    
    return scene;
}

bool ScheduleLession::init(){
    if (!Layer::init()) {
        return false;
    }
//    Size size = Director ::getInstance() ->getOpenGLView()->getFrameSize();
//    Size size = Director ::getInstance()->getWinSize();
    Size size = Director ::getInstance()->getVisibleSize();

    Label *title = Label::createWithSystemFont("Lession9", "Arial", 20);
    title ->setPosition(size.width/2.0, size.height);
    this ->addChild(title);
    /*
    this -> scheduleUpdate();//开启定时器 系统默认调用 update函数
    
    this -> schedule(schedule_selector(ScheduleLession::myUpdate));
    this -> schedule(schedule_selector(ScheduleLession::myUpdate), 2.0f);//第一个参数是 执行函数  第二个参数是 多久执行一次
    
    this -> scheduleOnce(schedule_selector(ScheduleLession::myCallBack), 2.0);//执行一次  2秒后执行
    
    this -> unscheduleAllCallbacks();//取消所有 update函数 调用

//    初始化
    m_fCountTime = 0;
    m_fTotalTime = 0;
//    每隔一秒 执行一次
    this -> schedule(schedule_selector(ScheduleLession::countTime), 1.0f);
//    定时器 越走 越慢 存在时间差 因为不知道在哪一个时刻有耗时操作
    */
    
    //添加 自己制作的计时器
//    m_timerCounter = TimerCounter::create();
//    this ->addChild(m_timerCounter);
    /*
    //开始计时
    m_timerCounter ->startTime();
    
    this ->schedule(schedule_selector(ScheduleLession::logic), 1.0f);
    this ->schedule(schedule_selector(ScheduleLession::doSomething));*/
    
//    m_timerCounter -> startTime(5.0f, [&](){
//        Label *title1 = Label::createWithSystemFont("Lession9 lllllll", "Arial", 20);
//        title1 ->setPosition(200,100);
//        this ->addChild(title1);
//    });
    
    //观察者
    //添加观察者
//    NotificationCenter::getInstance() ->addObserver(this, callfuncO_selector(ScheduleLession::getMsg), "test", NULL);
    
    //自定义通知中心
    MyNotice::getInstance()->addOberver("ccTest", [](Ref*){
        log("我的 通知中心");
    
    });
    this -> scheduleOnce(schedule_selector(ScheduleLession::sendMsg), 3);

    
    return true;
}

void ScheduleLession::logic(float dt){
    log("%f",m_timerCounter ->getCurrentTime());
}

void ScheduleLession::doSomething(float dt){
    //模拟游戏耗时操作
    for (int i=0; i<9999999; i++) {
        ;
    }
}

void ScheduleLession::update(float delate){

    //模拟游戏耗时操作
    for (int i=0; i<9999999; i++) {
        ;
    }
//    log("update  %f",delate);

//    this -> unscheduleUpdate();//取消系统默认 update

}

void ScheduleLession::myUpdate(float delate){
    log("my update  %f",delate);
    this -> unschedule(schedule_selector(ScheduleLession::myUpdate));//取消自定义 update 

}

void ScheduleLession::myCallBack(float delay){
    log("2 delay");
}

void ScheduleLession::countTime(float dt){
    m_fCountTime += 1;
    m_fTotalTime += dt;

    log("total = %f   ****   count = %f",m_fTotalTime,m_fCountTime);
}

void ScheduleLession::sendMsg(float dt){
    log("send");
//    NotificationCenter::getInstance() ->postNotification("test",NULL);
    
    MyNotice::getInstance()->postMessage("ccTest", NULL);
}

//void ScheduleLession::getMsg(Ref *pSender){
//    log("get");
//}
