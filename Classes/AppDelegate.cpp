#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "MyHelloWorldScene.hpp"
#include "FirstGame.hpp"
#include "MyScene_7.hpp"
#include "RunTollgateScene.hpp"
#include "ScheduleLession.hpp"
#include "LessionTenScene.hpp"
#include "LessionElevenScene.hpp"
#include "HelloLua.hpp"
#include "XMLTest.hpp"
//#include "TowerPosEditorScene.hpp"
#include "SceneManager.hpp"

// #define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("Chapter2_4_HelloWorld", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("Chapter2_4_HelloWorld");
#endif
        glview -> setFrameSize(800, 480);
        director->setOpenGLView(glview);
        
    }
    glview ->setDesignResolutionSize(800, 480, ResolutionPolicy::SHOW_ALL);
    
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    auto frameSize = glview->getFrameSize();
    // if the frame's height is larger than the height of medium size.
    if (frameSize.height > mediumResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is larger than the height of small size.
    else if (frameSize.height > smallResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium size.
    else
    {        
        director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }

    register_all_packages();
    
    /*
    //以下就是如何进行适配的具体方法
    //getFrameSize()获得实际屏幕的大小
    Size ccsize = glview->getFrameSize();
    //这填写的就是一般你作为背景图片的那种图片的大小，适配的原理就是放到和缩小，而以什么为参照，当然就是
    //以最大的那张图片为参照，什么图片最大，当然是背景图片了，以后美工做图的时候用的就是以下的这个尺寸
    Size winSize= Size(480,320);
       //将宽和高做一个比，通过这个比，来具体的调整逻辑分辨率的大小
    
    float widthRate = ccsize.width/winSize.width;
    float heightRate = ccsize.height/winSize.height;
    
    //如果是if中的语句，说明逻辑的高度有点大了，就把逻辑的高缩小到和宽度一样的比率
    if (widthRate > heightRate)
    {
        //里边传入的前俩个参数就是逻辑分辨率的大小，也就是通过getWinSize()得到的大小
        glview->setDesignResolutionSize(winSize.width,
                                          winSize.height*heightRate/widthRate, kResolutionNoBorder);
    }
    else
    {
        glview->setDesignResolutionSize(winSize.width*widthRate/heightRate, winSize.height,
                                          kResolutionNoBorder);
    }*/


    // create a scene. it's an autorelease object
//    auto scene = HelloWorld::createScene();
//    auto scene = MyHelloWorldScene::createScene();
//    auto scene = FirstGame::createScene();
    
//    auto scene = MyScene_7::createScene();
//    auto scene = RunTollgateScene::createScene();
//    auto scene = ScheduleLession::createScene();
//    auto scene = LessionTen::createScene();
//    auto scene = LessionElevenScene::createScene();
//    auto scene = HelloLua::createScene();
//    auto scene = XMLTest::createScene();
//    auto scene = TowerPosEditorScene::createScene();
    // run
//    director->runWithScene(scene);
    SceneManager::getInstance()->changeScene(SceneManager::en_TollgateScene);
    
    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}
