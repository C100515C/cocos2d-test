#include "MMWinFactory.h"
#include "MMNormalWin.h"
#include "MMLabel.h"

bool MMWinFactory::init() {
    return true;
}

MMBase* MMWinFactory::createWin( EnumWinType enWinType ) {
    MMBase* win = NULL;
    switch(enWinType) {
    case en_Win_None:

        break;
	case en_Win_NormalWin:
		win = MMNormalWin::create();
		break;
	case en_Win_Label:
		win = MMLabel::create();
		break;
    }

    if(win != NULL) {
        win->setEnWinType(enWinType);
    }

    return win;
}