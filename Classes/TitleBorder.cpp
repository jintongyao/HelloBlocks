//
//  TitleBorder.cpp
//  HelloBlocks
//
//  Created by JinTongyao on 8/31/14.
//
//

#include "TitleBorder.h"

bool TitleBorder::init() {
    if (!Node::init()) {
        return false;
    }
    return true;
}

void TitleBorder::draw(Renderer *renderer, const Mat4& transform, bool transformUpdated) {
    DrawPrimitives::setDrawColor4B(0, 255, 255, 255);
    DrawPrimitives::drawRect(Point(0, 0), Point(200, 100));
}