//
//  LoadingScene.cpp
//  HelloBlocks
//
//  Created by JinTongyao on 8/29/14.
//
//

#include "LoadingScene.h"

using namespace cocos2d;

bool LoadingScene::init() {
    if(Scene::init()){
        return true;
    } else {
        return false;
    }
}

void LoadingScene::onEnter() {
    // add background to current scene
    Sprite *background = Sprite::create("lullaby.jpg");
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    background->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
    this->addChild(background);
    
    Director::getInstance()->getTextureCache()->addImageAsync("atlas.png", CC_CALLBACK_1(LoadingScene::loadingCallBack, this));
}

void LoadingScene::loadingCallBack(Texture2D *texture){
    AtlasLoader::getInstance()->loadAtlas("atlas.txt", texture);

    auto scene = WelcomeScene::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}

