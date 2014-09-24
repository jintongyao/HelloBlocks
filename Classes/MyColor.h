//  MyColor.h
//  HelloBlocks
//  define the class in order to store colors in this game
//  Created by JinTongyao on 9/5/14.
//
#pragma once
#include <stdio.h>
#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

/**
 * define the enum struct for the theme
 **/
typedef enum {
    DEFAULT,
    JELLY,
    BLUE,
    PURPLE,
    DARK,
    GREEN,
    GRAY,
    PINK,
    WHITE
} theme;

/**
 *  class MyColor
 *  define the colors in this game
 */
class MyColor {
public:
    MyColor(theme themeName, int colorNum);
    void setColorRgb(theme themeName, int colorNum);
    theme getThemeName();
    void setThemeName(theme themeName);
    GLubyte getRed();
    void setRed(GLubyte red);
    GLubyte getGreen();
    void setGreen(GLubyte green);
    GLubyte getBlue();
    void setBlue(GLubyte blue);
    
private:
    theme themeName;
    int colorNum;//the number of color,in order to randomize color
    GLubyte red;
    GLubyte green;
    GLubyte blue;
    
};
