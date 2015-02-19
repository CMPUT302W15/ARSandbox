#include "GameIcon.h"
#include <iostream>
#include <string>
#include <Images/RGBImage.h>
#include <Images/GetImageFileSize.h>
#include <Images/ReadImageFile.h>
#include <IO/File.h>
#include <IO/Directory.h>
#include <Vrui/Vrui.h>
#include <Vrui/OpenFile.h>

GameIcon::GameIcon(float x, float y, const char* iconFilename)
{
    //ctor
    xCoord = x;
    yCoord = y;
    fileName = iconFilename;
    iconImage = Images::readImageFile(fileName,Vrui::openFile(fileName));
}

void GameIcon::generateImage(void)
{
    if(fileName)
        iconImage = Images::readImageFile(fileName,Vrui::openFile(fileName));
}

GameIcon::GameIcon(){
}

GameIcon::~GameIcon()
{
    //dtor
}
