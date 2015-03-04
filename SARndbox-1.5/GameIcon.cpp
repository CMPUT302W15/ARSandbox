#include "GameIcon.h"
#include <iostream>
#include <string>

GameIcon::GameIcon(float x, float y, const char* iconFilename)
{
    //ctor
    xCoord = x;
    yCoord = y;
    fileName = iconFilename;
    //iconImage = Images::readImageFile(fileName,Vrui::openFile(fileName));
}

void GameIcon::generateImage(void)
{
    //if(fileName)
    //    iconImage = Images::readImageFile(fileName,Vrui::openFile(fileName));
}

GameIcon::GameIcon(){
}

GameIcon::~GameIcon()
{
    //dtor
}
