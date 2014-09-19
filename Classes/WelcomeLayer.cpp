//
//  WelcomeLayer.cpp
//  HelloBlocks
//
//  Created by JinTongyao on 8/30/14.
//
//

#include "WelcomeLayer.h"

WelcomeLayer::WelcomeLayer() {}

WelcomeLayer::~WelcomeLayer() {}

bool WelcomeLayer::init() {
    if (!Layer::init()) {
        return false;
    }
    
    Size visiableSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    //set title
//    auto *titleBorder = TitleBorder::create();
//    titleBorder->setPosition(100,100);
    
    //set background
    switch (userTheme) {
        case theme::PINK:
            backgroundLayer = LayerColor::create(Color4B(234, 97, 137, 255));
            break;
        case theme::GRAY:
            backgroundLayer = LayerColor::create(Color4B(194, 194, 194, 255));
            break;
        case theme::BLUE:
            backgroundLayer = LayerColor::create(Color4B(20, 142, 204, 255));
            break;
        case theme::JELLY:
            backgroundLayer = LayerColor::create(Color4B(90, 191, 188, 255));
            break;
        case theme::DARK:
            backgroundLayer = LayerColor::create(Color4B(50, 50, 50, 255));
            break;
        default:
            backgroundLayer = LayerColor::create(Color4B(20, 142, 204, 255));
            break;
    }
    backgroundLayer->setPosition(Point(origin.x, origin.y));
    backgroundLayer->setContentSize(Size(visiableSize.width, visiableSize.height));
    this->addChild(backgroundLayer);

    //draw title border
    //auto draw = drawnode::create();
    //this->addchild(draw, 10);
    //vec2 points[] = {vec2(visiablesize.width / 4, visiablesize.height / 12 * 9), vec2(visiablesize.width / 4 * 3, visiablesize.height / 12 * 9), vec2(visiablesize.width / 4 * 3, visiablesize.height / 12 * 8), vec2(visiablesize.width / 4, visiablesize.height / 12 * 8)};
    //draw->drawpolygon(points, sizeof(points)/sizeof(points[0]), color4f(0,0,0,0), 1.5, color4f::gray);
    
//    //set title
//    auto *titleBorder = TitleBorder::create();
//    titleBorder->setPosition(100,100);
//    addChild(titleBorder,5);
    
//    Label *helloTitle = Label::create();
//    helloTitle->setString("Hello Block");
//    helloTitle->setPosition(Point(titleSpriteSize.width / 2, titleSpriteSize.height / 2));
//
//    titleSprite->addChild(helloTitle);
//    backgroundLayer->addChild(titleSprite);
    
    //menus
    //Normal Mode
    LayerColor *colorBlock1 = LayerColor::create(Color4B(255, 134, 154, 255));
    colorBlock1->setAnchorPoint(Point(0, 0));
    colorBlock1->setContentSize(Size(40, 40));
    colorBlock1->setPosition(Point(visiableSize.width / 2 - 150, visiableSize.height / 2 + 90));
    this->addChild(colorBlock1);
    this->labelItem1 = MenuItemLabel::create(LabelTTF::create("Normal Mode", "Afonts/Marker Felt.ttf", 32), CC_CALLBACK_1(WelcomeLayer::menuNormalModeCallback, this));
    this->labelItem1->setAnchorPoint(Point(0, 0));
    this->labelItem1->setPosition(Point(visiableSize.width / 2 - 70, visiableSize.height / 2 + 90));
    auto menu1 = Menu::create(labelItem1, NULL);
    menu1->setPosition(0, 0);
    this->addChild(menu1);
    
    //LayerColor *colorBlock2 = LayerColor::create(Color4B(255, 134, 154, 255));
    //colorBlock1->setAnchorPoint(Point(0, 0));
    //colorBlock1->setContentSize(Size(40, 40));
    //colorBlock1->setPosition(Point(visiableSize.width / 2 - 150, visiableSize.height / 2 + 90));
    //this->addChild(colorBlock1);
    //this->labelItem1 = MenuItemLabel::create(LabelTTF::create("Normal Mode", "Afonts/Marker Felt.ttf", 32), CC_CALLBACK_1(WelcomeLayer::menuNormalModeCallback, this));
    //this->labelItem1->setAnchorPoint(Point(0, 0));
    //this->labelItem1->setPosition(Point(visiableSize.width / 2 - 70, visiableSize.height / 2 + 90));
    //auto menu1 = Menu::create(labelItem1, NULL);
    //menu1->setPosition(0, 0);
    //this->addChild(menu1);
    
    //Start button
    //Sprite *startButton = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_play"));
    //Sprite *activeStartButton = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_play"));
    //activeStartButton->setPositionY(5);
    //auto menuItem  = MenuItemSprite::create(startButton, activeStartButton, NULL, CC_CALLBACK_1(WelcomeLayer::menuStartCallback, this));
    //menuItem->setPosition(Point(origin.x + visiableSize.width/2, origin.y + visiableSize.height * 2 / 5));
    //auto menu = Menu::create(menuItem,NULL);
    //menu->setPosition(Point(origin.x ,origin.y));
    //this->addChild(menu);
    
    return true;
}


void WelcomeLayer::menuNormalModeCallback(Object *sender) {
    this->labelItem1->runAction(ScaleTo::create(1.1, 1.1));
    auto scene = ArcadeScene::create();
    TransitionTurnOffTiles *transition = TransitionTurnOffTiles::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}

