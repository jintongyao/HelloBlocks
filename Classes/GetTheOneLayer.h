//
//  GetTheOneLayer.h
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

class GetTheOneLayer : public Layer {
    GetTheOneLayer();
    ~GetTheOneLayer();
    CREATE_FUNC(GetTheOneLayer);
    GetTheOneLayer(int MatrixNum);
};