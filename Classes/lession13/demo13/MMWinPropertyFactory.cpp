#include "MMWinPropertyFactory.h"
#include "MMNormalWin.h"
#include "MMLabel.h"

bool MMWinPropertyFactory::init() {
    return true;
}

void MMWinPropertyFactory::dressPropertiesByType( MMBase* mmWin, MMWinXmlData* xmlData ) {
    /* 根据控件类型设置独特属性 */
    switch(mmWin->getEnWinType()) {
    case en_Win_None:

        break;
	case en_Win_NormalWin:
		dressMMNormalWin((MMNormalWin*)mmWin, xmlData);
		break;
	case en_Win_Label:
		dressMMLabel((MMLabel*)mmWin, xmlData);
		break;
    }

    /* 设置基础属性 */
    dressBaseProperties(mmWin, xmlData);
}

void MMWinPropertyFactory::dressBaseProperties( MMBase* mmWin, MMWinXmlData* xmlData ) {
    /* 如果有父控件，则取父控件的宽高 */
    MMBase* mmParent = NULL;
    if(mmWin->isHasParentWin()) {
        mmParent = (MMBase*)mmWin->getParent();
    }

    mmWin->setPositionX(xmlData->getiX());      // x坐标
    mmWin->setPositionY(xmlData->getiY());      // y坐标
}

void MMWinPropertyFactory::dressMMNormalWin( MMNormalWin* mmNormalWin, MMWinXmlData* xmlData ) {
	mmNormalWin->setBG("bg.jpg");
}

void MMWinPropertyFactory::dressMMLabel( MMLabel* mmLabel, MMWinXmlData* xmlData ) {
    mmLabel->setsText("Label Test!");
}
