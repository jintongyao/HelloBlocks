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

bool PopupLayer::init() {
    if(!LayerColor::initWithColor(Color4B(255, 255, 255, 120))) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    //front layer
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
    
    //add menus icons
    Sprite *homeButton = Sprite::create("home-1.png");
    Sprite *activeHomeButton = Sprite::create("home-1.png");
    activeHomeButton->setPositionY(5);
    auto homeMenuItem  = MenuItemSprite::create(homeButton, activeHomeButton, NULL, CC_CALLBACK_1(PopupLayer::homeCallBack, this));
    homeMenuItem->setPosition(menuLayer->getContentSize().width / 2 - 100, menuLayer->getContentSize().height / 2);
    auto homeMenu = Menu::create(homeMenuItem,NULL);
    homeMenu->setPosition(Point(0 ,0));
    menuLayer->addChild(homeMenu);
    
    Sprite *resumeButton = Sprite::create("start.png");
    Sprite *activeResumeButton = Sprite::create("start.png");
    activeResumeButton->setPositionY(5);
    auto resumeMenuItem  = MenuItemSprite::create(resumeButton, activeResumeButton, NULL, CC_CALLBACK_1(PopupLayer::resumeCallBack, this));
    resumeMenuItem->setPosition(menuLayer->getContentSize().width / 2, menuLayer->getContentSize().height / 2);
    auto resumeMenu = Menu::create(resumeMenuItem,NULL);
    resumeMenu->setPosition(Point(0 ,0));
    menuLayer->addChild(resumeMenu);
    
    Sprite *restartButton = Sprite::create("restart.png");
    Sprite *activeRestartButton = Sprite::create("restart.png");
    activeRestartButton->setPositionY(5);
    auto restartMenuItem  = MenuItemSprite::create(restartButton, activeRestartButton, NULL, CC_CALLBACK_1(PopupLayer::homeCallBack, this));
    restartMenuItem->setPosition(menuLayer->getContentSize().width / 2 + 100, menuLayer->getContentSize().height / 2);
    auto restartMenu = Menu::create(restartMenuItem,NULL);
    restartMenu->setPosition(Point(0 ,0));
    menuLayer->addChild(restartMenu);
    
    //add shadow for menuLayer
    auto *shadowLayer = LayerColor::create(Color4B(100, 100, 100, 100));
    shadowLayer->setContentSize(Size(350, 200));
    shadowLayer->ignoreAnchorPointForPosition(false);
    shadowLayer->setAnchorPoint(Point(0.5, 0.5));
    shadowLayer->setPosition(Point(visibleSize.width / 2 + 8, visibleSize.height / 2 - 8));
    
    this->addChild(shadowLayer);
    this->addChild(menuLayer);
    
    auto callback = [](Touch * ,Event *) {
        return true;
    };
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = callback;
    listener->setSwallowTouches(true);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    
    return true;
}

/**
 *  back to the welcome scene
 *
 *  @param sender
 */
void PopupLayer::homeCallBack(Object *sender) {
    auto welcomeScene = WelcomeScene::create();
    TransitionTurnOffTiles *transition = TransitionTurnOffTiles::create(1, welcomeScene);
    Director::getInstance()->replaceScene(transition);
    //stop background music
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

/**
 *  resume to the game
 *  @param sender
 */
void PopupLayer::resumeCallBack(Object *sender) {
    this->removeFromParentAndCleanup(true);
}
