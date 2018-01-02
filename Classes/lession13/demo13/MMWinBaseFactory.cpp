#include "MMWinBaseFactory.h"
#include "MMWinManager.h"

MMBase* MMWinBaseFactory::createWinByType( EnumWinType enWinType ) {
    /* 从子类件工厂创建一个控件 */
    MMBase* mmWin = createWin(enWinType);

    /* 给控件设置一个唯一ID(必须大于0) */
    mmWin->setID(MMWinManager::getInstance()->getWinSystem()->createUniqueID());

    /* 每一个控件都要添加到desktop中 */
    MMWinManager::getInstance()->getDesktopWin()->addWin(mmWin);

    return mmWin;
}