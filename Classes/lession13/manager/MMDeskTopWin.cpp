//
//  MMDeskTopWin.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/3.
//

#include "MMDeskTopWin.hpp"

bool MMDeskTopWin::init(){
    return true;
}

MMDeskTopWin::MMDeskTopWin(){
    
}
MMDeskTopWin::~MMDeskTopWin(){
    
}

void MMDeskTopWin::addWin(MMBase *mmWin){
    assert(mmWin&&"addWin:MMBase *mmWin is NULL");
    int winID = mmWin->getID();
    
    //判断 控件是否存在 先移除
    if (mWinsDict.at(winID)!=NULL) {
        mWinsDict.erase(winID);
    }
    //添加 进去
    mWinsDict.insert(winID, mmWin);
}

MMBase *MMDeskTopWin::getWinByID(int id){
    return mWinsDict.at(id);
}

void MMDeskTopWin::removeAllWins(){
    mWinsDict.clear();
    
    this -> removeAllChildrenWithCleanup(true);
}
