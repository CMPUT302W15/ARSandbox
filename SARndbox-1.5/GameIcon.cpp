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

	scale = 25.0;
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
    scale = 10.0;
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
    xTranslation = -220.00f;
    yTranslation = -155.00f;
	int numData;

	if (type == Mountain)
	{
		float tempData[] = {
                xCoord + (-1.005*scale) + xTranslation, yCoord + yTranslation,    zValue,
				xCoord + xTranslation,     yCoord + (1.99*scale) + yTranslation, zValue,
		        xCoord + (1.005*scale) + xTranslation,  yCoord + yTranslation,    zValue,
		        xCoord + xTranslation,     yCoord + yTranslation,    zValue,

                xCoord + (1.005*scale) + xTranslation,  yCoord + yTranslation,    zValue,
				xCoord + xTranslation,     yCoord + (1.99*scale) + yTranslation, zValue,
				xCoord + (-1.005*scale) + xTranslation, yCoord + yTranslation,    zValue,
		        xCoord + xTranslation,     yCoord + yTranslation,    zValue,
		    };
		numData = 8*3;
		data = new float[numData];
		data = tempData;

	}
	else if (type == Valley)
	{
		float tempData[] = {
				// second item (left side)
				xCoord + (-1.0*scale) + xTranslation,  yCoord + (2.0*scale) + yTranslation,  zValue,	// top left
				xCoord + (-1.0*scale) + xTranslation,  yCoord + (0.0*scale) + yTranslation,  zValue,	// bottom left
				xCoord + (0.0*scale) + xTranslation,   yCoord + (0.0*scale) + yTranslation,  zValue,	// bottom right
		        xCoord + (-0.75*scale) + xTranslation, yCoord + (2.0*scale) + yTranslation,  zValue,	// top right

				// first item (right side)
				xCoord + (0.75*scale) + xTranslation, yCoord + (2.0*scale) + yTranslation,  zValue,	// top left
				xCoord + (0.0*scale) + xTranslation,  yCoord + (0.0*scale) + yTranslation,  zValue,	// bottom left
				xCoord + (1.0*scale) + xTranslation,  yCoord + (0.0*scale) + yTranslation,  zValue,	// bottom right
		        xCoord + (1.0*scale) + xTranslation,  yCoord + (2.0*scale) + yTranslation,  zValue,	// top right
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

	drawCircle();
}

void GameIcon::drawCircle()
{
	float xCenter = 0;
	float yCenter = 0;
	float radius = 0;

	if (type == Mountain)
	{
		xCenter = xCoord + xTranslation;
		yCenter = (yCoord*3 + 1.99*scale)/3 + yTranslation;
		radius = yCoord + 1.99*scale - yCenter;
	}
	else if (type == Valley)
	{
		xCenter = xCoord + xTranslation;
		yCenter = yCoord + 1*scale + yTranslation;
		radius = 1.85 * scale;
	}

	for (float i=0.00; i < 0.05; i = i +0.001)
	{
		glBegin(GL_LINE_LOOP);
		glColor3f(1.0f, 1.0f, 1.0f);
		for (int f=0; f < 360; f++)
		{
			float degInRad = f*DEG2RAD;
			glVertex3f( xCenter + cos(degInRad)*radius,
						yCenter + sin(degInRad)*radius + (2/3)*radius,
						zValue);
		}
		radius = radius + 0.001;
		glEnd();
		glFlush();
	}
}

void GameIcon::toggleComplete()
{
	complete = !complete;
}

GameIcon::~GameIcon()
{
    //dtor
}
