#include "MMWinXmlDataSetting.h"

bool MMWinXmlDataSetting::init() {
	return true;
}

void MMWinXmlDataSetting::setXmlEnWinType( MMWinXmlData* xmlData,const char* sText ) {
	if(strcmp(sText, WINType_C_en_Win_None) == 0) {
		xmlData->setEnWinType(en_Win_None);
	}
	else if(strcmp(sText, WINType_C_en_Win_NormalWin) == 0) {
		xmlData->setEnWinType(en_Win_NormalWin);
	}
	else if(strcmp(sText, WINType_C_en_Win_Label) == 0) {
		xmlData->setEnWinType(en_Win_Label);
	}
}

void MMWinXmlDataSetting::setXmliX( MMWinXmlData* xmlData, const char* sText ) {
	xmlData->setiX(atoi(sText));
}

void MMWinXmlDataSetting::setXmliY( MMWinXmlData* xmlData, const char* sText ) {
	xmlData->setiY(atoi(sText));
}


void MMWinXmlDataSetting::setWinXmlData( MMWinXmlData* xmlData, const char* sName, const char* sText ) {
	if(strcmp(sName, XML_VALUE_enWinType) == 0) {
		setXmlEnWinType(xmlData, sText);
	}
	else if(strcmp(sName, XML_VALUE_x) == 0) {
		setXmliX(xmlData, sText);
	}
	else if(strcmp(sName, XML_VALUE_y) == 0) {
		setXmliY(xmlData, sText);
	}
}
