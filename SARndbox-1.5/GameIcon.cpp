#include "GameIcon.h"
#include <iostream>
#include <string>
#include <Images/RGBImage.h>
#include <Images/GetImageFileSize.h>
#include <Images/ReadImageFile.h>
#include <IO/File.h>
#include <IO/Directory.h>

GameIcon::GameIcon(float x, float y, Images::RGBImage i) //,const string& filename
{
    //ctor
    xCoord = x;
    yCoord = y;
    //iconFilename = filename;
    iconImage = i;
}

GameIcon::~GameIcon()
{
    //dtor
}
