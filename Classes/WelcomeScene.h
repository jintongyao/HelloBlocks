//
//  WelcomeScene.h
//  HelloBlocks
//
//  Created by JinTongyao on 8/27/14.
//
//
#pragma once
#include "WelcomeLayer.h"
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

class WelcomeScene : public Scene{
public:
    WelcomeScene(void);
    ~WelcomeScene(void);
    bool virtual init();
    CREATE_FUNC(WelcomeScene);
};