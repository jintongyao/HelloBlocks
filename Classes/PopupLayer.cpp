//
//  PopupLayer.cpp
//  HelloBlocks
//
//  Created by JinTongyao on 9/22/14.
//
//

#include "PopupLayer.h"

PopupLayer::PopupLayer(){}

PopupLayer::~PopupLayer(){}

PopupLayer* PopupLayer::createSuspendLayer(int gameType) {
    PopupLayer *layer = new PopupLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        layer->initSuspendLayer(gameType);
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return NULL;
}

PopupLayer* PopupLayer::createGameoverLayer(int gameType, int score) {
    PopupLayer *layer = new PopupLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        layer->initGameoverLayer(gameType, score);
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return NULL;
}

bool PopupLayer::initSuspendLayer(int gameType) {
    if(!LayerColor::initWithColor(Color4B(255, 255, 255, 120))) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //set menu layer properties
    switch (userTheme) {
        case PINK:
            menuLayer = LayerColor::create(Color4B(234, 97, 137, 255));
            break;
        case GRAY:
            menuLayer = LayerColor::create(Color4B(194, 194, 194, 255));
            break;
        case BLUE:
            menuLayer = LayerColor::create(Color4B(20, 142, 204, 255));
            break;
        case JELLY:
            menuLayer = LayerColor::create(Color4B(90, 191, 188, 255));
            break;
        case DARK:
            menuLayer = LayerColor::create(Color4B(50, 50, 50, 255));
            break;
        default:
            menuLayer = LayerColor::create(Color4B(20, 142, 204, 255));
            break;
    }
    menuLayer->setContentSize(Size(350, 200));
    menuLayer->ignoreAnchorPointForPosition(false);
    menuLayer->setAnchorPoint(Point(0.5, 0.5));
    menuLayer->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    
    //add label "suspend"
    auto *suspendLabel = Label::create("Suspend", "Futura.ttf", 30);
    suspendLabel->setPosition(Point(menuLayer->getContentSize().width / 2, menuLayer->getContentSize().height / 2 + 50));
    
    //add menus icons
    Sprite *homeButton = Sprite::create("home.png");
    Sprite *activeHomeButton = Sprite::create("home.png");
    activeHomeButton->setPositionY(5);
    auto homeMenuItem = MenuItemSprite::create(homeButton, activeHomeButton, NULL, CC_CALLBACK_1(PopupLayer::homeCallBack, this));
    homeMenuItem->setPosition(menuLayer->getContentSize().width / 2 - 100, menuLayer->getContentSize().height / 2 - 30);
    auto homeMenu = Menu::create(homeMenuItem, NULL);
    homeMenu->setPosition(Point(0, 0));
    Sprite *resumeButton = Sprite::create("start.png");
    Sprite *activeResumeButton = Sprite::create("start.png");
    activeResumeButton->setPositionY(5);
    MenuItemSprite *resumeMenuItem;
    if (gameType == 1) {
        resumeMenuItem = MenuItemSprite::create(resumeButton, activeResumeButton, NULL, CC_CALLBACK_1(PopupLayer::resumeNormalMode, this));
    }else {
        resumeMenuItem = MenuItemSprite::create(resumeButton, activeResumeButton, NULL, CC_CALLBACK_1(PopupLayer::resumeGetTheOne, this));
    }
    resumeMenuItem->setPosition(menuLayer->getContentSize().width / 2, menuLayer->getContentSize().height / 2 - 30);
    auto resumeMenu = Menu::create(resumeMenuItem, NULL);
    resumeMenu->setPosition(Point(0, 0));
    Sprite *restartButton = Sprite::create("restart.png");
    Sprite *activeRestartButton = Sprite::create("restart.png");
    activeRestartButton->setPositionY(5);
    MenuItemSprite *restartMenuItem;
    if (gameType == 1) {
        restartMenuItem = MenuItemSprite::create(restartButton, activeRestartButton, NULL, CC_CALLBACK_1(PopupLayer::restartNormalMode, this));
    }else{
        restartMenuItem = MenuItemSprite::create(restartButton, activeRestartButton, NULL, CC_CALLBACK_1(PopupLayer::restartGetTheOne, this));
    }
    restartMenuItem->setPosition(menuLayer->getContentSize().width / 2 + 100, menuLayer->getContentSize().height / 2 - 30);
    auto restartMenu = Menu::create(restartMenuItem, NULL);
    restartMenu->setPosition(Point(0, 0));
    
    //add shadow for menuLayer
    auto *shadowLayer = LayerColor::create(Color4B(100, 100, 100, 100));
    shadowLayer->setContentSize(Size(350, 200));
    shadowLayer->ignoreAnchorPointForPosition(false);
    shadowLayer->setAnchorPoint(Point(0.5, 0.5));
    shadowLayer->setPosition(Point(visibleSize.width / 2 + 8, visibleSize.height / 2 - 8));
    
    menuLayer->addChild(suspendLabel);
    menuLayer->addChild(homeMenu);
    menuLayer->addChild(resumeMenu);
    menuLayer->addChild(restartMenu);
    
    this->addChild(shadowLayer);
    this->addChild(menuLayer);
    
    //swallow touch
    auto callback = [](Touch * ,Event *) {
        return true;
    };
    
    //add event listener
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = callback;
    listener->setSwallowTouches(true);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    
    return true;
}

bool PopupLayer::initGameoverLayer(int gameType, int score) {
    if(!LayerColor::initWithColor(Color4B(255, 255, 255, 120))) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //set menu layer properties
    switch (userTheme) {
        case PINK:
            menuLayer = LayerColor::create(Color4B(234, 97, 137, 255));
            break;
        case GRAY:
            menuLayer = LayerColor::create(Color4B(194, 194, 194, 255));
            break;
        case BLUE:
            menuLayer = LayerColor::create(Color4B(20, 142, 204, 255));
            break;
        case JELLY:
            menuLayer = LayerColor::create(Color4B(90, 191, 188, 255));
            break;
        case DARK:
            menuLayer = LayerColor::create(Color4B(50, 50, 50, 255));
            break;
        default:
            menuLayer = LayerColor::create(Color4B(20, 142, 204, 255));
            break;
    }
    menuLayer->setContentSize(Size(350, 300));
    menuLayer->ignoreAnchorPointForPosition(false);
    menuLayer->setAnchorPoint(Point(0.5, 0.5));
    menuLayer->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    
    //add label "Game Over"
    auto *suspendLabel = Label::create("Game Over", "Futura.ttf", 30);
    suspendLabel->setPosition(Point(menuLayer->getContentSize().width / 2, menuLayer->getContentSize().height / 2 + 100));
    
    //add score
    auto scoreLabel = Label::create(CCString::createWithFormat("%d",score)->_string, "Futura.ttf", 70);
    scoreLabel->setAnchorPoint(Point(0.5, 0.5));
    scoreLabel->setPosition(Point(menuLayer->getContentSize().width / 2, menuLayer->getContentSize().height / 2));
    
    //add menus icons
    Sprite *homeButton = Sprite::create("home.png");
    Sprite *activeHomeButton = Sprite::create("home.png");
    activeHomeButton->setPositionY(5);
    auto homeMenuItem = MenuItemSprite::create(homeButton, activeHomeButton, NULL, CC_CALLBACK_1(PopupLayer::homeCallBack, this));
    homeMenuItem->setPosition(menuLayer->getContentSize().width / 2 - 50, menuLayer->getContentSize().height / 2 - 100);
    auto homeMenu = Menu::create(homeMenuItem, NULL);
    homeMenu->setPosition(Point(0, 0));
    Sprite *restartButton = Sprite::create("restart.png");
    Sprite *activeRestartButton = Sprite::create("restart.png");
    activeRestartButton->setPositionY(5);
    MenuItemSprite *restartMenuItem;
    if (gameType == 1) {
        restartMenuItem = MenuItemSprite::create(restartButton, activeRestartButton, NULL, CC_CALLBACK_1(PopupLayer::restartNormalMode, this));
    }else{
        restartMenuItem = MenuItemSprite::create(restartButton, activeRestartButton, NULL, CC_CALLBACK_1(PopupLayer::restartGetTheOne, this));
    }
    restartMenuItem->setPosition(menuLayer->getContentSize().width / 2 + 50, menuLayer->getContentSize().height / 2 - 100);
    auto restartMenu = Menu::create(restartMenuItem, NULL);
    restartMenu->setPosition(Point(0, 0));
    
    //add shadow for menuLayer
    auto *shadowLayer = LayerColor::create(Color4B(100, 100, 100, 100));
    shadowLayer->setContentSize(Size(350, 300));
    shadowLayer->ignoreAnchorPointForPosition(false);
    shadowLayer->setAnchorPoint(Point(0.5, 0.5));
    shadowLayer->setPosition(Point(visibleSize.width / 2 + 8, visibleSize.height / 2 - 8));
    
    menuLayer->addChild(suspendLabel);
    menuLayer->addChild(scoreLabel);
    menuLayer->addChild(homeMenu);
    menuLayer->addChild(restartMenu);
    
    this->addChild(shadowLayer);
    this->addChild(menuLayer);
    
    //swallow touch
    auto callback = [](Touch * ,Event *) {
        return true;
    };
    
    //add event listener
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = callback;
    listener->setSwallowTouches(true);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    
    return true;
}

bool PopupLayer::init() {
    if (!Layer::init()) {
        return false;
    }
    return true;
}

/**
 *  back to the welcome scene
 *
 *  @param sender
 */
void PopupLayer::homeCallBack(Ref *sender) {
    auto welcomeScene = WelcomeScene::create();
    TransitionTurnOffTiles *transition = TransitionTurnOffTiles::create(1, welcomeScene);
    Director::getInstance()->replaceScene(transition);
    //stop background music
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

/**
 *  resume to the game(normal mode)
 *  @param sender
 */
void PopupLayer::resumeNormalMode(Ref *sender) {
    this->removeFromParentAndCleanup(true);
}

/**
 *  resume to the game(Get The One)
 *  @param sender
 */
void PopupLayer::resumeGetTheOne(Ref *sender) {
    this->getParent()->schedule(schedule_selector(GetTheOneScene::flowTime), 1.0f, kRepeatForever, 0);
    this->removeFromParentAndCleanup(true);
}

/**
 *  restart the game
 *  @param sender
 */
void PopupLayer::restartNormalMode(Ref *sender) {
    auto normalModeSecne = NormalModeScene::create();
    TransitionSplitRows *transition = TransitionSplitRows::create(1, normalModeSecne);
    Director::getInstance()->replaceScene(transition);
}

void PopupLayer::restartGetTheOne(Ref *sender) {
    auto getTheOneScene = GetTheOneScene::create();
    TransitionSplitRows *transition = TransitionSplitRows::create(1, getTheOneScene);
    Director::getInstance()->replaceScene(transition);
}
