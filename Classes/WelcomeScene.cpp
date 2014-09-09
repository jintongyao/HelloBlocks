//
//  WelcomeScene.cpp
//  HelloBlocks
//
//  Created by JinTongyao on 8/27/14.
//
//

#include "WelcomeScene.h"

WelcomeScene::WelcomeScene() {};

WelcomeScene::~WelcomeScene() {};

bool WelcomeScene::init(){
    if (!Scene::init()) {
        return false;
    }else {
        auto welcomeLayer = WelcomeLayer::create();
        this->addChild(welcomeLayer);
        return true;
    }
}