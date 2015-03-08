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

	scale = 0.50;
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

GameIcon::GameIcon()
{
	//ctor
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
				xCoord,     yCoord + (1.99*scale), zValue,
		        xCoord + (1.005*scale),  yCoord,    zValue,
		        xCoord,     yCoord,    zValue,
		        xCoord + (-1.005*scale), yCoord,    zValue
		    };
		numData = 4*3;
		data = new float[numData];
		data = tempData;
		
	}
	else if (type == Valley)
	{
		float tempData[] = {
				// first item
		        xCoord + (1.0*scale),  yCoord + (0.5*scale),    zValue,
				xCoord + (1.0*scale),  yCoord + (-1.5*scale), zValue,
				xCoord + (1.0*scale),  yCoord + (-1.5*scale), zValue,
		        xCoord + (0.3*scale),  yCoord + (-1.5*scale),    zValue,
				// second item
		        xCoord + (-0.3*scale),  yCoord + (-1.5*scale),    zValue,
				xCoord + (-1.0*scale),  yCoord + (-1.5*scale), zValue,
				xCoord + (-1.0*scale),  yCoord + (-1.5*scale), zValue,
		        xCoord + (-1.0*scale),  yCoord + (0.5*scale),    zValue,
		    };
		numData = 8*3;
		data = new float[numData];
		data = tempData;
	}

	glEnable( GL_COLOR_MATERIAL );

	if (!complete)
	{
		glColor3f(1.0f, 0.0f, 0.0f);
	}
	else
	{
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
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);

	float xCenter = 0;
	float yCenter = 0;
	float radius = 0;

	if (type == Mountain)
	{
		xCenter = (xCoord*3 + 1.005*scale + -1.005*scale)/3;
		yCenter = (yCoord*3 + 1.99*scale)/3;
		radius = yCoord + 1.99*scale - yCenter;
	}
	else if (type == Valley)
	{
		xCenter = (xCoord*3 + 1.005*scale + -1.005*scale)/3;
		yCenter = (yCoord*3 + 1.99*scale)/3;
		radius = yCoord + 1.99*scale - yCenter;
	}

	for (int i=0; i < 360; i++)
	{
		float degInRad = i*DEG2RAD;
		glVertex3f( xCenter + cos(degInRad)*radius,
					yCenter + sin(degInRad)*radius + (2/3)*radius,
					zValue);
	}

	glEnd();
	glFlush();
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
