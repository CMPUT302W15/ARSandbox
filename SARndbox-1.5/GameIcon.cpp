#include "GameIcon.h"
#include <iostream>
#include <string.h>
#include <GL/gl.h>
#include <GL/GLMaterial.h>
#include <stdlib.h>



GameIcon::GameIcon(float x, float y, const char* typeString)
{
    //ctor
    xCoord = x;
    yCoord = y;

    zValue = -1000.0f;

    scale = 1;

    if (strcasecmp(typeString, "mountain") == 0)
    {
        type = Mountain;
    }
}

GameIcon::GameIcon(){
    scale = 1;
    zValue = -1000.0f;

}

void GameIcon::generateIcon(void)
{
}

void GameIcon::setType(const char* typeString)
{
    if (strcasecmp(typeString, "mountain") == 0)
    {
        type = Mountain;
    }
}

void GameIcon::drawIcon()
{
    if (type == Mountain)
    {
        float tempData[] = {
            xCoord - (25*scale), yCoord, zValue,
            xCoord + (25*scale), yCoord, zValue,
            xCoord, yCoord + (50*scale), zValue
        };


        // innit opengl for our icon
        //glMaterial(GLMaterialEnums::FRONT,GLMaterial(GLMaterial::Color(0.7f,0.7f,0.7f)));

        glBegin(GL_QUADS);
        // draw
        for (int i = 0; i < sizeof(tempData)/sizeof(float);i = i + 3)
        {
            glVertex3f(tempData[i], tempData[i+1], tempData[i+2]);

        }
        glEnd();

    }
}

GameIcon::~GameIcon()
{
    //dtor
}
