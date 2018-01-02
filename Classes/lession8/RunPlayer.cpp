//
//  RunPlayer.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/24.
//
//

#include "RunPlayer.hpp"
#define SPACE 150//地图多出 黑框距离
#include "HelloWorldScene.h"

void RunPlayer::run(){
    SpriteFrameCache *cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("boys.plist", "boys.png");
    
    Vector<SpriteFrame *> frames;
    SpriteFrame *frame = NULL;
    int index = 1;
    do{
        frame = cache ->getSpriteFrameByName(StringUtils::format("run%d.png",index++));
        if (frame==NULL) {
            break;
        }
        frames.pushBack(frame);
    }while (true);
    
    Animation *animation = Animation::createWithSpriteFrames(frames);
    animation ->setLoops(-1);
    animation ->setDelayPerUnit(0.08f);
    
    Animate *animate = Animate::create(animation);
    
    Sprite *sprite = getSprite();
    
    sprite ->runAction(animate);
    
}

bool RunPlayer::init(){
    if (!RunEntity::init()) {
        return false;
    }
    isJumping = false;
    isRotate = false;
    return true;
}

void RunPlayer::bindMap(cocos2d::TMXTiledMap *map){
    this-> m_map = map;
    
    //将 meta 层 引用
    m_meta = m_map->getLayer("meta");
    m_meta ->setVisible(false);
}

void RunPlayer::setViewPointByPlyer(){
    
    if (getSprite()==NULL) {
        return;
    }
    
    Layer *parent = (Layer*)getParent();
    
    //获得地图 格子数量
    Size mapNum = m_map->getMapSize();
    
    //单个格子 大小
    Size tileSize = m_map ->getTileSize();
    
    //地图大小
    Size mapSize = Size(mapNum.width*tileSize.width/2.0,mapNum.height*tileSize.height/2.0);
    
    //获得屏幕大小
    Size size = Director::getInstance()->getVisibleSize();
    
    //主角坐标
    Point spritePos = getPosition();
    
    //如果主角的坐标小于屏幕的一半，则去屏幕中心，否则去主角坐标
    float x = MAX(spritePos.x, size.width/2.0);
    float y = MAX(spritePos.y, size.height/2.0);
    
    //如果 x y 坐标大于右上角极限则取极限值，目的是不让 地图超出屏幕 出现黑边
    x = MIN(x, mapSize.width-size.width/2.0-SPACE);
    y = MIN(y, mapSize.height-size.height/2.0-SPACE);
    
    //目标点
    Point destPos = Point(x,y);
    //屏幕 中心点
    Point centerPos = Point(size.width/2.0,size.height/2.0);
    
    //计算屏幕中心店 和 所要移动点之间的距离
    Point viewPos = centerPos - destPos;
    
    parent -> setPosition(viewPos.x, viewPos.y);
}

void RunPlayer::setTagPoint(float x, float y){
    //判断前面是否可以通行
    //取主角坐标
    Size spriteSize = getSprite()->getContentSize();
    Point player = Point(x+spriteSize.width/2.0,y);
    
    //获得当前主角方格子的坐标
    Point tilePoint = tileCoordForPostion(player);
    log("%f--%f",tilePoint.x,tilePoint.y);
    //获取格子的唯一标示
    int tileId = m_meta -> getTileGIDAt(Point(tilePoint.x,tilePoint.y));
    
    //tileId 不为0，代表这个格子存在
    if (tileId != 0) {
        //获取該格子的所有属性，目前我们的格子只有一个属性Collidable 属性；格子属于meta层，但同时也属于整个地图，所以获取格子的方法是通过 格子唯一标示  id
        Value  propertys = m_map->getPropertiesForGID(tileId);
        ValueMap property = propertys.asValueMap();
       //判断是否找到  Collidable
        if (property.find("Collidable")!=property.end()) {
            //获取格子的Collidable属性
            //判断属性是否为true
            Value prop = property.at("Collidable");
            if (prop.asString().compare("true")==0 && isJumping==false) {
                isJumping = true;
                
                auto jump = JumpBy::create(1.0f, Point(-150,0), 80, 1);
                auto call = [&](){
                    isJumping = false;
                };
                CallFunc *c = CallFunc::create(call);
                
                Action *action = Sequence::create(jump,c, NULL);
                this ->runAction(action);
                
            }
            
        }
        //获取food 属性
        if (property.find("food") !=property.end()) {
            Value food = property.at("food");
            if (food.asString().compare("true")==0) {
                //让各自从层上小时
                TMXLayer *barrier = m_map ->getLayer("barrier");
                barrier ->removeTileAt(tilePoint);
            }
            
        }
        
        //获取win 属性 判断 游戏 结束
        if (property.find("win") != property.end()) {
            Value win = property.at("win");
            if (win.asString().compare("true")==0) {
                //切换到胜利场景
                Director::getInstance()->replaceScene(HelloWorld::createScene());
            }
        }
        /*
        //获取 ccTest 属性 测试
        if (property.find("testcc") !=property.end()) {
            Value cctest = property.at("testcc");
            if (cctest.asString().compare("true")==0 && isRotate==false) {
                RotateBy *rotate = RotateBy::create(1.0f, 10, -10);
                isRotate = true;
                auto callback = [&](){
                    RotateBy *rotate1 = RotateBy::create(1.0f, -10, 10);
                    this -> runAction(rotate1);
                    isRotate = false;
                };
                CallFunc *call = CallFunc::create(callback);
                
                Action *action = Sequence::create(rotate, call,NULL);
                this -> runAction(action);
            };
        }*/
    
    }
    //
    RunEntity ::setTagPoint(x, y);
    
    //以主角为中心 移动地图
    setViewPointByPlyer();
    
}

Point RunPlayer::tileCoordForPostion(Point point){
    
    Size mapNum = m_map ->getMapSize();
    Size tileSize = m_map ->getTileSize();
    
    int x = point.x / tileSize.width*2;
    
    //2dx 中坐标 是 从下往上的 所以要减去
    int y = (700-point.y*2)/tileSize.height;
    
    //格子坐标从0 开始计算
    if (x>0) {
        x -= 1;
    }
    
    if (y>0) {
        y -= 0;
    }
    
    return Point(x,y);
}
