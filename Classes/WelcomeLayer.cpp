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
    MyColor *color1 = new MyColor(userTheme, 0);
    log("%i,%i,%i",color1->getRed(), color1->getGreen(), color1->getBlue());
    LayerColor *colorBlock1 = LayerColor::create(Color4B(color1->getRed(), color1->getGreen(), color1->getBlue(), 255));
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
    
    MyColor *color2 = new MyColor(userTheme, 1);
    LayerColor *colorBlock2 = LayerColor::create(Color4B(color2->getRed(), color2->getGreen(), color2->getBlue(), 255));
    colorBlock2->setAnchorPoint(Point(0, 0));
    colorBlock2->setContentSize(Size(40, 40));
    colorBlock2->setPosition(Point(visiableSize.width / 2 - 150, visiableSize.height / 2 + 10));
    this->addChild(colorBlock2);
    this->labelItem2 = MenuItemLabel::create(LabelTTF::create("Aracde Mode", "Afonts/Marker Felt.ttf", 32), CC_CALLBACK_1(WelcomeLayer::menuNormalModeCallback, this));
    this->labelItem2->setAnchorPoint(Point(0, 0));
    this->labelItem2->setPosition(Point(visiableSize.width / 2 - 70, visiableSize.height / 2 + 10));
    auto menu2 = Menu::create(labelItem2, NULL);
    menu2->setPosition(0, 0);
    this->addChild(menu2);

    MyColor *color3 = new MyColor(userTheme, 2);
    LayerColor *colorBlock3 = LayerColor::create(Color4B(color3->getRed(), color3->getGreen(), color3->getBlue(), 255));
    colorBlock3->setAnchorPoint(Point(0, 0));
    colorBlock3->setContentSize(Size(40, 40));
    colorBlock3->setPosition(Point(visiableSize.width / 2 - 150, visiableSize.height / 2 - 70));
    this->addChild(colorBlock3);
    this->labelItem3 = MenuItemLabel::create(LabelTTF::create("Settings", "Afonts/Marker Felt.ttf", 32), CC_CALLBACK_1(WelcomeLayer::menuNormalModeCallback, this));
    this->labelItem3->setAnchorPoint(Point(0, 0));
    this->labelItem3->setPosition(Point(visiableSize.width / 2 - 70, visiableSize.height / 2 - 70));
    auto menu3 = Menu::create(labelItem3, NULL);
    menu3->setPosition(0, 0);
    this->addChild(menu3);

    MyColor *color4 = new MyColor(userTheme, 3);
    LayerColor *colorBlock4 = LayerColor::create(Color4B(color4->getRed(), color4->getGreen(), color4->getBlue(), 255));
    colorBlock4->setAnchorPoint(Point(0, 0));
    colorBlock4->setContentSize(Size(40, 40));
    colorBlock4->setPosition(Point(visiableSize.width / 2 - 150, visiableSize.height / 2 - 150));
    this->addChild(colorBlock4);
    this->labelItem4 = MenuItemLabel::create(LabelTTF::create("Theme", "Afonts/Marker Felt.ttf", 32), CC_CALLBACK_1(WelcomeLayer::menuNormalModeCallback, this));
    this->labelItem4->setAnchorPoint(Point(0, 0));
    this->labelItem4->setPosition(Point(visiableSize.width / 2 - 70, visiableSize.height / 2 - 150));
    auto menu4 = Menu::create(labelItem4, NULL);
    menu4->setPosition(0, 0);
    this->addChild(menu4);
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
    auto scene = NormalModeScene::create();
    TransitionTurnOffTiles *transition = TransitionTurnOffTiles::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}
