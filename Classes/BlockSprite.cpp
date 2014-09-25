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

bool BlockSprite::init() {
    if (!Sprite::init()) {
        return false;
    }
    return true;
}

/**
 *  create block for normal mode
 *  @param ranColor
 *  @param colorTheme
 *  @param width
 *  @param height
 *  @param posX
 *  @param posY
 *  @return BlockSprite
 */
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

/**
 *  create block for GetTheOne
 *  @param isTheOneFlag
 *  @param ranColor
 *  @param colorTheme
 *  @param width
 *  @param height
 *  @param posX
 *  @param posY
 *  @return BlockSprite
 */
BlockSprite* BlockSprite::createBlock(bool isTheOneFlag, int ranColor, theme colorTheme, int width, int height, int posX, int posY) {
    BlockSprite *block = new BlockSprite();
    if (block && block->init()) {
        block->autorelease();
        block->blockInit(isTheOneFlag, ranColor, colorTheme, width, height, posX, posY);
        return block;
    }
    CC_SAFE_DELETE(block);
    return NULL;
}

/**
 *  init process of "createBlock"(normal mode)
 *  @param ranColor
 *  @param colorTheme
 *  @param width
 *  @param height
 *  @param posX
 *  @param posY
 */
void BlockSprite::blockInit(int ranColor, theme colorTheme, int width, int height, int posX, int posY) {
    this->setColorTheme(colorTheme);
    this->setBlockColor(new MyColor(colorTheme, ranColor));
    this->blockBackgroundLayer = LayerColor::create(Color4B(this->getBlockColor()->getRed(), this->getBlockColor()->getGreen(), this->getBlockColor()->getBlue(), 255));
    this->blockBackgroundLayer->setPosition(Point(posX, posY));
    this->blockBackgroundLayer->setContentSize(Size(width, height));
    this->addChild(blockBackgroundLayer);
}

/**
 *  init process of "createBlock"(get the one)
 *  @param isTheOneFlag
 *  @param ranColor
 *  @param colorTheme
 *  @param width
 *  @param height
 *  @param posX
 *  @param posY
 */
void BlockSprite::blockInit(bool isTheOneFlag, int ranColor, theme colorTheme, int width, int height, int posX, int posY) {
    this->setColorTheme(colorTheme);
    this->setBlockColor(new MyColor(colorTheme, ranColor));
    //the special block : change the color
    if(isTheOneFlag) {
        int randomInt = rand() % 6;
        switch (randomInt) {
            case 1:
                this->blockBackgroundLayer = LayerColor::create(Color4B(this->getBlockColor()->getRed() + 15, this->getBlockColor()->getGreen(), this->getBlockColor()->getBlue(), 255));
                break;
            case 2:
                this->blockBackgroundLayer = LayerColor::create(Color4B(this->getBlockColor()->getRed(), this->getBlockColor()->getGreen() + 15, this->getBlockColor()->getBlue(), 255));
                break;
            case 3:
                this->blockBackgroundLayer = LayerColor::create(Color4B(this->getBlockColor()->getRed(), this->getBlockColor()->getGreen(), this->getBlockColor()->getBlue() + 15, 255));
                break;
            case 4:
                this->blockBackgroundLayer = LayerColor::create(Color4B(this->getBlockColor()->getRed() - 15, this->getBlockColor()->getGreen(), this->getBlockColor()->getBlue(), 255));
                break;
            case 5:
                this->blockBackgroundLayer = LayerColor::create(Color4B(this->getBlockColor()->getRed(), this->getBlockColor()->getGreen() - 15, this->getBlockColor()->getBlue(), 255));
                break;
            case 6:
                this->blockBackgroundLayer = LayerColor::create(Color4B(this->getBlockColor()->getRed(), this->getBlockColor()->getGreen(), this->getBlockColor()->getBlue() - 15, 255));
                break;
            default:
                this->blockBackgroundLayer = LayerColor::create(Color4B(this->getBlockColor()->getRed() + 15, this->getBlockColor()->getGreen(), this->getBlockColor()->getBlue(), 255));
                break;
        }
    }else {
        this->blockBackgroundLayer = LayerColor::create(Color4B(this->getBlockColor()->getRed(), this->getBlockColor()->getGreen(), this->getBlockColor()->getBlue(), 255));
    }
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
