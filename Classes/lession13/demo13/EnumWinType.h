/*
    文件名：    EnumWinType.h
    描　述：    控件类型
    创建人：    笨木头 (博客：http://www.benmutou.com)
*/
#ifndef __ENUM_WIN_TYPE_H__
#define __ENUM_WIN_TYPE_H__

/* 控件类型字符串 */
#define WINType_C_en_Win_None           "MMNone"            // 无
#define WINType_C_en_Win_NormalWin		"MMNormalWin"		// 普通窗口
#define WINType_C_en_Win_Label			"MMLabel"			// 标签

enum EnumWinType {
    en_Win_None,
    en_Win_NormalWin,        /* 普通窗口 */
    en_Win_Label,            /* 普通标签 */
};

#endif
