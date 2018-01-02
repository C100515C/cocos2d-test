//
//  HelloLua.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/10/25.
//

#include "HelloLua.hpp"

Scene *HelloLua :: createScene(){
    Scene *scene = Scene ::create();
    HelloLua *layer = HelloLua ::create();
    
    scene -> addChild(layer);
    
    return scene;
}

bool HelloLua::init(){
    
    if (!Layer::init()) {
        return false;
    }
    lua_State* pL = lua_open();
    luaopen_base(pL);
    luaopen_math(pL);
    luaopen_string(pL);
    
    //注册 c++ 函数
    lua_register(pL, "cpp_GetNumber", HelloLua::cpp_GetNumber);

    std::string path = FileUtils::getInstance()->fullPathForFilename("helloLua.lua");
    int err = luaL_dofile(pL, path.c_str());
    log("open : %d", err);
    
    /*
     //++++++++++++调用 lua  数据++++++//
     lua_State *pl = lua_open();//lua_State 表示lua 的一个身体，lua所有的执行都在这个lua_State结构体总
     //下面是加载一些lua的标准库
     luaopen_base(pl);
     luaopen_math(pl);
     luaopen_string(pl);
     
     //     1.执行lua脚本返回0表示成功
     int err = luaL_dofile(pl, path.c_str());
     
     log("open:%d",err);
     
     //     2.重置栈顶索引
     lua_settop(pl, 0);
     lua_getglobal(pl, "myName");
     
     //     3.判断栈顶值是否为string 返回非0 表示成功
     int isStr = lua_isstring(pl, 1);
     log("isStr:%d",isStr);
     
     //     4.获取栈顶值
     if (isStr!=0) {
     const char *str = lua_tostring(pl, 1);
     log("str=%s",str);
     }
     
     lua_close(pl);*/
    
    /*
     //++++++++++++调用 lua  数据++++++//
    lua_settop(pL, 0);
    lua_getglobal(pL, "myName");
    
    int isstr = lua_isstring(pL, 1);
    log("isstr = %d", isstr);
    
    if(isstr != 0) {
        const char* str = lua_tostring(pL, 1);
        log("getStr = %s", str);
    }
    lua_close(pL);*/
    
    lua_settop(pL, 0);//重置栈顶
    
    /*
     //++++++++++++调用 lua  table 数据++++++//
    lua_getglobal(pL, "helloTable");
    
    lua_pushstring(pL, "name");
    
    lua_gettable(pL, -2);
    
    int name = lua_isstring(pL, -1);
    if (name !=0) {
        const char *nameStr = lua_tostring(pL, -1);
        log("%s",nameStr);
    }*/
    
    //++++++++++++调用 lua  函数++++++//
    lua_getglobal(pL, "helloAdd");//将helloadd函数 名字放入栈顶 lua取栈顶helloAdd将helloAdd函数放入栈顶
    //将两个数字 分别放入栈顶
    lua_pushnumber(pL, 10);
    lua_pushnumber(pL, 5);
    
    //lua 分别取出栈顶两个数字执行韩式将返回值放入栈顶 第一个参数lua本身 第二参数表示 函数几个参数  第三个表示 函数返回值 是几个
    lua_call(pL, 2, 1);
    
    int res = lua_isnumber(pL, -1);//此时判断栈顶是否是数字，函数返回结果  返回不为0表示成功
    if (res != 0) {
        int result = lua_tonumber(pL, -1);//取出 结果
        log("res:%d",result);
    }
    
    lua_close(pL);
    
    return true;
}

int HelloLua::cpp_GetNumber(lua_State *pl){
    //从栈顶去一个值
    int num = (int )lua_tonumber(pl, -1);
    
    //调用getNumber函数 将值入栈
    lua_pushnumber(pl,HelloLua::getNumber(num));
    
    //返回 函数返回值个数  此函数为一个返回值所以 是1
    return 1;
}

int HelloLua::getNumber(int num){
    log("get num : %d",num);
    return num+1;
}
