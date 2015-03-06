#include "GameIcon.h"
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

GameIcon::GameIcon(float x, float y, const char* iconType)
{
    //ctor
    xCoord = x;
    yCoord = y;

	zValue = 0.0f;

	x_offset = 0.0f;
	y_offset = 0.0f;
	z_offset = 0.0f;

	scale = 1;

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
	}
}

void GameIcon::generateIcon(void)
{

	float tempData[] = {
		 0.0f + x_offset,  1.0f + y_offset,  0.7f + z_offset,
		 0.5f + x_offset,  0.0f + y_offset, -0.3f + z_offset,
		 //0.0f + x_offset, -0.5f + y_offset, -0.3f + z_offset,
		-0.5f + x_offset,  0.0f + y_offset, -0.3f + z_offset
        };

	// resize icon to new scale
	for (int i = 0; i < sizeof(tempData) / sizeof(float); i) 
	{
		tempData[i] = tempData[i++]*scale;
	}
	
	//data = tempData;
}

void GameIcon::drawIcon(void)
{

	float tempData[] = {
			xCoord*scale, yCoord + (0.50*scale), zValue,
            xCoord + (0.25*scale), yCoord*scale, zValue,
            xCoord*scale, yCoord*scale, zValue,
            xCoord - (0.25*scale), yCoord*scale, zValue,
            
        };

	const GLfloat blue[4] = { .3f, .3f, 1.f, 1.f };

	glEnable( GL_COLOR_MATERIAL );
	//glMaterialfv( GL_FRONT, GL_DIFFUSE, blue );

	glColor3f(0.0f, 0.0f, 1.0f);

	glBegin(GL_QUADS);
	
	glNormal3f(0.0f,0.0f,-1.0f);
	for (int i = 0; i < 12; i) {
		//printf("%f\t%f\t%i\n", data[i], data[i+1],i);
		glVertex3f(tempData[i], tempData[i+1], tempData[i+2]);
		i = i + 3;
	}

	glEnd();
	glFlush();
}

GameIcon::~GameIcon()
{
    //dtor
}
