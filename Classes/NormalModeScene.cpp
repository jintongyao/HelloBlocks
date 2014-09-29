//
//  NormalModeScene.cpp
//  HelloBlocks
//
//  Created by JinTongyao on 9/20/14.
//
//

#include "NormalModeScene.h"

NormalModeScene::NormalModeScene() {}

NormalModeScene::~NormalModeScene() {}

bool NormalModeScene::init() {
    if (!Scene::init() ) {
        return false;
    }
    
    //play background music
    SimpleAudioEngine::getInstance()->playBackgroundMusic("dream-as-memory.mp3", true);
    
    //create background layer and front layer
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    //front layer
    switch (userTheme) {
        case PINK:
            normalModeLayer = LayerColor::create(Color4B(234, 97, 137, 255));
            frontLayer = LayerColor::create(Color4B(163, 20, 71, 150));
            break;
        case GRAY:
            normalModeLayer = LayerColor::create(Color4B(194, 194, 194, 255));
            frontLayer = LayerColor::create(Color4B(169, 170, 170, 255));
            break;
        case BLUE:
            normalModeLayer = LayerColor::create(Color4B(20, 142, 204, 255));
            frontLayer = LayerColor::create(Color4B(85, 169, 212, 255));
            break;
        case JELLY:
            normalModeLayer = LayerColor::create(Color4B(90, 191, 188, 255));
            frontLayer = LayerColor::create(Color4B(78, 165, 163, 255));
            break;
        case DARK:
            normalModeLayer = LayerColor::create(Color4B(50, 50, 50, 255));
            frontLayer = LayerColor::create(Color4B(100, 100, 100, 255));
            break;
        default:
            normalModeLayer = LayerColor::create(Color4B(20, 142, 204, 255));
            frontLayer = LayerColor::create(Color4B(85, 169, 212, 255));
            break;
    }
    float frontHeight = visibleSize.height;
    float line = frontHeight / VERTICAL_BLOCK_NUM;
    float frontWidth = line * HORIZONTAL_BLOCK_NUM;
    frontLayer->setContentSize(Size(frontWidth, frontHeight));
    frontLayer->setPosition(visibleSize.width - 5 * line, 0);
    normalModeLayer->addChild(frontLayer);
    
    //suspend button
    Sprite *suspendButton = Sprite::create("suspend.png");
    Sprite *activeSuspendButton = Sprite::create("suspend.png");
    activeSuspendButton->setPositionY(5);
    auto suspendMenuItem  = MenuItemSprite::create(suspendButton, activeSuspendButton, NULL, CC_CALLBACK_1(NormalModeScene::suspendCallBack, this));
    suspendMenuItem->setPosition((visibleSize.width - 5 * line) / 2 - 50, visibleSize.height - 150);
    auto suspendMenu = Menu::create(suspendMenuItem,NULL);
    suspendMenu->setPosition(Point(0 ,0));
    normalModeLayer->addChild(suspendMenu);
    
    //music button
    Sprite *musicButton = Sprite::create("musicon.png");
    Sprite *activeMusicButton = Sprite::create("musicon.png");
    activeMusicButton->setPositionY(5);
    auto musicMenuItem  = MenuItemSprite::create(musicButton, activeMusicButton, NULL, CC_CALLBACK_1(NormalModeScene::suspendCallBack, this));
    musicMenuItem->setPosition((visibleSize.width - 5 * line) / 2 + 50, visibleSize.height - 150);
    auto musicMenu = Menu::create(musicMenuItem,NULL);
    musicMenu->setPosition(Point(0 ,0));
    normalModeLayer->addChild(musicMenu);
    
    //scores
    scoreLabel = Label::create(CCString::createWithFormat("%d",scores)->_string, "American Typewriter.ttf", 40);
    scoreLabel->setAnchorPoint(Point(0.5, 0.5));
    scoreLabel->setPosition((visibleSize.width - 5 * line) / 2, visibleSize.height / 2 + 100);
    normalModeLayer->addChild(scoreLabel);
    
    //create blocks
    srand((unsigned)time(NULL));//add random seed
    for (int i = 0; i < HORIZONTAL_BLOCK_NUM; i++) {
        for (int j = 0; j < INITED_BLOCK_HEIGHT; j++) {
            int randomInt = rand() % COLOR_NUM;
            BlockSprite *block = BlockSprite::createBlock(randomInt, userTheme, line, line, line * i, line * j);
            block->setPosX(i);
            block->setPosY(j);
            block->setRanColor(randomInt);
            blocks[i][j] = block;
            frontLayer->addChild(blocks[i][j]);
        }
    }
    
    //add event listener
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(NormalModeScene::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    this->addChild(normalModeLayer);
    return true;
}

/**
 *  when touch began,execute this methods
 *
 *  @param touch
 *  @param event
 *  @return normalModeScene
 */
bool NormalModeScene::onTouchBegan(Touch *touch, Event *event) {
    //get touched block
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point touchPoint = touch->getLocation();
    BlockSprite *aBlock = this->getBlockSprite(visibleSize, touchPoint);
    
    if (aBlock != NULL) {
        //get and clear relative blocks
        getRelativeBlocks(aBlock);
        int clearNum = clearBlockCache.size();
        for (Vector<BlockSprite*>::iterator iter = clearBlockCache.begin(),iterEnd = clearBlockCache.end(); iter != iterEnd; iter++) {
            BlockSprite *tmpBlock = *iter;
            removeBlock(tmpBlock);
            blocks[tmpBlock->getPosX()][tmpBlock->getPosY()] = NULL;
        }
        clearBlockCache.clear();
        scores = scores + clearNum * 10;
        scoreLabel->setString(CCString::createWithFormat("%d",scores)->_string);
        
        //let blocks fall
        schedule(schedule_selector(NormalModeScene::fallBlock), 1, 0, 0.4);
        
        //move upward
        schedule(schedule_selector(NormalModeScene::upBlock), 1, 0, 0.4);
    }
    return true;
}

/**
 *  get seleceted block
 *
 *  @param size
 *  @param touchPoint
 *  @return             selected block
 */
BlockSprite* NormalModeScene::getBlockSprite(Size size, Point touchPoint) {
    float blockLine = size.height / VERTICAL_BLOCK_NUM;
    if ((touchPoint.x > (size.width - (HORIZONTAL_BLOCK_NUM + 1) * blockLine)) && (touchPoint.x < ((size.width - blockLine)))) {
        int posX = getXPosFromArray(touchPoint, size);
        int posY = getYPosFromArray(touchPoint, size);
        //        log("the x is %i and y is %i", i ,j);
        return blocks[posX][posY];
    }else {
        return NULL;
    }
}

/**
 *  get the relative blocks around the selected block
 *
 *  @param relativeBlock
 */
void NormalModeScene::getRelativeBlocks(BlockSprite *relativeBlock) {
    if (clearBlockCache.contains(relativeBlock)) {
        return;
    }
    clearBlockCache.pushBack(relativeBlock);
    
    int posX = relativeBlock->getPosX();
    int posY = relativeBlock->getPosY();
    int ranColor = relativeBlock->getRanColor();
    
    //top
    if (posY < (VERTICAL_BLOCK_NUM - 1) && blocks[posX][posY + 1] != NULL) {
        if (blocks[posX][posY + 1]->getRanColor() == ranColor) {
            getRelativeBlocks(blocks[posX][posY + 1]);
        }
    }
    //bottom
    if (posY > 0  && blocks[posX][posY - 1] != NULL) {
        if (blocks[posX][posY - 1]->getRanColor() == ranColor) {
            getRelativeBlocks(blocks[posX][posY - 1]);
        }
    }
    //left
    if (posX > 0  && blocks[posX - 1][posY] != NULL) {
        if (blocks[posX - 1][posY]->getRanColor() == ranColor) {
            getRelativeBlocks(blocks[posX - 1][posY]);
        }
    }
    //right
    if (posX < (HORIZONTAL_BLOCK_NUM - 1)  && blocks[posX + 1][posY] != NULL) {
        if (blocks[posX + 1][posY]->getRanColor() == ranColor) {
            getRelativeBlocks(blocks[posX + 1][posY]);
        }
    }
}

/**
 *  remove the selected block
 *
 *  @param block
 */
void NormalModeScene::removeBlock(BlockSprite *block) {
    auto removeBlockPhyAction = CallFunc::create(CC_CALLBACK_0(NormalModeScene::removeBlockPhyCallback,this, block));
    //    block->getBlockBackgroundLayer()->runAction(Sequence::create(Spawn::create(RotateBy::create(0.4, 360), MoveTo::create(0.4, Point(block->getPosX(), -200)), NULL), removeBlockPhyAction, NULL));//移除动作序列
    //    block->getBlockBackgroundLayer()->runAction(Sequence::create(Spawn::create(RotateBy::create(0.2, 360), ScaleBy::create(0.2, 0.5, 0.5), NULL), removeBlockPhyAction, NULL));//移除动作序列
    block->getBlockBackgroundLayer()->runAction(Sequence::create(Spawn::create(FadeOut::create(0.4), NULL), removeBlockPhyAction, NULL));
}

/**
 *  remove the block from the front layer
 *
 *  @param block
 */
void NormalModeScene::removeBlockPhyCallback(BlockSprite *block) {
    this->frontLayer->removeChild(block);
}

/**
 *  drop the blocks
 *
 *  @param dt
 */
void NormalModeScene::fallBlock(float dt) {
    Size size = Director::getInstance()->getVisibleSize();
    for (int x = 0; x < HORIZONTAL_BLOCK_NUM; x++) {
        //1.loop the columns
        for (int y = 0; y < VERTICAL_BLOCK_NUM; y++) {
            //2.find the blank area at the bottom
            if (blocks[x][y] == NULL) {
                BlockSprite *aboveBlock = checkHasBlocksAbove(x, y);//3.check whether there are blocks over the blank area
                if (aboveBlock != NULL) {
                    //4.move the blocks above blank area n lines down
                    int moveStep = aboveBlock->getPosY() - y;
                    aboveBlock->runAction(MoveBy::create(0.0001, Point(0, -(moveStep *(size.height / VERTICAL_BLOCK_NUM)))));
                    //5.refresh data of the blocks and array
                    int originAboveX = aboveBlock->getPosX();
                    int originAboveY = aboveBlock->getPosY();
                    blocks[x][y] = aboveBlock;
                    aboveBlock->setPosX(x);
                    aboveBlock->setPosY(y);
                    blocks[originAboveX][originAboveY] = NULL;
                }
            }
        }
    }
    //array test
    //    for (int j = VERTICAL_BLOCK_NUM - 1; j >= 0; j--) {
    //        printf("\n");
    //        for (int i = 0; i < HORIZONTAL_BLOCK_NUM; i++) {
    //            if(blocks[i][j] != NULL) {
    //                printf("[%i , %i] ", blocks[i][j]->getPosX(), blocks[i][j]->getPosY());
    //            }else {
    //                printf("[    ] ");
    //            }
    //        }
    //    }
}

/**
 *  rise the blocks
 *  @param dt
 */
void NormalModeScene::upBlock(float dt) {
    Size size = Director::getInstance()->getVisibleSize();
    float line = size.height / VERTICAL_BLOCK_NUM;
    
    //is game over
    for (int i = 0; i < HORIZONTAL_BLOCK_NUM; i++) {
        if (blocks[i][VERTICAL_BLOCK_NUM - 1] != NULL) {
            auto *gameoverLayer = PopupLayer::createGameoverLayer(2, scores);
            this->addChild(gameoverLayer);
        }
    }
    
    //move all blocks upward
    for (int j = VERTICAL_BLOCK_NUM - 2; j >= 0; j--) {
        for (int i = 0; i < HORIZONTAL_BLOCK_NUM; i++) {
            if(blocks[i][j] != NULL) {
                blocks[i][j]->setPosY(j+1);
                blocks[i][j]->runAction(MoveBy::create(0.05, Point(0, size.height / VERTICAL_BLOCK_NUM)));
                blocks[i][j+1] = blocks[i][j];
                blocks[i][j] = NULL;
            }
        }
    }
    
    //generate 4 blocks
    srand((unsigned)time(NULL));//add random seed
    for (int k = 0; k < HORIZONTAL_BLOCK_NUM; k++) {
        int randomInt = rand() % COLOR_NUM;
        BlockSprite *block = BlockSprite::createBlock(randomInt, userTheme, line, line, line * k, 0);
        block->setPosX(k);
        block->setPosY(0);
        block->setRanColor(randomInt);
        blocks[k][0] = block;
        frontLayer->addChild(block);
    }
}

/**
 *  check whether there are blocks above
 *  @param x
 *  @param y
 *  @return the block above
 */
BlockSprite* NormalModeScene::checkHasBlocksAbove(int x, int y) {
    for (int j = y; j < VERTICAL_BLOCK_NUM; j++) {
        if (blocks[x][j] != NULL) {
            return blocks[x][j];
        }
    }
    return NULL;
}

/**
 *  back to the welcome scene
 */
void NormalModeScene::back2Welcome() {
    auto scene = WelcomeScene::create();
    TransitionCrossFade *transition = TransitionCrossFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}

/**
 *  locate the x-coordinate of the touch point
 *
 *  @param touchPoint
 *  @param size        the size of current screen
 *  @return            the number of block in array
 */
int NormalModeScene::getXPosFromArray(Point touchPoint, Size size) {
    float blockLine = (size.height / VERTICAL_BLOCK_NUM);
    return (int)(touchPoint.x - (size.width - (HORIZONTAL_BLOCK_NUM + 1) * blockLine)) / blockLine;
}

/**
 *  locate the x-coordinate of the touch point
 *
 *  @param touchPoint
 *  @param size
 *  @return             the number of block in array
 */
int NormalModeScene::getYPosFromArray(Point touchPoint, Size size) {
    return (int)(touchPoint.y / (size.height / VERTICAL_BLOCK_NUM));
}

void NormalModeScene::suspendCallBack(Ref *sender) {
    auto *suspendLayer = PopupLayer::createSuspendLayer(1);
    this->addChild(suspendLayer);
}
