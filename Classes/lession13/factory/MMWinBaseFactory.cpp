//
//  MMWinBaseFactory.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/3.
//

#include "MMWinBaseFactory.hpp"
#include "MMBase.hpp"
#include "MMWinManager.hpp"
#include "MMDeskTopWin.hpp"
#include "MMWinSystem.hpp"

//bool MMWinBaseFactory::init(){
//    return true;
//}

MMBase *MMWinBaseFactory::createWinByType(WinType enWinType){
    //从子类工厂 创建一个控件
    MMBase *mmWin = createWin(enWinType);
    
    //给控件设置一个id 大于0
    mmWin ->setID(MMWinManager::getInstance()->getWinSystem()->createUniqueID());
    
    //每个控件都要添加到 deskTop
    MMWinManager::getInstance()->getDeskTopWin()->addWin(mmWin);
    
    return mmWin;
}
