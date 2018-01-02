//
//  MutouTFSM.hpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/9.
//
//

#ifndef MutouTFSM_hpp
#define MutouTFSM_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class Mutou;
class MutouTFSM : public Node{
public:
    static MutouTFSM *createWithMutou(Mutou *mutou);
    bool initWithMutou(Mutou *mutou);
//
    virtual void update(float delate);
//    void changeState(I_stat);
    
};

#endif /* MutouTFSM_hpp */
