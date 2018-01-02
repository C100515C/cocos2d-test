#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "SecondSecne.hpp"
#include "MoveTest.hpp"

//#include "MMWinXmlData.h"
//#include "tinyxml.h"
//#include "MMWinXmlDataSetting.h"
//#include "MMBase.h"
//#include "MMNormalWin.h"
//#include "MMLabel.h"
//#include "MMWinManager.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    /* ¥¥Ω®øÿº˛ */
//    std::string spa = FileUtils::getInstance()->fullPathForFilename("test13_1.xml");
//    MMBase* win = MMWinManager::getInstance()->createWinsFromXML(spa.c_str());
//
//    /* Ω´∂•º∂◊¿√ÊÃÌº”µΩ≥°æ∞ */
//    this->addChild(MMWinManager::getInstance()->getDesktopWin());
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    m_titleSprite = Sprite::create("CloseSelected.png");
    m_titleSprite -> retain();
//
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    
//    Director::getInstance()->end();

//    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
    
//    Director::getInstance() -> replaceScene(SecondSecne::createScene());
    
//    Director::getInstance() -> replaceScene(TransitionProgressRadialCCW::create(2.0f, SecondSecne::createScene()));//动画切换场景会使旧场景释放，这是必要的因为场景可能占用很大内存
    
    //push 进来的场景 不会是旧场景释放 都会存在
//    Director :: getInstance() -> pushScene(SecondSecne::createScene());
    
//    Director :: getInstance() -> pushScene(MoveTest::createMoveTest());
    m_titleSprite->setPosition(200, 100);
//    this->addChild(m_titleSprite);
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
