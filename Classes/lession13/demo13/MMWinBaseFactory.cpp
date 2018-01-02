#include "MMWinBaseFactory.h"
#include "MMWinManager.h"

MMBase* MMWinBaseFactory::createWinByType( EnumWinType enWinType ) {
    /* ���������������һ���ؼ� */
    MMBase* mmWin = createWin(enWinType);

    /* ���ؼ�����һ��ΨһID(�������0) */
    mmWin->setID(MMWinManager::getInstance()->getWinSystem()->createUniqueID());

    /* ÿһ���ؼ���Ҫ��ӵ�desktop�� */
    MMWinManager::getInstance()->getDesktopWin()->addWin(mmWin);

    return mmWin;
}