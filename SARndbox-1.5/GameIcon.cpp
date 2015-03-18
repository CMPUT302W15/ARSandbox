#include "GameIcon.h"
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>


GameIcon::GameIcon(float x, float y, const char* iconType)
{
	//ctor
	xCoord = x;
	yCoord = y;
	complete = false;

	zValue = 0.0f;

	scale = 0.25;
	DEG2RAD = 3.14159/180;

	if (strcasecmp(iconType,"mountain") == 0) {
		type = Mountain;
	}
	else if (strcasecmp(iconType,"valley") == 0) {
		type = Valley;
	}
	else {
		std::cout << "No type found" << std::endl;
	}
}

GameIcon::GameIcon(){
    scale = 0.0;
    zValue = -980.0f;
}

void GameIcon::setType(const char* typeString)
{
	if (strcasecmp(typeString,"mountain") == 0) {
		type = Mountain;
	}
	else if (strcasecmp(typeString,"valley") == 0) {
		type = Valley;
	}
	else {
		std::cout << "No type found" << std::endl;
		type = None;
	}
}

void GameIcon::drawIcon(void)
{
	int numData;

	if (type == Mountain)
	{
		float tempData[] = {
                xCoord + (-1.005*scale), 	yCoord,    				zValue,
				xCoord,						yCoord + (1.99*scale), 	zValue,
		        xCoord + (1.005*scale),  	yCoord,    				zValue,
		        xCoord,						yCoord,    				zValue,

                xCoord + (1.005*scale), 	yCoord,    				zValue,
				xCoord, 					yCoord + (1.99*scale), 	zValue,
				xCoord + (-1.005*scale), 	yCoord,    				zValue,
		        xCoord,    					yCoord,    				zValue,
		    };
		numData = 8*3;
		data = new float[numData];
		data = tempData;

	}
	else if (type == Valley)
	{
		float tempData[] = {
				// second item (left side)
				xCoord + (-1.0*scale),  yCoord + (2.0*scale),  zValue,	// top left
				xCoord + (-1.0*scale),  yCoord + (0.0*scale),  zValue,	// bottom left
				xCoord + (0.0*scale),   yCoord + (0.0*scale),  zValue,	// bottom right
		        xCoord + (-0.75*scale), yCoord + (2.0*scale),  zValue,	// top right

				// first item (right side)
				xCoord + (0.75*scale), 	yCoord + (2.0*scale),  zValue,	// top left
				xCoord + (0.0*scale),  	yCoord + (0.0*scale),  zValue,	// bottom left
				xCoord + (1.0*scale),  	yCoord + (0.0*scale),  zValue,	// bottom right
		        xCoord + (1.0*scale),  	yCoord + (2.0*scale),  zValue,	// top right
		    };
		numData = 8*3;
		data = new float[numData];
		data = tempData;
	}

	glEnable( GL_COLOR_MATERIAL );

	if (!complete)
	{
		// r, g, b
		glColor3f(1.0f, 0.0f, 0.0f);
	}
	else
	{
		// r, g, b
		glColor3f(0.0f, 1.0f, 0.0f);
	}

	glBegin(GL_QUADS);
	for (int i = 0; i < numData; i)
	{
		glVertex3f(data[i], data[i+1], data[i+2]);
		i = i + 3;
	}

	glEnd();
	glFlush();

	//drawCircle();
}

void GameIcon::drawCircle()
{
	float xCenter = 0;
	float yCenter = 0;
	float radius = 0;
	xCoord = 0.0;
	yCoord = 0.0;

	if (type == Mountain)
	{
		xCenter = xCoord;
		yCenter = (yCoord*3 + 1.99*scale)/3;
		radius = yCoord + 1.99*scale - yCenter;
	}
	else if (type == Valley)
	{

		xCenter = xCoord;
		yCenter = yCoord + 1*scale;
		radius = 1.85 * scale;
	}

	for (int i=0; i < 10; i += 1)
	{
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);

        for (int i = 0; i < 360; i++)
        {
            xCenter = radius * cos(i) + xCoord;
            yCenter = radius * sin(i) + yCoord;
            glVertex3f(xCenter,yCenter, zValue);

            xCenter = radius * cos(i + 0.1)  + xCoord;
            yCenter = radius * sin(i + 0.1)  + yCoord;
            glVertex3f(xCenter,yCenter, zValue);
        }
        glEnd();
		glFlush();
		radius += 0.005;
	}
}

void GameIcon::translate(float xTranslation, float yTranslation)
{
	xCoord = xCoord + xTranslation;
	yCoord = yCoord + yTranslation;
}

void GameIcon::toggleComplete()
{
	complete = !complete;
}

GameIcon::~GameIcon()
{
    //dtor
	//delete data;
}
