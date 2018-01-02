//
//  MyScene_7.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/22.
//
//

#include "MyScene_7.hpp"
#include "SecondSecne.hpp"
#include "AnimationManager.hpp"

Scene *MyScene_7 :: createScene(){
    Scene *scene = Scene :: create();
    MyScene_7 *layer = MyScene_7 :: create();
 
    scene -> addChild(layer);
    return scene;
}

bool MyScene_7::init(){
    if (!Layer::init()) {
        return false;
    }
    /*
     auto batching
    //创建很多精灵
    for (int i=0; i<14100; i++) {
        Sprite *sprite0 = Sprite :: create("sprite0.png");
        sprite0 -> setPosition(CCRANDOM_0_1()*1134, CCRANDOM_0_1()*640);
        this -> addChild(sprite0);
        sprite0-> setGlobalZOrder(1);
        
        Sprite *sprite1 = Sprite :: create("sprite1.png");
        sprite1 -> setPosition(CCRANDOM_0_1()*1134, CCRANDOM_0_1()*640);
        this -> addChild(sprite1);
        sprite1 -> setGlobalZOrder(2);
    }*/
    /*
    // globalZOrder localZOrder orderOfArrival
    Sprite *sprite1 = Sprite :: create("sprite1.png");
    sprite1 -> setPosition(240, 160);
    this -> addChild(sprite1);
    
    Sprite *sprite2 = Sprite :: create("xiaoruo.png");
    sprite2 -> setPosition(200, 160);
    this -> addChild(sprite2);
    
    //localZOrder 代表 对象子节点在其上面 绘制 顺序
    sprite1 -> setLocalZOrder(2);
    sprite2 -> setLocalZOrder(1);
    //orderOfArrival 当localZOrder值相同时用其来调整绘制顺序 （orderOfArrival无需手动设置，当localZOrder相同 是按照add顺序自动在addChild方法中设置）
    
    SecondSecne *layer = SecondSecne ::create();
    this -> addChild(layer);
    //控制不同层 之间 子节点 顺序
    sprite1 -> setGlobalZOrder(2);*/
    
    /*
    //SpriteBatchNode
    SpriteBatchNode *manager = SpriteBatchNode::create("sprite.png");
    this -> addChild(manager);
    
    for (int i=0; i<999; i++) {
        Sprite *sp = Sprite :: create("sprite.png");
        sp -> setPosition(CCRANDOM_0_1()*300, CCRANDOM_0_1()*200);
        
        //将精灵添加到SpriteBatchNode 对象上
        manager -> addChild(sp);
    }*/
    
    /*
    //纹理Texture  可以理解为相同图片具有相同纹理
    Sprite *sprite1 = Sprite :: createWithSpriteFrame(SpriteFrame::create("sprite.png", Rect(0,0,60,50)));
    Sprite *sprite2 = Sprite ::create("sprite.png");
    
    sprite1 -> setPosition(100, 200);
    sprite2 -> setPosition(150, 200);
    this -> addChild(sprite1);
    this -> addChild(sprite2);
    
    Texture2D *t1 = sprite1 ->getTexture();
    Texture2D *t2 = sprite2 ->getTexture();*/
    
    /*
    Sprite *sprite1 = Sprite :: createWithSpriteFrame(SpriteFrame::create("girls.png", Rect(63,2,150,187)));
    sprite1 -> setPosition(100,200);
    this -> addChild(sprite1);
    
    Sprite *sprite2 = Sprite::createWithSpriteFrame(SpriteFrame ::create("girls.png", Rect(0,2,61,200)));
    sprite2 ->setPosition(250, 150);
    this -> addChild(sprite2);*/
    
    /*
    //将图片加入精灵帧缓存池
    SpriteFrameCache *cache = SpriteFrameCache::getInstance();
    cache ->addSpriteFramesWithFile("pics.plist", "pics.png");
    
    //用小图片名称创建图片精灵
    Sprite *xiaoruo = Sprite::createWithSpriteFrameName("xiaoruo.png");
    xiaoruo -> setPosition(100, 200);
    this ->addChild(xiaoruo);
    
    Sprite *sprite00 = Sprite ::createWithSpriteFrameName("sprite00.png");
    sprite00 ->setPosition(250, 200);
    this -> addChild(sprite00);*/
    
    //动画 animation
    Sprite *sprite = Sprite ::create("run1.png");
    sprite ->setPosition(250, 200);
    this -> addChild(sprite);
    
    SpriteFrameCache *cache = SpriteFrameCache ::getInstance();
    cache -> addSpriteFramesWithFile("boys.plist", "boys.png");
    Animate *ani = Animate::create(AnimationManager::createAnimateWithFrameNameAndNum("run", 15, 0.1f, -1));
//    Animate *ani = Animate::create(AnimationManager::createAnimateWithFrameName("run", 0.1f, -1));

    sprite ->runAction(ani);
    

//    sprite ->runAction(createAnimation1());
    
    return true;
    
}

Animate *MyScene_7::createAnimation(){

    int iFrameNum = 15;
    SpriteFrame *spriteFrame = NULL;
    Vector<SpriteFrame*> frames;
    
    for (int i=0; i<iFrameNum; i++) {
        spriteFrame = SpriteFrame::create(StringUtils::format("run%d.png",i+1), Rect(0,0,130,130));
        frames.pushBack(spriteFrame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frames);
    animation -> setLoops(-1);
    animation ->setDelayPerUnit(0.1f);
    
    //将动画打包成一个动作
    Animate *animate = Animate::create(animation);
    return animate;

}

Animate *MyScene_7::createAnimation1(){
    SpriteFrameCache *cache = SpriteFrameCache ::getInstance();
    cache -> addSpriteFramesWithFile("boys.plist", "boys.png");
    
    int iFrameNum = 15;
    SpriteFrame *spriteFrame = NULL;
    Vector<SpriteFrame*> frames;
    
    for (int i=0; i<iFrameNum; i++) {
        spriteFrame = cache->getSpriteFrameByName(StringUtils::format("run%d.png",i+1));
        frames.pushBack(spriteFrame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frames);
    animation -> setLoops(-1);
    animation ->setDelayPerUnit(0.1f);
    
    //将动画打包成一个动作
    Animate *animate = Animate::create(animation);
    return animate;

}
