//
//  MainScene.h
//  HelloBlocks
//
//  Created by JinTongyao on 8/27/14.
//
//
#pragma once
#include "cocos2d.h"
#include "BlockSprite.h"
#include "WelcomeScene.h"

using namespace cocos2d;

const int VERTICAL_BLOCK_NUM = 12;
const int HORIZONTAL_BLOCK_NUM = 4;
const int COLOR_NUM = 4;
const int INITED_BLOCK_HEIGHT = 4;

class ArcadeScene : public Scene {
public:
    ArcadeScene();
    ~ArcadeScene();
    virtual bool init();
    virtual bool onTouchBegan(Touch *touch, Event *event);
    CREATE_FUNC(ArcadeScene);
    
private:
    void back2Welcome();
    bool gameoverFlag = false;
    
    LayerColor *frontLayer;
    BlockSprite* getBlockSprite(Size size, Point touchPoint);
    BlockSprite *blocks[4][12] = {0};
    Vector<BlockSprite*> clearBlockCache;

    int getXPosFromArray(Point touchPoint, Size size);
    int getYPosFromArray(Point touchPoint, Size size);
    void getRelativeBlocks(BlockSprite *relativeBlock);
    
    void removeBlock(BlockSprite *block);
    void removeBlockPhyCallback(BlockSprite *block);
    
    void fallBlock(float dt);
    BlockSprite* checkHasBlocksAbove(int x, int y);
    void upBlock(float dt);
};