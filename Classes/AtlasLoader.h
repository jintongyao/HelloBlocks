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

//定义Atlas结构体
typedef struct _atlas{
    char name[255];//名称
    int width;//宽度
    int height;//高度
    Point start;//起始坐标
    Point end;//结束坐标
} Atlas;

class AtlasLoader {
public:
    static AtlasLoader* getInstance();//设定为单态类
    static void destroyInstance();//对象销毁
    void loadAtlas(string fileName);//从文件中读取背景图片
    void loadAtlas(string filename, cocos2d::Texture2D *texture);//
    SpriteFrame* getSpriteFrameByName(string name);
    
protected:
    virtual bool init();
    static AtlasLoader* sharedAtlasLoader;
    Map<std::string, SpriteFrame*> _spriteFrames;
    
private:
    AtlasLoader();
};