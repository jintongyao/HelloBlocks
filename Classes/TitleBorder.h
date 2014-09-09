//
//  TitleBorder.h
//  HelloBlocks
//
//  Created by JinTongyao on 8/31/14.
//
//
#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class TitleBorder : public Node {
public:
    virtual bool init();
    virtual void draw(Renderer *renderer, const Mat4& transform, bool transformUpdated);
    CREATE_FUNC(TitleBorder);
};
