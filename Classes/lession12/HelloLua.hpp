//
//  HelloLua.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/10/25.
//

#ifndef HelloLua_hpp
#define HelloLua_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

extern "C"{
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
};

class HelloLua : public Layer{
public:
    CREATE_FUNC(HelloLua);
    virtual bool init();
    static Scene *createScene();
    
    static int getNumber(int num);
    static int cpp_GetNumber(lua_State *pl);
};

#endif /* HelloLua_hpp */
