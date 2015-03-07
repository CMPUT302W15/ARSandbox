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

    zValue = -900.0f;

    scale = 100;

    if (strcasecmp(typeString, "mountain") == 0)
    {
        type = Mountain;
    }
}

GameIcon::GameIcon(){
    scale = 100;
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

void GameIcon::drawIcon(void)
{
	float tempData[] = {
			xCoord,     yCoord + (1.50*scale), zValue,
            xCoord + (1.25*scale),  yCoord,    zValue,
            xCoord,     yCoord,    zValue,
            xCoord + (-1.25*scale), yCoord,    zValue
        };

    glPushAttrib(GL_ENABLE_BIT);

    glEnable( GL_COLOR_MATERIAL );
    glColor3f(1.0f, 0.5f, 0.0f);

    glBegin(GL_QUADS);

    for (int i = 0; i < 12; i) {
        //printf("%f\t%f\t%i\n", data[i], data[i+1],i);
        std::cout << "x:";
        std::cout << tempData[i];
        std::cout << "  y:";
        std::cout << tempData[i+1];
        std::cout << " z:";
        std::cout << tempData[i+2] << std::endl;
        glVertex3f(tempData[i], tempData[i+1], tempData[i+2]);
        i = i + 3;
    }
    glEnd();
    //glFlush();
    glPopAttrib();
}

GameIcon::~GameIcon()
{
    //dtor
}
