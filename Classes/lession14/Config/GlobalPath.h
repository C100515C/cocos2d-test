//
//  GlobalPath.h
//  Chapter2_4_HelloWorld
//
//  Created by CC on 2017/11/27.
//

#ifndef GlobalPath_h
#define GlobalPath_h

#define PATH_CSV_HERO_CONF "HeroG"//英雄 配置文件
#define PATH_CSV_MONSTER_CONF "MonsterG"//怪物配置文件
#define PATH_BULLET_NOR ""//子弹 文件
#define PATH_I18N_PUBLIC ""//语言文件 公共
#define PATH_FONT_PUBLIC ""//文字字体
#define PATH_PUBLIC "public"//

//pist 文件 头拼写
#define PATH_TOWERPOS_PLIST_HEADER "towerPos_level_%d.plist"
#define PATH_MONSTERPOS_PLIST_HEADER "monsterPos_level_%d.plist"
#define PATH_MONSTER_PLIST_HEADER "monster_level_%d.plist"

//图片 文件名头
#define PATH_BORDER_PIC_HEADER "border_%d.png"
#define PATH_BORDER_MAGIC_PIC_HEADER "magic_border_%d.png"
#define PATH_HERO_PIC_HEADER "hero_%d.png"
#define PATH_MONSTER_PIC_HEADER "monster_%d.png"

//手机存储 document 路径
#define DOCUMENT_PATH(c_path)({\
std::string define_pathToSave=FileUtils::getInstance()->getWritablePath();\
c_path = define_pathToSave+c_path;\
(c_path);\
})\


#endif /* GlobalPath_h */
