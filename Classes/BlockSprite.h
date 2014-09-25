//
//  BlockSprite.h
//  HelloBlocks
//
//  Created by JinTongyao on 8/27/14.
//
//
#pragma once
#include "cocos2d.h"
#include "MyColor.h"
#include "stdio.h"

USING_NS_CC;
using namespace std;

class BlockSprite : public Sprite {
public:
    static BlockSprite* createBlock(int ranColor, theme colorTheme, int width, int height, int posX, int posY);
    static BlockSprite* createBlock(bool isTheOneFlag, int ranColor, theme colorTheme, int width, int height, int posX, int posY);
    BlockSprite();
    ~BlockSprite();
    virtual bool init();
    CREATE_FUNC(BlockSprite);
    
    int getRanColor();
    void setRanColor(int ranColor);
    int getBlockWidth();
    void setBlockWidth(int w);
    int getBlockHeight();
    void setBlockHeight(int h);
    int getPosX();
    void setPosX(int posX);
    int getPosY();
    void setPosY(int posY);
    theme getColorTheme();
    void setColorTheme(theme colorTheme);
    MyColor* getBlockColor();
    void setBlockColor(MyColor *blockColor);
    LayerColor* getBlockBackgroundLayer();
    void setBlockBackgroundLayer(LayerColor *blockBackgroundLayer);
    
private:
    int posX;
    int posY;
    int blockWidth;
    int blockHeight;
    void blockInit(int ranColor, theme colorTheme, int width, int height, int posX, int posY);
    void blockInit(bool IsTheOneFlag, int ranColor, theme colorTheme, int width, int height, int posX, int posY);
    int ranColor;
    MyColor* blockColor;
    theme colorTheme;
    LayerColor *blockBackgroundLayer;
    
};
