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

    /* ����Ѿ����ڸ�ID�Ŀؼ�,����ɾ�� */
    if(mWinDict.at(iWinID) != nullptr) {
        mWinDict.erase(iWinID);
    }

    /* ��ӿؼ����ֵ���,�������� */
    mWinDict.insert(iWinID, mmWin);
}


MMBase* MMDesktopWin::getWinByID( int ID ) {
    return mWinDict.at(ID);
}

void MMDesktopWin::removeAllWins() {
    mWinDict.clear();

    this->removeAllChildrenWithCleanup(true);
}