//
//  MainScene.cpp
//  HelloBlocks
//
//  Created by JinTongyao on 8/27/14.
//
//

#include "ArcadeScene.h"

ArcadeScene::ArcadeScene() {}

ArcadeScene::~ArcadeScene() {}

bool ArcadeScene::init() {
    if (!Scene::init() ) {
        return false;
    }
    
    //create background layer and front layer
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    switch (userTheme) {
        case PINK:
            arcadeLayer = LayerColor::create(Color4B(234, 97, 137, 255));
            frontLayer = LayerColor::create(Color4B(163, 20, 71, 150));
            break;
        case GRAY:
            arcadeLayer = LayerColor::create(Color4B(194, 194, 194, 255));
            frontLayer = LayerColor::create(Color4B(169, 170, 170, 255));
            break;
        case BLUE:
            arcadeLayer = LayerColor::create(Color4B(20, 142, 204, 255));
            frontLayer = LayerColor::create(Color4B(85, 169, 212, 255));
            break;
        case JELLY:
            arcadeLayer = LayerColor::create(Color4B(90, 191, 188, 255));
            frontLayer = LayerColor::create(Color4B(78, 165, 163, 255));
            break;
        case DARK:
            arcadeLayer = LayerColor::create(Color4B(50, 50, 50, 255));
            frontLayer = LayerColor::create(Color4B(100, 100, 100, 255));
            break;
        default:
            arcadeLayer = LayerColor::create(Color4B(20, 142, 204, 255));
            frontLayer = LayerColor::create(Color4B(85, 169, 212, 255));
            break;
    }
    //PINK
//    auto *arcadeLayer = LayerColor::create(Color4B(234, 97, 137, 255));//set background color of the layer
//    frontLayer = LayerColor::create(Color4B(163, 20, 71, 150));//set front color
    //GRAY
//    auto *arcadeLayer = LayerColor::create(Color4B(194, 194, 194, 255));//set background color of the layer
//    frontLayer = LayerColor::create(Color4B(169, 170, 170, 255));//set front color
    //BLUE
//    auto *arcadeLayer = LayerColor::create(Color4B(20, 142, 204, 255));//set background color of the layer
//    frontLayer = LayerColor::create(Color4B(85, 169, 212, 255));//set front color
    //JELLY
//auto *arcadeLayer = LayerColor::create(Color4B(90, 191, 188, 255));//set background color of the layer
//frontLayer = LayerColor::create(Color4B(78, 165, 163, 255));//set front color
    //DARK
//    auto *arcadeLayer = LayerColor::create(Color4B(50, 50, 50, 255));//set background color of the layer
//    frontLayer = LayerColor::create(Color4B(100, 100, 100, 255));//set front color
    
    float frontHeight = visibleSize.height;
    float line = frontHeight / VERTICAL_BLOCK_NUM;
    float frontWidth = line * HORIZONTAL_BLOCK_NUM;
    frontLayer->setContentSize(Size(frontWidth, frontHeight));
    frontLayer->setPosition(visibleSize.width - 5 * line, 0);
    arcadeLayer->addChild(frontLayer);
    
    //play background music
    SimpleAudioEngine::getInstance()->playBackgroundMusic("solo.wav", true);
    
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
    touchListener->onTouchBegan = CC_CALLBACK_2(ArcadeScene::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    this->addChild(arcadeLayer);
    return true;
}

/**
 *  when touch began,execute these methods
 *
 *  @param touch
 *  @param event
 *  @return         ArcadeScene
 */
bool ArcadeScene::onTouchBegan(Touch *touch, Event *event) {
    //get touched block
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point touchPoint = touch->getLocation();
    BlockSprite *aBlock = this->getBlockSprite(visibleSize, touchPoint);
    
    if (aBlock != NULL) {
        //get and clear relative blocks
        getRelativeBlocks(aBlock);
        for (Vector<BlockSprite*>::iterator iter = clearBlockCache.begin(),iterEnd = clearBlockCache.end(); iter != iterEnd; iter++) {
            BlockSprite *tmpBlock = *iter;
            removeBlock(tmpBlock);
            blocks[tmpBlock->getPosX()][tmpBlock->getPosY()] = NULL;
        }
        clearBlockCache.clear();
        
        //let blocks fall
        schedule(schedule_selector(ArcadeScene::fallBlock), 1, 0, 0.4);
        
        //move upward
        schedule(schedule_selector(ArcadeScene::upBlock), 1, 0, 0.4);
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
BlockSprite* ArcadeScene::getBlockSprite(Size size, Point touchPoint) {
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
void ArcadeScene::getRelativeBlocks(BlockSprite *relativeBlock) {
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
void ArcadeScene::removeBlock(BlockSprite *block) {
    auto removeBlockPhyAction = CallFunc::create(CC_CALLBACK_0(ArcadeScene::removeBlockPhyCallback,this, block));
//    block->getBlockBackgroundLayer()->runAction(Sequence::create(Spawn::create(RotateBy::create(0.4, 360), MoveTo::create(0.4, Point(block->getPosX(), -200)), NULL), removeBlockPhyAction, NULL));//移除动作序列
//    block->getBlockBackgroundLayer()->runAction(Sequence::create(Spawn::create(RotateBy::create(0.2, 360), ScaleBy::create(0.2, 0.5, 0.5), NULL), removeBlockPhyAction, NULL));//移除动作序列
    block->getBlockBackgroundLayer()->runAction(Sequence::create(Spawn::create(FadeOut::create(0.4), NULL), removeBlockPhyAction, NULL));
}

/**
 *  remove the block from the front layer
 *
 *  @param block
 */
void ArcadeScene::removeBlockPhyCallback(BlockSprite *block) {
    this->frontLayer->removeChild(block);
}

/**
 *  drop the blocks
 *
 *  @param dt
 */
void ArcadeScene::fallBlock(float dt) {
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
 *
 *  @param dt
 */
void ArcadeScene::upBlock(float dt) {
    Size size = Director::getInstance()->getVisibleSize();
    float line = size.height / VERTICAL_BLOCK_NUM;
    
    //is game over
    for (int i = 0; i < HORIZONTAL_BLOCK_NUM; i++) {
        if (blocks[i][VERTICAL_BLOCK_NUM - 1] != NULL) {
            back2Welcome();
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
 *
 *  @param x
 *  @param y
 *  @return the block above
 */
BlockSprite* ArcadeScene::checkHasBlocksAbove(int x, int y) {
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
void ArcadeScene::back2Welcome() {
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
int ArcadeScene::getXPosFromArray(Point touchPoint, Size size) {
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
int ArcadeScene::getYPosFromArray(Point touchPoint, Size size) {
    return (int)(touchPoint.y / (size.height / VERTICAL_BLOCK_NUM));
}
