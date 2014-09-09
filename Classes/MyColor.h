//  MyColor.h
//  HelloBlocks
//  定义色彩类,用于表示游戏中的颜色
//  define the class in order to store colors in this game
//  Created by JinTongyao on 9/5/14.
//

#include <stdio.h>
#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

/**
 * 定义存储主题的数据结构
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