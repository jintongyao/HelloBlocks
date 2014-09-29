//
//  GetTheOneLayer.cpp
//  HelloBlocks
//
//  Created by JinTongyao on 9/24/14.
//
//

#include "GetTheOneLayer.h"
GetTheOneLayer::GetTheOneLayer(){};
    
GetTheOneLayer::~GetTheOneLayer(){};

bool GetTheOneLayer::init() {
    if (!Layer::init()) {
        return false;
    }
    return true;
}

GetTheOneLayer* GetTheOneLayer::createLayer(int matrix) {
    GetTheOneLayer *layer = new GetTheOneLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        layer->layerInit(matrix);
    return layer;
    }
    CC_SAFE_DELETE(layer);
    return NULL;
}

void GetTheOneLayer::layerInit(int matrix) {
    srand((unsigned)time(NULL));//add random seed
    int line = this->getContentSize().width / matrix;
    int ranX = rand() % matrix;
    int ranY = rand() % matrix;
    int ranColor = rand() % 5;
    int ranRed = rand() % 225 + 15;
    int ranGreen = rand() % 225 + 15;
    int ranBlue = rand() % 225 + 15;
    //log("rgb is %i , %i , %i", ranRed, ranGreen, ranBlue);
    for(int i = 0; i < matrix; i++) {
        for(int j = 0; j < matrix; j++) {
            if(i == ranX && j == ranY) {
                BlockSprite *block = BlockSprite::createBlock(true, ranRed, ranGreen, ranBlue, line - 3, line - 3, line * i, line * j);
                block->setPosX(i);
                block->setPosY(j);
                block->setRanColor(ranColor);
                this->addChild(block);
            }else {
                BlockSprite *block = BlockSprite::createBlock(false, ranRed, ranGreen, ranBlue, line - 3, line - 3, line * i, line * j);
                block->setPosX(i);
                block->setPosY(j);
                block->setRanColor(ranColor);
                this->addChild(block);
            }
        }
    }
    //add event listener
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(GetTheOneLayer::onTouchBegan, this, matrix, ranX, ranY);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
} 

bool GetTheOneLayer::onTouchBegan(Touch *touch, Event *event, int matrix, int ranX, int ranY) {
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //get touched block
    Point touchPoint = touch->getLocation();
    float leftX = this->getContentSize().width / matrix * ranX;
    float rightX = this->getContentSize().width / matrix * (ranX + 1);
    float bottomY = this->getContentSize().height / matrix * ranY;
    float topY = this->getContentSize().height / matrix * (ranY + 1);
    //log("ranx = %i , rany = %i", ranX, ranY);
    //log("touchPoint x is %f, touchPoint y is %f", touchPoint.x, touchPoint.y);
    //log("left x is %f, right x is %f, bottomY is %f, topY is %f", leftX, rightX, bottomY, topY);
    //change layer
    if (leftX <= touchPoint.x && rightX >= touchPoint.x && bottomY <= touchPoint.y - 120 && topY >= touchPoint.y - 120) {
        GetTheOneScore = GetTheOneScore + 1;
        GetTheOneLayer *newLayer;
        if (matrix < 6) {
            newLayer = GetTheOneLayer::createLayer(matrix + 1);
        }else {
            newLayer = GetTheOneLayer::createLayer(matrix);
        }
        //log("size : %f , %f", visibleSize.width, visibleSize.width);
        newLayer->setContentSize(Size(visibleSize.width, visibleSize.width));
        newLayer->setPosition(Point(0, 120));
        this->getParent()->addChild(newLayer);
        this->removeFromParent();
    }
}

