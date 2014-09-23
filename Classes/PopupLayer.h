//
//  PopupLayer.h
//  HelloBlocks
//
//  Created by JinTongyao on 9/22/14.
//
//

#pragma once
#include "cocos2d.h"
#include "Settings.h"
#include "NormalModeScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;

class PopupLayer : public LayerColor {
    
public:
    PopupLayer();
    ~PopupLayer();
    virtual bool init();
    CREATE_FUNC(PopupLayer);
    
private:
    LayerColor *menuLayer;
    void homeCallBack(Ref *sender);
    void resumeCallBack(Ref *sender);
    void restartCallBack(Ref *sender);
};