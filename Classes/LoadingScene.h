//
//  LoadingScene.h
//  HelloBlocks
//
//  Created by JinTongyao on 8/29/14.
//
//
#pragma once

#include "cocos2d.h"
#include "WelcomeScene.h"
#include "AtlasLoader.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

class LoadingScene : public Scene {
public:
    virtual bool init();
    void onEnter() override;
    CREATE_FUNC(LoadingScene);
    
private:
    void loadingCallBack(Texture2D *texture);
};
