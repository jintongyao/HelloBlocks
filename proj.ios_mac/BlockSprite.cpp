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
//    if (this->getColorTheme() == theme::PURPLE) {
//        if (ranColor == 0) {
//            blockBackgroundLayer->setColor(Color3B(167, 80, 232));//紫色
//        }else if (ranColor == 1) {
//            blockBackgroundLayer->setColor(Color3B(173, 222, 255));//浅蓝
//        }else if (ranColor == 2) {
//            blockBackgroundLayer->setColor(Color3B(195, 116, 105));//浅褐
//        }else if (ranColor == 3) {
//            blockBackgroundLayer->setColor(Color3B(227, 217, 192));//米黄
//        }else if (ranColor == 4) {
//            blockBackgroundLayer->setColor(Color3B(40, 115, 53));//深绿
//        }else if (ranColor == 5) {
//            blockBackgroundLayer->setColor(Color3B(101, 58, 200));//蓝紫
//        }
//    }else if (this->getColorTheme() == theme::DARK) {
//        if (ranColor == 0) {
//            blockBackgroundLayer->setColor(Color3B(255, 252, 200));//
//        }else if (ranColor == 1) {
//            blockBackgroundLayer->setColor(Color3B(85, 255, 200));//
//        }else if (ranColor == 2) {
//            blockBackgroundLayer->setColor(Color3B(59, 184, 242));//
//        }else if (ranColor == 3) {
//            blockBackgroundLayer->setColor(Color3B(255, 89, 131));//
//        }else if (ranColor == 4) {
//            blockBackgroundLayer->setColor(Color3B(216, 34, 13));//
//        }else if (ranColor == 5) {
//            blockBackgroundLayer->setColor(Color3B(233, 83, 131));//
//        }
//    }else if (this->getColorTheme() == theme::GRAY) {
//        if (ranColor == 0) {
//            blockBackgroundLayer->setColor(Color3B(230, 230, 230));//
//        }else if (ranColor == 1) {
//            blockBackgroundLayer->setColor(Color3B(35, 35, 35));//
//        }else if (ranColor == 2) {
//            blockBackgroundLayer->setColor(Color3B(25, 178, 255));//
//        }else if (ranColor == 3) {
//            blockBackgroundLayer->setColor(Color3B(12, 89, 127));//
//        }else if (ranColor == 4) {
//            blockBackgroundLayer->setColor(Color3B(159, 0, 82));//玫红
//        }else if (ranColor == 5) {
//            blockBackgroundLayer->setColor(Color3B(221, 218, 202));//
//        }
//    }else if (this->getColorTheme() == theme::BLUE) {
//        if (ranColor == 0) {
//            blockBackgroundLayer->setColor(Color3B(6, 44, 64));//
//        }else if (ranColor == 1) {
//            blockBackgroundLayer->setColor(Color3B(220, 220, 220));//
//        }else if (ranColor == 2) {
//            blockBackgroundLayer->setColor(Color3B(255, 50, 70));//
//        }else if (ranColor == 3) {
//            blockBackgroundLayer->setColor(Color3B(11, 216, 232));//
//        }else if (ranColor == 4) {
//            blockBackgroundLayer->setColor(Color3B(159, 0, 82));//玫红
//        }else if (ranColor == 5) {
//            blockBackgroundLayer->setColor(Color3B(221, 218, 202));//
//        }
//    }else if (this->getColorTheme() == theme::PINK) {//234,97,137 163,20,71
//        if (ranColor == 0) {
//            blockBackgroundLayer->setColor(Color3B(254, 235, 200));
//        }else if (ranColor == 1) {
//            blockBackgroundLayer->setColor(Color3B(243, 168, 187));
//        }else if (ranColor == 2) {
//            blockBackgroundLayer->setColor(Color3B(255, 255, 255));
//        }else if (ranColor == 3) {
//            blockBackgroundLayer->setColor(Color3B(21, 137, 229));
//        }else if (ranColor == 4) {
//            blockBackgroundLayer->setColor(Color3B(102, 43, 43));
//        }else if (ranColor == 5) {
//            blockBackgroundLayer->setColor(Color3B(251, 203, 114));
//        }
//    }else if (this->getColorTheme() == theme::JELLY) {
//        if (ranColor == 0) {
//            blockBackgroundLayer->setColor(Color3B(235, 134, 154));
//        }else if (ranColor == 1) {
//            blockBackgroundLayer->setColor(Color3B(84, 199, 239));
//        }else if (ranColor == 2) {
//            blockBackgroundLayer->setColor(Color3B(235, 245, 235));
//        }else if (ranColor == 3) {
//            blockBackgroundLayer->setColor(Color3B(175, 157, 158));
//        }else if (ranColor == 4) {
//            blockBackgroundLayer->setColor(Color3B(194, 159, 239));
//        }else if (ranColor == 5) {
//            blockBackgroundLayer->setColor(Color3B(251, 203, 114));
//        }
//    }else {//DEFAULT
//        if (ranColor == 0) {
//            blockBackgroundLayer->setColor(Color3B(255, 252, 255));//
//        }else if (ranColor == 1) {
//            blockBackgroundLayer->setColor(Color3B(255, 128, 0));//
//        }else if (ranColor == 2) {
//            blockBackgroundLayer->setColor(Color3B(25, 178, 255));//
//        }else if (ranColor == 3) {
//            blockBackgroundLayer->setColor(Color3B(255, 71, 88));//
//        }else if (ranColor == 4) {
//            blockBackgroundLayer->setColor(Color3B(16, 138, 243));//
//        }else if (ranColor == 5) {
//            blockBackgroundLayer->setColor(Color3B(232, 29, 71));//
//        }
//    }
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