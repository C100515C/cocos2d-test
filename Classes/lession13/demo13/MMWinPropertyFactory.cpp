#include "MMWinPropertyFactory.h"
#include "MMNormalWin.h"
#include "MMLabel.h"

bool MMWinPropertyFactory::init() {
    return true;
}

void MMWinPropertyFactory::dressPropertiesByType( MMBase* mmWin, MMWinXmlData* xmlData ) {
    /* ���ݿؼ��������ö������� */
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

    /* ���û������� */
    dressBaseProperties(mmWin, xmlData);
}

void MMWinPropertyFactory::dressBaseProperties( MMBase* mmWin, MMWinXmlData* xmlData ) {
    /* ����и��ؼ�����ȡ���ؼ��Ŀ�� */
    MMBase* mmParent = NULL;
    if(mmWin->isHasParentWin()) {
        mmParent = (MMBase*)mmWin->getParent();
    }

    mmWin->setPositionX(xmlData->getiX());      // x����
    mmWin->setPositionY(xmlData->getiY());      // y����
}

void MMWinPropertyFactory::dressMMNormalWin( MMNormalWin* mmNormalWin, MMWinXmlData* xmlData ) {
	mmNormalWin->setBG("bg.jpg");
}

void MMWinPropertyFactory::dressMMLabel( MMLabel* mmLabel, MMWinXmlData* xmlData ) {
    mmLabel->setsText("Label Test!");
}
