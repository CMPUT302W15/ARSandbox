#include "GameIcon.h"
#include <iostream>
#include <string>

GameIcon::GameIcon(float x, float y, const char* iconType)
{
    //ctor
    xCoord = x;
    yCoord = y;
	type = iconType;
	
}

GameIcon::GameIcon()
{
	//ctor
}

void GameIcon::generateImage(void)
{
}

GameIcon::~GameIcon()
{
    //dtor
}
