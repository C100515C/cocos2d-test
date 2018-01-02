//
//  TowerPosEditorOperateLayer.cpp
//  Chapter2_4_HelloWorld-mobile
//
//  Created by CC on 2017/11/15.
//

#include "TowerPosEditorOperateLayer.hpp"
#include "TowerPosEditorLayer.hpp"
#include "PosBase.hpp"

TowerPosEditorOperateLayer ::TowerPosEditorOperateLayer(){}
TowerPosEditorOperateLayer :: ~TowerPosEditorOperateLayer(){}

bool TowerPosEditorOperateLayer::init(TowerPosEditorLayer *layer){
    if(!Layer::init()){
        return false;
    }
    this -> m_editorLayer = layer;
    
    //加载UI
    //弃用
//    std::string path = FileUtils::getInstance()->fullPathForFilename("EditorOperate_1.ExportJson");
//    auto ui = cocostudio::GUIReader::getInstance()->widgetFromJsonFile(path.c_str());
    auto ui = CSLoader ::createNode("lession_14_1.csb");

    this -> addChild(ui);
//    ui -> setTouchEnabled(true);
    //添加 监听事件//获取控件对象
    //保存坐标 文件
    Button *outputBtn = (Button*)ui->getChildByName("outputBtn");
    outputBtn -> addTouchEventListener(this,toucheventselector(TowerPosEditorOperateLayer::outputBtnClicked));
    
    //切换模式
    Button *changeBtn = (Button*)ui->getChildByName("exchangeBtn");
    changeBtn -> addTouchEventListener(this,toucheventselector(TowerPosEditorOperateLayer::changeBtnClicked));
    
    //切换关卡
    Button *next = (Button*)ui->getChildByName("nextLevel");
    next -> addTouchEventListener(this,toucheventselector(TowerPosEditorOperateLayer::next));
    Button *previous = (Button*)ui->getChildByName("previousLevel");
    previous -> addTouchEventListener(this,toucheventselector(TowerPosEditorOperateLayer::previous));
    
    return true;
}

TowerPosEditorOperateLayer * TowerPosEditorOperateLayer :: create(TowerPosEditorLayer *layer){
    
    TowerPosEditorOperateLayer *operate = new TowerPosEditorOperateLayer ();
    
    if(operate && operate->init(layer)){
        operate -> autorelease();
//        operate -> retain();
    }else{
        CC_SAFE_DELETE(operate);
    }
    
    return operate;
}

void TowerPosEditorOperateLayer::outputBtnClicked(Ref *ref,TouchEventType type){
    if (type == TouchEventType::TOUCH_EVENT_ENDED) {
        m_editorLayer -> outPutPosToPlistFile();
    }
}

void TowerPosEditorOperateLayer::changeBtnClicked(Ref *ref,TouchEventType type){
    if(type == TouchEventType::TOUCH_EVENT_ENDED){
        this ->m_editorLayer ->changeMode();
    }
}

void TowerPosEditorOperateLayer::next(Ref *ref,TouchEventType type){
    if(type == TouchEventType::TOUCH_EVENT_ENDED){
        this ->m_editorLayer -> nextLevel();
    }
}

void TowerPosEditorOperateLayer::previous(Ref *ref,TouchEventType type){
    if(type == TouchEventType::TOUCH_EVENT_ENDED){
        this ->m_editorLayer -> previousLevel();
    }
}

//重写 draw函数
void TowerPosEditorOperateLayer::draw(cocos2d::Renderer *renderer, const kmMat4 &transform, uint32_t transformUpdated){
    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(TowerPosEditorOperateLayer::onDraw, this,transform,transformUpdated);
    renderer->addCommand(&_customCommand);
}

void TowerPosEditorOperateLayer::onDraw(const kmMat4 &transform, bool transformUpdated){
    kmGLPushMatrix();
    kmGLLoadMatrix(&transform);
    PosBase *prePos = NULL;
    Vector<PosBase*> m_monsterPos = m_editorLayer->getMonstersPos();
    for(PosBase *basePos : m_monsterPos){
        if (prePos!=NULL) {
            DrawPrimitives::drawLine(prePos ->getPos(), basePos->getPos());
        }
        prePos = basePos;
    }
    
    kmGLPopMatrix();
}
