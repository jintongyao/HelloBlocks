//
//  GetTheOneScene.cpp
//  HelloBlocks
//
//  Created by JinTongyao on 9/24/14.
//
//

#include "GetTheOneScene.h"

GetTheOneScene::GetTheOneScene(){}

GetTheOneScene::~GetTheOneScene(){}

int GetTheOneScore = 1;

bool GetTheOneScene::init() {
    if (!Scene::init() ) {
        return false;
    }
      
    //play background music
    SimpleAudioEngine::getInstance()->playBackgroundMusic("dream-as-memory.mp3", true);
    //create background layer and front layer
    Size visibleSize = Director::getInstance()->getVisibleSize(); 

    //set backgroundLayer
    switch (userTheme) {
        case PINK:
            backgroundLayer = LayerColor::create(Color4B(234, 97, 137, 255));
            break;
        case GRAY:
            backgroundLayer = LayerColor::create(Color4B(194, 194, 194, 255));
            break;
        case BLUE:
            backgroundLayer = LayerColor::create(Color4B(20, 142, 204, 255));
            break;
        case JELLY:
            backgroundLayer = LayerColor::create(Color4B(90, 191, 188, 255));
            break;
        case DARK:
            backgroundLayer = LayerColor::create(Color4B(50, 50, 50, 255));
            break;
        default:
            backgroundLayer = LayerColor::create(Color4B(20, 142, 204, 255));
            break;
    }
    //suspend button
    Sprite *suspendButton = Sprite::create("suspend.png");
    Sprite *activeSuspendButton = Sprite::create("suspend.png");
    activeSuspendButton->setPositionY(5);
    auto suspendMenuItem  = MenuItemSprite::create(suspendButton, activeSuspendButton, NULL, CC_CALLBACK_1(GetTheOneScene::suspendCallBack, this));
    suspendMenuItem->setPosition(backgroundLayer->getContentSize().width / 8, backgroundLayer->getContentSize().height - 50);
    auto suspendMenu = Menu::create(suspendMenuItem,NULL);
    suspendMenu->setPosition(Point(0 ,0));
    backgroundLayer->addChild(suspendMenu);
    //music button
    Sprite *musicButton = Sprite::create("musicon.png");
    Sprite *activeMusicButton = Sprite::create("musicon.png");
    activeMusicButton->setPositionY(5);
    auto musicMenuItem  = MenuItemSprite::create(musicButton, activeMusicButton, NULL, CC_CALLBACK_1(GetTheOneScene::suspendCallBack, this));
    musicMenuItem->setPosition(backgroundLayer->getContentSize().width / 8 + 80, backgroundLayer->getContentSize().height - 50);
    auto musicMenu = Menu::create(musicMenuItem,NULL);
    musicMenu->setPosition(Point(0 ,0));
    backgroundLayer->addChild(musicMenu);
    //rank label
    scoreLabel = Label::create(CCString::createWithFormat("%d",GetTheOneScore)->_string, "American Typewriter.ttf", 50);
    scoreLabel->setAnchorPoint(Point(0.5, 0.5));
    scoreLabel->setPosition(backgroundLayer->getContentSize().width / 2, visibleSize.width + 200);
    backgroundLayer->addChild(scoreLabel);
    //last time
    lastTimeLabel = Label::create(CCString::createWithFormat("%d",lastTime)->_string, "American Typewriter.ttf", 50);
    lastTimeLabel->setAnchorPoint(Point(0.5, 0.5));
    lastTimeLabel->setPosition(backgroundLayer->getContentSize().width / 2, 60);
    backgroundLayer->addChild(lastTimeLabel);
    
    //main layer
    auto mainLayer = GetTheOneLayer::createLayer(matrix);
    mainLayer->setContentSize(Size(visibleSize.width, visibleSize.width));
    mainLayer->setPosition(Point(0, 120));
    
    this->addChild(backgroundLayer);
    this->addChild(mainLayer);
    
    schedule(schedule_selector(GetTheOneScene::flowTime), 1.0f, kRepeatForever, 0);
    schedule(schedule_selector(GetTheOneScene::refreshScore), 0.3f, kRepeatForever, 0);
    
    return true;
}

void GetTheOneScene::suspendCallBack(Ref *sender) {
    auto *suspendLayer = PopupLayer::createSuspendLayer(2);
    this->unschedule(schedule_selector(GetTheOneScene::flowTime));
    this->addChild(suspendLayer);
}

void GetTheOneScene::flowTime(float dt) {
    if (lastTime > 0) {
        lastTime = --lastTime;
        lastTimeLabel->setString(CCString::createWithFormat("%d",lastTime)->_string);
    }else if (lastTime == 0){
        lastTime = --lastTime;
        auto *gameoverLayer = PopupLayer::createGameoverLayer(2, GetTheOneScore);
        this->addChild(gameoverLayer);
    }
}

void GetTheOneScene::refreshScore(float dt) {
    if (scoreLabel == nullptr) {
        scoreLabel = Label::create(CCString::createWithFormat("%d",GetTheOneScore)->_string, "American Typewriter.ttf", 50);
    }else {
        scoreLabel->setString(CCString::createWithFormat("%d",GetTheOneScore)->_string);
    }
}

