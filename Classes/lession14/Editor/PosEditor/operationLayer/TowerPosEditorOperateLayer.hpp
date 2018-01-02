//
//  TowerPosEditorOperateLayer.hpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/15.
//

#ifndef TowerPosEditorOperateLayer_hpp
#define TowerPosEditorOperateLayer_hpp

#include <stdio.h>

#include "cocos2d.h"
USING_NS_CC;

//cocostudio: GUIReader
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
using namespace cocostudio::timeline;
using namespace cocos2d::ui;
#include "extensions/cocos-ext.h"
USING_NS_CC_EXT;

class TowerPosEditorLayer;
class TowerPosEditorOperateLayer : public Layer{
public:
    TowerPosEditorOperateLayer();
    ~TowerPosEditorOperateLayer();
    
    static TowerPosEditorOperateLayer *create(TowerPosEditorLayer *layer);
    virtual bool init (TowerPosEditorLayer *layer);
    //重写draw函数
    virtual void draw(Renderer *renderer, const kmMat4 &transform,uint32_t transformUpdated);

private:
    /*编辑层*/
    TowerPosEditorLayer *m_editorLayer;
    void outputBtnClicked(Ref *ref,TouchEventType type);
    void changeBtnClicked(Ref *ref,TouchEventType type);
    void next(Ref *ref,TouchEventType type);
    void previous(Ref *ref,TouchEventType type);
    
    //绘制路线 怪物
    void onDraw(const kmMat4 &transform,bool transformUpdated);
    CustomCommand _customCommand;
};

#endif /* TowerPosEditorOperateLayer_hpp */
