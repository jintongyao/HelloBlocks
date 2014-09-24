//
//  BlockSprite.cpp
//  HelloBlocks
//
//  Created by JinTongyao on 8/27/14.
//
//

#include "BlockSprite.h"

BlockSprite::BlockSprite() {}

BlockSprite::~BlockSprite() {}

BlockSprite* BlockSprite::createBlock(int ranColor, theme colorTheme, int width, int height, int posX, int posY) {
    BlockSprite *block = new BlockSprite();
    if (block && block->init()) {
        block->autorelease();
        block->blockInit(ranColor, colorTheme, width, height, posX, posY);
        return block;
    }
    CC_SAFE_DELETE(block);
    return NULL;
}

bool BlockSprite::init() {
    if (!Sprite::init()) {
        return false;
    }
    return true;
}

void BlockSprite::blockInit(int ranColor, theme colorTheme, int width, int height, int posX, int posY) {
    this->setColorTheme(colorTheme);
    this->setBlockColor(new MyColor(colorTheme, ranColor));
    this->blockBackgroundLayer = LayerColor::create(Color4B(this->getBlockColor()->getRed(), this->getBlockColor()->getGreen(), this->getBlockColor()->getBlue(), 255));
    this->blockBackgroundLayer->setPosition(Point(posX, posY));
    this->blockBackgroundLayer->setContentSize(Size(width, height));
    this->addChild(blockBackgroundLayer);
}

int BlockSprite::getRanColor() {
    return this->ranColor;
}

void BlockSprite::setRanColor(int ranColor) {
    this->ranColor = ranColor;

}

MyColor* BlockSprite::getBlockColor() {
    return this->blockColor;
}

void BlockSprite::setBlockColor(MyColor *blockColor) {
    this->blockColor = blockColor;
}

theme BlockSprite::getColorTheme() {
    return this->colorTheme;
}

void BlockSprite::setColorTheme(theme colorTheme) {
    this->colorTheme = colorTheme;
}

int BlockSprite::getPosX() {
    return this->posX;
}

void BlockSprite::setPosX(int posX) {
    this->posX = posX;
}

int BlockSprite::getPosY() {
    return this->posY;
}

void BlockSprite::setPosY(int posY) {
    this->posY = posY;
}

int BlockSprite::getBlockWidth() {
    return this->blockWidth;
}

void BlockSprite::setBlockWidth(int w) {
    this->blockWidth = w;
}

int BlockSprite::getBlockHeight() {
    return this->blockHeight;
}

void BlockSprite::setBlockHeight(int h) {
    this->blockHeight = h;
}

LayerColor* BlockSprite::getBlockBackgroundLayer() {
    return this->blockBackgroundLayer;
}

void BlockSprite::setBlockBackgroundLayer(LayerColor *blockBackgroundLayer) {
    this->blockBackgroundLayer = blockBackgroundLayer;
}