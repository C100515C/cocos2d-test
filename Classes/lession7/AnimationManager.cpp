//
//  AnimationManager.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/8/23.
//
//

#include "AnimationManager.hpp"

Animation * AnimationManager::createAnimateWithFrameName(const char *name, float delay, int iLoops){
    SpriteFrameCache *cache = SpriteFrameCache::getInstance();
//    cache ->addSpriteFramesWithFile(StringUtils::format("%s.plist",name), StringUtils::format("%s.png",name));
    
    Vector<SpriteFrame*> frames;
    SpriteFrame *frame = NULL;
    int index = 1;
    do{
        frame = cache->getSpriteFrameByName(StringUtils::format("%s%d.png",name,index++));
        if (frame==NULL) {
            break;
        }
        frames.pushBack(frame);
    }while(true);
    
    Animation *animation = Animation::createWithSpriteFrames(frames);
    animation->setLoops(iLoops);
    animation ->setDelayPerUnit(delay);
    
    return animation;

}

Animation *AnimationManager::createAnimateWithFrameNameAndNum(const char *name, int num, float delay, int iLoops){
    
    SpriteFrameCache *cache = SpriteFrameCache::getInstance();
//    cache ->addSpriteFramesWithFile(StringUtils::format("%s.plist",name), StringUtils::format("%s.png",name));
    
    Vector<SpriteFrame*> frames;
    SpriteFrame *frame = NULL;
//    int index = 1;

    for (int i=1; i<=num; i++) {
        frame = cache->getSpriteFrameByName(StringUtils::format("%s%d.png",name,i));
        if (frame==NULL) {
            break;
        }
        frames.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frames);
    animation->setLoops(iLoops);
    animation ->setDelayPerUnit(delay);
    
    return animation;
}
