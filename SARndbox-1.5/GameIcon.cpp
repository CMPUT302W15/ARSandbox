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

GameIcon::GameIcon(float x, float y, char* iconFilename) //,const string& filename
{
    //ctor
    xCoord = x;
    yCoord = y;
    //iconFilename = filename;
    iconImage = Images::readImageFile(iconFilename,Vrui::openFile(iconFilename));
}

GameIcon::~GameIcon()
{
    //dtor
}
