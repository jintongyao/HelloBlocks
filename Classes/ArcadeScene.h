//
//  MainScene.h
//  HelloBlocks
//
//  Created by JinTongyao on 8/27/14.
//
//
#pragma once
#include "cocos2d.h"
#include "Settings.h"
#include "BlockSprite.h"
#include "WelcomeScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;

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
    LayerColor *arcadeLayer;
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