//
//  CTOScene.h
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

using namespace cocos2d;

class CTOScene : public Scene {
    CTOScene();
    ~CTOScene();
    bool init();
    CREATE_FUNC(CTOScene);
};
