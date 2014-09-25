//
//  GetTheOneScene.h
//  HelloBlocks
//
//  Created by JinTongyao on 9/24/14.
//
//

#pragma once
#include "cocos2d.h"
#include "Settings.h"
#include "BlockSprite.h"
#include "WelcomeScene.h"
#include "PopupLayer.h"
#include "SimpleAudioEngine.h"
#include "GetTheOneLayer.h"

using namespace cocos2d;

class GetTheOneScene : public Scene {
public:
    GetTheOneScene();
    ~GetTheOneScene(); 
    bool init();
    CREATE_FUNC(GetTheOneScene);

private:
    int rank = 1;
    int matrix = 2;
    int lastTime = 60;
    Label *lastTimeLabel;
    LayerColor *backgroundLayer;
    void suspendCallBack(Ref *sender);
    void flowTime(float dt);
};
