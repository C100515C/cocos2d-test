//
//  TollgateScene.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/19.
//
//

#include "TollgateScene.hpp"
#include "Player.hpp"
#include "MonsterManager.hpp"

#define SPACE 55

Scene * TollgateScene :: createScene(){
    Scene *scene  = Scene :: create();
    
    TollgateScene *layer = TollgateScene ::create();

    scene -> addChild(layer);
    
    return scene;
}

bool TollgateScene :: init(){
    if (!Layer::init()) {
        return false;
    }
    
    Size size = Director :: getInstance() ->getVisibleSize();
    
    //游戏标题图片
    Sprite *titleSprite = Sprite :: create("title.png");
    titleSprite ->setPosition(size.width/2.0, size.height-50);
    this -> addChild(titleSprite,2);
    
    //创建主角
    m_player = Player :: create();
    m_player -> bindSprite(Sprite::create("sprite.png"));
    m_player -> setPosition(200,size.height/4.0);
    this -> addChild(m_player,3);
    
    //初始化 背景图
    initBG();

    loadUI();
    
    this -> scheduleUpdate();//开启 更新方法
    
    MonsterManager *monsterManager = MonsterManager ::create();
    this -> addChild(monsterManager,4);
    monsterManager ->bindPlayer(m_player);
    
    
    return true;
}

void TollgateScene::loadUI(){
    //跳跃 按钮
    auto ui = CSLoader::createNode("MainScene_Game.csb");
    ui -> setPosition(-700, 30);
    this -> addChild(ui);
    
    Button *btn = (Button*) ui -> getChildByName("jumpBtn");
    btn -> addTouchEventListener(CC_CALLBACK_2(TollgateScene::jumpEvent, this));
    
    //记分板 血条
    auto message = CSLoader :: createNode("MainScene_gg.csb");
    message -> setPosition(-10,30);
    this -> addChild(message);
    
    Text *score = (Text*)message -> getChildByName("scoreLabel");
    m_scoreLab = score;
    
    ImageView *background = (ImageView*)message -> getChildByName("background");
    m_hpPropress = (LoadingBar*)background -> getChildByName("hpPropress");
    
    
}

void TollgateScene::jumpEvent(Ref *ref, Widget::TouchEventType type){
    switch (type) {
        case Widget::TouchEventType::ENDED:
        {
            m_player -> jump();
        }
            break;
            
        default:
            break;
    }
    
}

void TollgateScene::initBG(){
    Size size = Director ::getInstance() -> getVisibleSize();
    
    m_bgSprite1 = Sprite ::create("tollgateBG.jpg");
    m_bgSprite1 -> setPosition(size.width/2.0-SPACE,size.height/2.0);
    this -> addChild(m_bgSprite1,0);
    
    Size contentSize = m_bgSprite1-> getContentSize();
    
    m_bgSprite2 = Sprite :: create("tollgateBG.jpg");
    m_bgSprite2 -> setPosition(contentSize.width+size.width/2.0-SPACE, size.height/2.0);
    m_bgSprite2 ->setFlippedX(true);//水平翻转 精灵
    this -> addChild(m_bgSprite2,0);
    
    m_bgSprite3 = Sprite :: create("tollgateBG.jpg");
    m_bgSprite3 -> setPosition(2*contentSize.width+size.width/2.0-SPACE, size.height/2.0);
//    m_bgSprite3 ->setFlippedX(true);//水平翻转 精灵
    this -> addChild(m_bgSprite3,0);
}


void TollgateScene::update(float delta){
    
    int px1 = m_bgSprite1 -> getPositionX();
    int px2 = m_bgSprite2 -> getPositionX();
    int px3 = m_bgSprite3 -> getPositionX();

    int speed = 1;
    
    px1 -= speed;
    px2 -= speed;
    px3 -= speed;
    
    //地图大小
    Size contentSize = m_bgSprite1-> getContentSize();
    
    if (px1 <= -(contentSize.width/2.0)) {
        px1 = 2*contentSize.width +contentSize.width/2.0-SPACE;
    }
    
    if (px2 <= -(contentSize.width/2.0)) {
        px2 = 2*contentSize.width+contentSize.width/2.0-SPACE;
    }
    
    if (px3 <= -(contentSize.width/2.0)) {
        px3 = 2*contentSize.width+contentSize.width/2.0-SPACE;

    }
    
    m_bgSprite1 -> setPositionX(px1);
    m_bgSprite2 -> setPositionX(px2);
    m_bgSprite3 -> setPositionX(px3);
    
    m_score += 1;
    m_scoreLab -> setString(Value(m_score).asString());
    float s = m_player->getHP()/1000.0*100;
    m_hpPropress -> setPercent(s);
}
