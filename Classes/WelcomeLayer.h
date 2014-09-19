//
//  WelcomeLayer.h
//  HelloBlocks
//
//  Created by JinTongyao on 8/30/14.
//
//
#pragma once
#include "cocos2d.h"
#include "AtlasLoader.h"
#include "ArcadeScene.h"
#include "SimpleAudioEngine.h"
#include "Settings.h"

using namespace cocos2d;
using namespace CocosDenshion;

class WelcomeLayer : public Layer {
public:
    WelcomeLayer();
    ~WelcomeLayer();
    virtual bool init();
    CREATE_FUNC(WelcomeLayer);
    LayerColor *backgroundLayer;
    
private:
    void menuNormalModeCallback(Object *sender);
    LayerColor *colorBlock1;
    MenuItemLabel *labelItem1;
};
