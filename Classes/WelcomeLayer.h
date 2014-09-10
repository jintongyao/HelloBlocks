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
#include "TitleBorder.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

class WelcomeLayer : public Layer {
public:
    WelcomeLayer();
    ~WelcomeLayer();
    virtual bool init();
    CREATE_FUNC(WelcomeLayer);
    
private:
    void menuStartCallback(Object *sender);
};