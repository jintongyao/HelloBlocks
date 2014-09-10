//
//  AtlasLoader.cpp
//
//  Created by JinTongyao on 8/21/14.
//

#include "AtlasLoader.h"

using namespace cocos2d;

AtlasLoader* AtlasLoader::sharedAtlasLoader = nullptr;

AtlasLoader::AtlasLoader(){}

AtlasLoader* AtlasLoader::getInstance() {
    if(sharedAtlasLoader == NULL) {
        sharedAtlasLoader = new AtlasLoader();
    }
    return sharedAtlasLoader;
}

void AtlasLoader::destroyInstance() {
    CC_SAFE_DELETE(sharedAtlasLoader);
}

/**
 *  load resources
 *
 *  @param fileName
 */
void AtlasLoader::loadAtlas(string fileName) {
    auto textureAtlas = Director::getInstance()->getTextureCache()->addImage("atlas.png");
    this->loadAtlas(fileName, textureAtlas);
}

/**
 *  load the texture by the config file
 *
 *  @param filename
 *  @param texture
 */
void AtlasLoader::loadAtlas(std::string filename, Texture2D *texture) {
    string data = FileUtils::getInstance()->getStringFromFile(filename);//读取素材布局文件
    unsigned pos;
    Atlas atlas;
    pos = data.find_first_of("\n");
    string line = data.substr(0, pos);
    data = data.substr(pos + 1);
    while(line != ""){
        sscanf(line.c_str(), "%s %d %d %f %f %f %f",
        atlas.name, &atlas.width, &atlas.height, &atlas.start.x,
        &atlas.start.y, &atlas.end.x, &atlas.end.y);
        atlas.start.x = 1024*atlas.start.x;
        atlas.start.y = 1024*atlas.start.y;
        atlas.end.x = 1024*atlas.end.x;
        atlas.end.y = 1024*atlas.end.y;
        
        pos = data.find_first_of("\n");
        line = data.substr(0, pos);
        data = data.substr(pos + 1);
        
        Rect rect = Rect(atlas.start.x, atlas.start.y, atlas.width, atlas.height);
        auto frame = SpriteFrame::createWithTexture(texture, rect);
        this->_spriteFrames.insert(string(atlas.name), frame);
    }
}

/**
 *  get sprite frame by name
 *
 *  @param name
 *  @return     SpriteFrame
 */
SpriteFrame* AtlasLoader::getSpriteFrameByName(string name){
    return this->_spriteFrames.at(name);
}

bool AtlasLoader::init(){
    return true;
}


