//
//  LessionTenScene.cpp
//  Chapter2_4_HelloWorld
//
//  Created by chen chen on 2017/9/2.
//
//

#include "LessionTenScene.hpp"
#include "LT_stringUtil.hpp"
#include "CsvUtil.hpp"
#include "json.h"

Scene *LessionTen::createScene(){
    Scene *scene = Scene::create();
    LessionTen *layer = LessionTen::create();
    scene -> addChild(layer);
    return scene;
}

bool LessionTen::init(){
    if (!Layer::init()) {
        return false;
    }
    /*
    //保存角色名字
    UserDefault::getInstance() -> setStringForKey("name", "cc");
    
    //读取角色名字
    this -> scheduleOnce(schedule_selector(LessionTen::getStore), 3.0f);
    */
    /*
    //分割字符
    ValueVector list = LT_stringUtil::getIntance() -> split("dkd,dgd,hhh,33re,tyyyy", ",");
    
    for(auto value:list){
        log("%s\n",value.asString().c_str());
    }*/
    const char *path = "Monster";
    CsvUtil::getIntance()->laodFile(path);
    
    Value tt = CsvUtil::getIntance()->getValue(2, 2, path);
    int r = CsvUtil::getIntance()->findValueInWithLine("26", 2, path);
    
    log("*&%s===%d",tt.asString().c_str(),r);
    
    readJson();
    
    return true;
}

void LessionTen::getStore(float delay){
    std::string name = UserDefault::getInstance() -> getStringForKey("name","c");
    log("%s",name.c_str());
}

void LessionTen::readJson(){
    Json::Reader reader;
    Json::Value root;
    
    std::string jsonStr = FileUtils::getInstance()->getStringFromFile("JsonTest.json");
    
    if (reader.parse(jsonStr, root,false)==true) {
        log("%s",root["child"]["name"].asString().c_str());
    }
    
}
