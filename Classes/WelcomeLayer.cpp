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
    Layer *backgroundLayer = LayerColor::create(Color4B(90, 191, 188, 255));
    backgroundLayer->setPosition(Point(origin.x, origin.y));
    backgroundLayer->setContentSize(Size(visiableSize.width, visiableSize.height));
    this->addChild(backgroundLayer);

    //draw title border
    auto draw = DrawNode::create();
    this->addChild(draw, 10);
    Vec2 points[] = {Vec2(visiableSize.width / 4, visiableSize.height / 12 * 9), Vec2(visiableSize.width / 4 * 3, visiableSize.height / 12 * 9), Vec2(visiableSize.width / 4 * 3, visiableSize.height / 12 * 8), Vec2(visiableSize.width / 4, visiableSize.height / 12 * 8)};
    draw->drawPolygon(points, sizeof(points)/sizeof(points[0]), Color4F(0,0,0,0), 1.5, Color4F::GRAY);
    
    //
    
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
    
    //Start button
    Sprite *startButton = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_play"));
    Sprite *activeStartButton = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_play"));
    activeStartButton->setPositionY(5);
    auto menuItem  = MenuItemSprite::create(startButton, activeStartButton, NULL, CC_CALLBACK_1(WelcomeLayer::menuStartCallback, this));
    menuItem->setPosition(Point(origin.x + visiableSize.width/2, origin.y + visiableSize.height * 2 / 5));
    auto menu = Menu::create(menuItem,NULL);
    menu->setPosition(Point(origin.x ,origin.y));
    this->addChild(menu);
    
    return true;
}

void WelcomeLayer::menuStartCallback(Object *sender) {
    auto scene = ArcadeScene::create();
    TransitionTurnOffTiles *transition = TransitionTurnOffTiles::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}
