//
//  SecondSecne.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/10.
//
//

#include "SecondSecne.hpp"
#include "MySprite.hpp"
//音乐播放库
#include "SimpleAudioEngine.h"
//九妹图 拉伸 属于 扩展库
#include "extensions/cocos-ext.h"
USING_NS_CC_EXT;


//
Scene * SecondSecne :: createScene(){

    auto scene = Scene::create();
    
    auto layer = SecondSecne::create();
    
    scene -> addChild(layer);
    
    return scene;
}

bool SecondSecne::init(){
    if (!Layer::init()) {
        return false;
    }
    
    Label *label = Label::createWithSystemFont("Hi,are you mutou?", "Arial", 25);
    label -> setPosition(200, 250);
    
    this -> addChild(label);
    
    /*
      添加 按钮返回  前一个场景
     */
    
    MenuItemImage *pClose = MenuItemImage :: create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_0(SecondSecne::popScene,this));
    
    pClose -> setPosition(300, 50);
    
    Menu *menu = Menu :: create(pClose, NULL);
    
    menu -> setPosition(0, 0);
    
    this -> addChild(menu,1);
    
    /**
    //添加精灵
//    MySprite *sprite = MySprite::createSprite();
//    sprite -> setName("CloseNormal.png");
//    sprite -> setColor(Color3B(200, 100, 33));
//    sprite  -> setPosition(100, 100);
    Sprite *sprite = Sprite::create("CloseNormal.png");
     sprite  -> setPosition(100, 100);
    this -> addChild(sprite);
    */
    
    /**
    //获取屏幕 大小
    Size screenSize = Director :: getInstance() -> getVisibleSize();
    
    //创建一个图片菜单项
    MenuItemImage *imageMenu = MenuItemImage :: create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_0(SecondSecne::menuClicked, this));
    //创建一个标签
    Label *label1 = Label :: createWithSystemFont("I am a label", "Arial", 18);
    
    //用标签对像创建一个菜单对象
    MenuItemLabel *menuLabel = MenuItemLabel :: create(label1);
    //创建菜单 菜单跟场景类似就是存放各种菜单项
    Menu *menu1 = Menu :: create(imageMenu,menuLabel, NULL);
    
    //让所有菜单项在菜单上自动垂直排列
    menu1 -> alignItemsVertically();
    
    //设置菜单坐标
    menu1 -> setPosition(screenSize.width/2.0, screenSize.height/2.0);
    
    this -> addChild(menu1,1);
    */
    
    /**
    //value  3.0 加入 各种值创建
    Value stringValue = Value("XiaoRou is ");
    Value intValue = Value(30);
    //as**函数获取值
    log("%s------%d",stringValue.asString().c_str(),intValue.asInt());
    
    //vector 队列
    Label * l1 = Label :: createWithSystemFont("cc1", "Arial", 20);
    l1 -> setPosition(50, 50);
    
    Label * l2 = Label :: createWithSystemFont("cc2", "Arial", 20);
    l2 -> setPosition(100, 50);
    
    //创建 vector
    Vector<Label*> vec;
    //把两个label 放入 vector中
    vec.pushBack(l2);
    vec.pushBack(l1);
    
    //遍历 vec 取出 label 添加到场景中
    for (auto la : vec) {
        this -> addChild(la);
    }
    
    //创建 map
    Map<int, Label*> testMap;
    //创建一百个 label  放入map中
    for (int i=0; i<100; i++) {
        //给label  起名字
        std::string name = "cc"+Value(i).asString();
        
        Label *la = Label :: createWithSystemFont(name.c_str(), "Arial", 10);
        //保存 label 到map 中，i作为key
        testMap.insert(i, la);
    }
    
    //取出 第二十个 label  添加到场景中
    Label *la = testMap.at(20);
    la -> setPosition(200,50);
    this -> addChild(la);
    */
    
    /**
    //播放音乐 只适合播放较长音乐
    CocosDenshion::SimpleAudioEngine::getInstance() ->playBackgroundMusic("sky_city.mp3",true);
    
    //播放 较短音乐
    CocosDenshion::SimpleAudioEngine::getInstance() ->playEffect("error.wav");
    */
    
    /**
    //九妹图  拉伸填充
    Scale9Sprite *nine = Scale9Sprite :: create("button.png");
    nine -> setContentSize(Size(200,200));
    nine -> cocos2d::Node::setPosition(280, 80);
    this -> addChild(nine,0);
    */
    
    /**
    //正常状态下的九妹图
    Scale9Sprite *normal = Scale9Sprite :: create("button.png");
    //高亮状态下图
    Scale9Sprite *select = Scale9Sprite :: create("buttonHighlighted.png");
    //按钮标题
    Label *title = Label :: createWithSystemFont("Touch", "Arial", 18);
    //创建按钮
    ControlButton *btn = ControlButton ::create(title, normal);
    
    //设置高亮图
    btn -> setBackgroundSpriteForState(select, Control::State::HIGH_LIGHTED);
    
    btn -> setPosition(300, 90);
    //强制设置按钮大小 但是当标题超过大小则自动放大  按钮大小跟标题适应
    btn -> setPreferredSize(Size(200,50));
    this -> addChild(btn);
    //*/
    
    /*  不好使
    //auto ui = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("MainScene.json");
   // ui -> cocos2d::Node::setPosition(100, 100);
    auto UI = CSLoader :: createNode("MainScene.csb");
    //auto rootNode =cocostudio::timeline::NodeReader::getInstance()->createNode("wzui_1/wzui_1.json");

    UI -> setPosition(-100, -250);
    this -> addChild(UI);
    
    Button *btn = (Button*)UI -> getChildByName("xiaorouBtn");
    img = (ImageView*) UI -> getChildByName("xiaoruoImage");
    
    //btn -> addTouchEventListener(this,toucheventselector(SecondSecne::hideTitle));
    btn -> addTouchEventListener(CC_CALLBACK_2(SecondSecne::hideTitle,this));
    */
    
    //血条
    auto ui = CSLoader ::createNode("MainScene2.csb");
    ui -> setPosition(-500, -10);
    this -> addChild(ui);
    /*
    //获得 控件 对象
    ImageView *back = (ImageView*)ui -> getChildByName("backImage");
    //back -> setTouchEnabled(true);
     hpBar = (LoadingBar*) back -> getChildByName("hpBar");
    hpBar -> setTouchEnabled(true);
    //添加监听事件
    hpBar -> addTouchEventListener(CC_CALLBACK_2(SecondSecne::changeLoadingBar , this));
    */
    
    return true;
}
void SecondSecne:: changeLoadingBar(Ref*r,Widget::TouchEventType tp){
    switch (tp) {
        case Widget::TouchEventType::MOVED:
        {
            hpBar -> setPercent(hpBar->getPercent()+1);
        }
            break;
            
        default:
            break;
    }
}


void SecondSecne :: hideTitle(Ref*r,Widget::TouchEventType tp){
    switch (tp) {
        case Widget::TouchEventType::BEGAN:
        
            break;
        case Widget::TouchEventType::MOVED:
            
            break;
        case Widget::TouchEventType::ENDED:
        {
            if (img  -> isVisible()) {
                img -> setVisible(false);
            }else{
                img -> setVisible(true);
            }
        }
            break;
        case Widget::TouchEventType::CANCELED:
            
            break;
        default:
            break;
    }
}

void SecondSecne :: popScene (){
    Director :: getInstance() -> popScene();
}

void SecondSecne :: menuClicked(){
//    Director :: getInstance() -> popScene();
    CocosDenshion::SimpleAudioEngine::getInstance() ->playEffect("error.wav");

}
