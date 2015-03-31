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
	setType(iconType);
}

GameIcon::GameIcon(){
    scale = 0.0;
    zValue = -980.0f;
}

void GameIcon::setType(const char* typeString)
{
	if (strcasecmp(typeString,"mountain") == 0)
	{
		type = Mountain;
	}
	else if (strcasecmp(typeString,"valley") == 0)
	{
		type = Valley;
	}
	else if (strcasecmp(typeString,"plain") == 0)
	{
		type = Plain;
	}
	else if (strcasecmp(typeString,"ditch") == 0)
	{
		type = Ditch;
	}
	else if (strcasecmp(typeString,"hill") == 0)
	{
		type = Hill;
	}
	else 
	{
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

	else if (type == Plain)
	{
		float tempData[] = {
				xCoord + (-1.0*scale), 	yCoord + (0.5*scale), 	zValue,
				xCoord + (-1.0*scale), 	yCoord + (0.0*scale), 	zValue,
				xCoord, 				yCoord, 				zValue,
				xCoord,				 	yCoord + (0.4*scale), 	zValue,

				xCoord,				 	yCoord + (0.4*scale), 	zValue,
				xCoord, 				yCoord, 				zValue,
				xCoord + (1.0*scale), 	yCoord + (0.0*scale), 	zValue,
				xCoord + (1.0*scale), 	yCoord + (0.5*scale), 	zValue,
			};
		numData = 8*3;
		data = new float[numData];
		data = tempData;
	}

	else if (type == Ditch)
	{
		float tempData[] = {
				xCoord + (-1.0*scale), 	yCoord + (0.5*scale), 	zValue,
				xCoord + (-1.0*scale), 	yCoord + (0.0*scale), 	zValue,
				xCoord + (0.25*scale),	yCoord, 				zValue,
				xCoord + (-0.25*scale),	yCoord + (0.45*scale), 	zValue,

				xCoord + (0.25*scale), 	yCoord + (0.45*scale), 	zValue,
				xCoord + (-0.25*scale),	yCoord, 				zValue,
				xCoord + (1.0*scale), 	yCoord + (0.0*scale), 	zValue,
				xCoord + (1.0*scale), 	yCoord + (0.5*scale), 	zValue,
			};
		numData = 8*3;
		data = new float[numData];
		data = tempData;
	}

	else if (type == Hill)
	{
		float tempData[] = {
				xCoord + (-1.0*scale), 	yCoord + (0.1*scale), 	zValue,
				xCoord + (-1.0*scale), 	yCoord + (0.0*scale), 	zValue,
				xCoord,					yCoord, 				zValue,
				xCoord,					yCoord + (0.5*scale), 	zValue,

				xCoord,					yCoord + (0.5*scale), 	zValue,
				xCoord,					yCoord, 				zValue,
				xCoord + (1.0*scale), 	yCoord + (0.0*scale), 	zValue,
				xCoord + (1.0*scale), 	yCoord + (0.1*scale), 	zValue,
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
	else if (type == Plain)
	{
		radius = 1.20*scale;
	}

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
