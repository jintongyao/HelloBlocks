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

using namespace cocos2d;

class LoadingScene : public Scene {
public:
    virtual bool init();
    void onEnter() override;//进入此场景时执行的方法
    CREATE_FUNC(LoadingScene);
    
private:
    void loadingCallBack(Texture2D *texture);
};
