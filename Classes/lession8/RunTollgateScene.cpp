//
//  RunTollgateScene.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/24.
//
//

#include "RunTollgateScene.hpp"
#include "RunPlayer.hpp"
#include "SimpleMoveController.hpp"
#include "ThreeDirectionMoveController.hpp"

Scene * RunTollgateScene :: createScene(){
    Scene *scene = Scene::create();
    RunTollgateScene *layer = RunTollgateScene::create();
    scene -> addChild(layer);
    return scene;
}

bool RunTollgateScene::init(){
    if (!Layer::init()) {
        return false;
    }
    //加载Tiled地图，添加到场景中
    TMXTiledMap *map = TMXTiledMap::create("level01.tmx");
    map ->setPosition(0, -50);
    this -> addChild(map);
    
    //添加玩家
    addPlayer(map);
    
    Director ::getInstance()->setProjection(Director::Projection::_2D);
    
    return true;
}

void RunTollgateScene::addPlayer(cocos2d::TMXTiledMap *map){
//    Size size = Director::getInstance()->getVisibleSize();
    //加载对象层
    TMXObjectGroup *objectGroup = map->getObjectGroup("objects");
    //加载玩家坐标对象
    ValueMap valueMap = objectGroup->getObject("PlayerPoint");
    float x = valueMap.at("x").asFloat();
    float y = valueMap.at("y").asFloat();

    Sprite *sprite = Sprite::create("player.png");
    RunPlayer *player = RunPlayer ::create();
    player ->bindSprite(sprite);
    player ->setPosition(x, y);
    player -> bindMap(map);
    player ->run();
    
    map -> addChild(player);
    
    //创建玩家简单移动控制
//    SimpleMoveController *controller = SimpleMoveController::create();
//    controller->setSpeed(5);
//    this -> addChild(controller);
//    
//    player ->setController(controller);
    ThreeDirectionMoveController *controller = ThreeDirectionMoveController::create();
    controller ->setYSpeed(0);
    controller ->setXSpeed(1);
    this ->addChild(controller);
    player ->setController(controller);
}


