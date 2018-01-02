//
//  MoveTest.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/14.
//
//

#include "MoveTest.hpp"

Scene * MoveTest:: createMoveTest(){
    Scene *scene = Scene::create();
    MoveTest *layer = MoveTest::create();
    
    scene -> addChild(layer);
    
    return scene;
}
bool MoveTest:: init(){
    if (!Layer::init()) {
        return false;
    }
    
    MenuItemImage *imgItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_0(MoveTest::popBack, this));
    
    Menu *menu = Menu :: create(imgItem,NULL);
    menu ->setPosition(450, 40);
    this -> addChild(menu);
    
    /*
    //移动
    //获取当前 尺寸
    Size size = Director::getInstance() -> getVisibleSize();
    
    //创建 一个精灵
    Sprite *sprite = Sprite ::create("sprite.png");
    sprite -> setPosition(50, size.height/2.0);
    this -> addChild(sprite);
    
    //创建移动对象
    MoveTo *moveto = MoveTo ::create(0.9f, Point(250,150));
//    MoveBy *moveby = MoveBy ::create(0.9f, Point(250,150));
    
    //精灵之行 移动
    sprite -> runAction(moveto);
//    sprite -> runAction(moveby);

    //拉伸
    
    Sprite *scaleSp = Sprite :: create("sprite.png");
    scaleSp -> setPosition(size.width/2.0,size.height/2.0);
    this -> addChild(scaleSp);
    
    //拉伸
//    ScaleTo *scale = ScaleTo ::create(2.8f, 0.4f, 1.0f);
//    
//    scaleSp -> runAction(scale);
    
    //在原来倍数上 拉伸
    ScaleBy *scaleby = ScaleBy ::create(2.8f, 0.4f, 1.0f);
    
    scaleSp -> runAction(scaleby);
    */
    /*
    //闪烁
    Blink *blink1 = Blink ::create(2.0f, 5);
    Blink *blink2 = Blink ::create(3.0f, 5);

    z -> runAction(blink1);
    f -> runAction(blink2);*/
    /*
    //贝塞尔 曲线运动
    Sprite *mov = Sprite :: create("sprite.png");
    mov -> setPosition(50, 180);
    this -> addChild(mov);
    
    //贝塞尔 曲线配置
    ccBezierConfig beizer;
    beizer.controlPoint_1 = Point(100,0);
    beizer.controlPoint_2 = Point(200,250);
    beizer.endPosition = Point(300,0);
    
//    创建贝塞尔动作对象
//    BezierTo *be = BezierTo :: create(4.0f, beizer);
    BezierBy *be = BezierBy :: create(4.0f, beizer);

    mov -> runAction(be);*/
    /*
    //动作重复之行
    Sprite *sprite = Sprite :: create("sprite.png");
    sprite -> setPosition(50, 180);
    this -> addChild(sprite);
    
    //创建 jumpBy
    JumpBy *jum = JumpBy :: create(3.0f, Point(10,0),20, 1);
    
    //以jum 为参数创建永久重复动作对象
//    RepeatForever *rp = RepeatForever ::create(jum);
    //制定重复次数
    Repeat *rp = Repeat :: create(jum, 5);
    
    sprite -> runAction(rp);*/
    
    /*
     //多个动作 一同做
    Sprite *sprite = Sprite :: create("sprite.png");
    sprite -> setPosition(50, 50);
    this -> addChild(sprite);
    
    MoveTo *move = MoveTo::create(3.0f, Point(200,100));
    
    JumpBy *jum = JumpBy ::create(3.0f, Point(50,1), 100, 5);
    
    RotateTo *rotate = RotateTo::create(3.0f, 200, 10);
    //Spawn 是多个动作一起做  Sequence 是多个动作一个接着一个做
    Action *action = Spawn ::create(move,jum,rotate, NULL);
    
    sprite -> runAction(action);*/
    /*
    //动作监听
    //卡片翻转特效 scaleto 就可以实现
    Size size = Director::getInstance() -> getVisibleSize();
    
    Sprite *z = Sprite ::create("sprite.png");
    z -> setPosition(size.width/2.0,size.height/2.0);
    this -> addChild(z,1);
    
    MoveTo *move = MoveTo ::create(10.0f, Point(100,100));
    
    //回掉对象
    auto callBackFunc = [&](){
        moveEnd();
    };
    
    CallFunc *call = CallFunc ::create(callBackFunc);
    
    //两个动作组合
    Action *action = Sequence :: create(move, call,NULL);
    
    z -> runAction(action);
    */
    /*
    Sprite *f = Sprite ::create("xiaoruo.png");
    f -> setPosition(size.width/2.0, size.height/2.0);
    f -> setScale(0, 1);
    this -> addChild(f,0);
    
    //第一个精灵 拉伸直 x=0
    ScaleTo *hideFirst = ScaleTo :: create(2.0f, 0.0f,1.0f);
    // 创建动作监听
    auto callBack = [=](){
        ScaleTo *to = ScaleTo ::create(2.0f, 1.0f,1.0f);
        f -> runAction(to);
    };
    CallFunc *call = CallFunc :: create(callBack);
    Sequence *se = Sequence ::create(hideFirst,call, NULL);
    
    z -> runAction(se);
    
    auto listener = EventListenerTouchOneByOne::create();
    
    listener -> onTouchBegan = [](Touch *touch,Event *event){
        Point p1 = touch ->getLocation();//点击获取 坐标  3D
        Point p2 = touch ->getLocationInView();//点击获取坐标2D
        Point p3 = Director::getInstance() -> convertToGL(p2);//基于 2dx
        
        log("hello world onTouchBegan p1 x=%f ,y=%f ",p1.x,p1.y);
        log("hello world onTouchBegan p2 x=%f ,y=%f ",p2.x,p2.y);
        log("hello world onTouchBegan p3 x=%f ,y=%f ",p3.x,p3.y);

        
        return true;
        
    };
    
    listener -> onTouchMoved = [](Touch *touch,Event *event){
        log("hello world onTouchMoved ");

    };
    
    listener -> onTouchEnded = [](Touch *touch,Event *event){
        log("hello world onTouchEnded ");

    };
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    //_eventDispatcher 3.0 弃用
    dispatcher -> addEventListenerWithSceneGraphPriority(listener, this);
    */
    /*
    Size size = Director ::getInstance() -> getVisibleSize();
    Sprite *sp1 = Sprite :: create("sprite1.png");
    sp1 -> setPosition(size.width*0.5, size.height*0.5);
    this -> addChild(sp1);
    
    Sprite *sp2 = Sprite :: create("sprite2.png");
    sp2 -> setPosition(size.width*0.5, size.height*0.5);
    this -> addChild(sp2);
    
    auto listener = EventListenerTouchOneByOne :: create();
    listener -> onTouchBegan = [](Touch *touch,Event *event){
    
        //获取 注册监听事件时绑定的 node 对象
        auto target = static_cast<Sprite*>(event -> getCurrentTarget());
        
        Point point = Director ::getInstance() ->convertToGL(touch->getLocationInView());
        
        //判断点击位置是否在精灵范围内
        if (target->getBoundingBox().containsPoint(point)) {
            target -> setOpacity(100);
            return true;
        }
        
        
        return false;
    };
    
    listener ->onTouchEnded = [](Touch *touch,Event *event){
        //恢复透明度
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        target -> setOpacity(255);
    };
    //设置事件截获 当一个响应 后面的就不响应
    listener -> setSwallowTouches(true);
    
    //注册监听事件绑定 精灵 sp1
    auto ev = Director ::getInstance() -> getEventDispatcher();
    ev -> addEventListenerWithSceneGraphPriority(listener, sp1);
    
    //复制一个listener注册绑定 sp2
    ev ->addEventListenerWithSceneGraphPriority(listener->clone(), sp2);//
    */
     
    //多点触摸
    Size size = Director :: getInstance() -> getVisibleSize();
    Label *l1 = Label :: createWithSystemFont("cc1", "Arial", 15);
    l1 -> setPosition(size.width/2.0,size.height/2.0);
    this -> addChild(l1,1,1);
    
    Label *l2 = Label :: createWithSystemFont("cc2", "Arial", 15);
    l2 -> setPosition(size.width/2.0,size.height/2.5);
    this -> addChild(l2,1,2);
    
    Label *l3 = Label :: createWithSystemFont("cc3", "Arial", 15);
    l3 -> setPosition(size.width/2.0,size.height/3.0);
    this -> addChild(l3,1,3);
    
    auto listener = EventListenerTouchAllAtOnce ::create();
    
    listener -> onTouchesBegan = [&](const std::vector<Touch*>& touchs,Event *event){
        Label *l = (Label*) this -> getChildByTag(1);
        
        int num = (int) touchs.size();
        l -> setString(Value(num).asString()+"Touchs:");
    };
    
    listener -> onTouchesMoved = [&](const std::vector<Touch*>& touchs,Event *event){
        Label *l = (Label*) this -> getChildByTag(2);
        
        int num = (int) touchs.size();
        std:: string text = Value(num).asString()+"Touchs:";
        
        for(auto touch : touchs){
            auto location = touch -> getLocation();
            text += "[touchId"+Value(touch -> getID()).asString()+"],";
            
        }
        l -> setString(text);
    };
    
    listener->onTouchesEnded = [&](const std::vector<Touch*>& touches, Event  *event){
        auto logText = (Label*)this->getChildByTag(3);
        int num = (int) touches.size();
        logText->setString(Value(num).asString() + " Touches:");
        
    };
    
    auto e = Director::getInstance() -> getEventDispatcher();
    e -> addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void MoveTest::moveEnd(){
    Size size = Director::getInstance() -> getVisibleSize();

    Sprite *f = Sprite ::create("xiaoruo.png");
    
    f -> setPosition(size.width/2.0, size.height/2.0);
    this -> addChild(f);
}

void MoveTest::popBack(){
    Director :: getInstance() -> popScene();
}
                                                   
