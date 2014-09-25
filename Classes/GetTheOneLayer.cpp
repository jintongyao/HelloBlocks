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
    int line = this->getContentSize().width / 2;
    int ranX = rand() % matrix;
    int ranY = rand() % matrix;
    int ranColor = rand() % 5;
    for(int i = 0; i < matrix; i++) {
        for(int j = 0; j < matrix; j++) {
            if(i == ranX && j == ranY) {
                BlockSprite *block = BlockSprite::createBlock(true, ranColor, userTheme, line, line, line * i, line * j);
                block->setPosX(i);
                block->setPosY(j);
                block->setRanColor(ranColor);
                this->addChild(block);
            }else {
                BlockSprite *block = BlockSprite::createBlock(false, ranColor, userTheme, line, line, line * i, line * j);
                block->setPosX(i);
                block->setPosY(j);
                block->setRanColor(ranColor);
                this->addChild(block);
            }
        }
    }
} 
