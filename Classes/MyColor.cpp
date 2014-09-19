//
//  MyColor.cpp
//  HelloBlocks
//  the implementation of MyColor
//  Created by JinTongyao on 9/5/14.
//
//

#include "MyColor.h"

MyColor::MyColor(theme themeName, int colorNum) {
    this->themeName = themeName;
    this->colorNum = colorNum;
    this->setColorRgb(themeName, colorNum);
}

//set the rgb by theme name & random number
void MyColor::setColorRgb(theme themeName, int colorNum) {
    switch (themeName) {
        case PURPLE:
            switch (colorNum) {
                case 0:
                    setRed(167);
                    setGreen(80);
                    setBlue(232);
                    break;
                case 1:
                    setRed(173);
                    setGreen(222);
                    setBlue(255);
                    break;
                case 2:
                    setRed(195);
                    setGreen(116);
                    setBlue(105);
                    break;
                case 3:
                    setRed(227);
                    setGreen(217);
                    setBlue(192);
                    break;
                case 4:
                    setRed(40);
                    setGreen(115);
                    setBlue(53);
                    break;
                case 5:
                    setRed(101);
                    setGreen(58);
                    setBlue(200);
                    break;
            }
            break;
        case DARK:
            switch (colorNum) {
                case 0:
                    setRed(255);
                    setGreen(252);
                    setBlue(200);
                    break;
                case 1:
                    setRed(85);
                    setGreen(255);
                    setBlue(200);
                    break;
                case 2:
                    setRed(59);
                    setGreen(184);
                    setBlue(242);
                    break;
                case 3:
                    setRed(255);
                    setGreen(89);
                    setBlue(131);
                    break;
                case 4:
                    setRed(216);
                    setGreen(34);
                    setBlue(13);
                    break;
                case 5:
                    setRed(233);
                    setGreen(83);
                    setBlue(131);
                    break;
            }
            break;
        case GRAY:
            switch (colorNum) {
                case 0:
                    setRed(230);
                    setGreen(230);
                    setBlue(230);
                    break;
                case 1:
                    setRed(35);
                    setGreen(35);
                    setBlue(35);
                    break;
                case 2:
                    setRed(25);
                    setGreen(178);
                    setBlue(255);
                    break;
                case 3:
                    setRed(12);
                    setGreen(89);
                    setBlue(127);
                    break;
                case 4:
                    setRed(159);
                    setGreen(0);
                    setBlue(82);
                    break;
                case 5:
                    setRed(221);
                    setGreen(218);
                    setBlue(202);
                    break;
            }
            break;
        case BLUE:
            switch (colorNum) {
                case 0:
                    setRed(6);
                    setGreen(44);
                    setBlue(64);
                    break;
                case 1:
                    setRed(220);
                    setGreen(220);
                    setBlue(220);
                    break;
                case 2:
                    setRed(255);
                    setGreen(50);
                    setBlue(70);
                    break;
                case 3:
                    setRed(11);
                    setGreen(216);
                    setBlue(232);
                    break;
                case 4:
                    setRed(159);
                    setGreen(0);
                    setBlue(82);
                    break;
                case 5:
                    setRed(221);
                    setGreen(218);
                    setBlue(202);
                    break;
            }
            break;
        case PINK:
            switch (colorNum) {
                case 0:
                    setRed(254);
                    setGreen(235);
                    setBlue(200);
                    break;
                case 1:
                    setRed(243);
                    setGreen(168);
                    setBlue(187);
                    break;
                case 2:
                    setRed(255);
                    setGreen(255);
                    setBlue(255);
                    break;
                case 3:
                    setRed(21);
                    setGreen(137);
                    setBlue(229);
                    break;
                case 4:
                    setRed(102);
                    setGreen(43);
                    setBlue(43);
                    break;
                case 5:
                    setRed(251);
                    setGreen(203);
                    setBlue(114);
                    break;
            }
            break;
        case JELLY:
            switch (colorNum) {
                case 0:
                    setRed(235);
                    setGreen(134);
                    setBlue(154);
                    break;
                case 1:
                    setRed(84);
                    setGreen(199);
                    setBlue(239);
                    break;
                case 2:
                    setRed(235);
                    setGreen(245);
                    setBlue(235);
                    break;
                case 3:
                    setRed(175);
                    setGreen(157);
                    setBlue(158);
                    break;
                case 4:
                    setRed(194);
                    setGreen(159);
                    setBlue(239);
                    break;
                case 5:
                    setRed(251);
                    setGreen(203);
                    setBlue(114);
                    break;
            }
            break;
        default:
            break;
    }
}

theme MyColor::getThemeName() {
    return this->themeName;
}

void MyColor::setThemeName(theme themeName) {
    this->themeName = themeName;
}

GLubyte MyColor::getRed() {
    return this->red;
}

void MyColor::setRed(GLubyte red) {
    this->red = red;
}

GLubyte MyColor::getGreen() {
    return this->green;
}

void MyColor::setGreen(GLubyte green) {
    this->green = green;
}

GLubyte MyColor::getBlue() {
    return this->blue;
}

void MyColor::setBlue(GLubyte blue) {
    this->blue = blue;
}

