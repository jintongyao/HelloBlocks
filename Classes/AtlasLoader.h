//
//  AtlasLoader.h
//  MyBird
//
//  Created by JinTongyao on 8/21/14.
//
//
#pragma once
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

/**
 *  define the Atlas struct
 */
typedef struct _atlas{
    char name[255];
    int width;
    int height;
    Point start;
    Point end;
} Atlas;

class AtlasLoader {
public:
    static AtlasLoader* getInstance();//singleton
    static void destroyInstance();
    void loadAtlas(string fileName);
    void loadAtlas(string filename, cocos2d::Texture2D *texture);
    SpriteFrame* getSpriteFrameByName(string name);
    
protected:
    virtual bool init();
    static AtlasLoader* sharedAtlasLoader;
    Map<std::string, SpriteFrame*> _spriteFrames;
    
private:
    AtlasLoader();
    
};