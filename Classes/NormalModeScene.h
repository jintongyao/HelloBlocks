//
//  NormalModeScene.h
//  HelloBlocks
//
//  Created by JinTongyao on 9/20/14.
//
//

#pragma once
#include "cocos2d.h"
#include "Settings.h"
#include "BlockSprite.h"
#include "WelcomeScene.h"

using namespace cocos2d;

class NormalModeScene: public Scene {
public:
    NormalModeScene();
    ~NormalModeScene();
    virtual bool init();
    virtual bool onTouchBegan(Touch *touch, Event *event);
    CREATE_FUNC(NormalModeScene);
    
private:
    void back2Welcome();
    bool gameoverFlag = false;
    
    LayerColor *frontLayer;
    LayerColor *normalModeLayer;
    LayerColor *middleLayer;
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

    void suspendCallBack(Object *sender);
};
