#include "MMDesktopWin.h"

MMDesktopWin::MMDesktopWin(){

}

MMDesktopWin::~MMDesktopWin() {
}

bool MMDesktopWin::init() {
    return true;
}

void MMDesktopWin::addWin( MMBase* mmWin ) {
    assert(mmWin && "addWin:mmWin is NULL!");

    int iWinID = mmWin->getID();

    /* 如果已经存在该ID的控件,则先删除 */
    if(mWinDict.at(iWinID) != nullptr) {
        mWinDict.erase(iWinID);
    }

    /* 添加控件到字典中,方便索引 */
    mWinDict.insert(iWinID, mmWin);
}


MMBase* MMDesktopWin::getWinByID( int ID ) {
    return mWinDict.at(ID);
}

void MMDesktopWin::removeAllWins() {
    mWinDict.clear();

    this->removeAllChildrenWithCleanup(true);
}