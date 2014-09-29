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
    static PopupLayer* createSuspendLayer(int gameType); //1-normalMode,2-GetTheOne
    static PopupLayer* createGameoverLayer(int gameType, int score); //1-normalMode,2-GetTheOne
    
private:
    LayerColor *menuLayer;
    void homeCallBack(Ref *sender);
    void resumeGetTheOne(Ref *sender);
    void resumeNormalMode(Ref *sender);
    void restartGetTheOne(Ref *sender);
    void restartNormalMode(Ref *sender);
    bool initSuspendLayer(int gameType);
    bool initGameoverLayer(int gameType, int score);
};
