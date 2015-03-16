#include "GameIcon.h"
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <Geometry/ProjectiveTransformation.h>
#include "SurfaceRenderer.h"




GameIcon::GameIcon(float x, float y, const char* iconType)
{
    //ctor
   	//SurfaceRenderer::PTransform::Point p1 = transformMatrix.transform(SurfaceRenderer::PTransform::Point(x, y, zValue));

    xCoord = x;
    yCoord = y;
	complete = false;

	kinectSpaceX = x;
	kinectSpaceY = y;
	kinectSpaceZ = 0.0f;

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
    scale = 25.0;
    zValue = 720.0f;
    complete = false;
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

void GameIcon::drawIcon(SurfaceRenderer::PTransform transformMatrix)
{
    xTranslation = 0;//-220.00f;
    yTranslation = 0;//-155.00f;
	int numData;
    //std::cout<<"Normal x="<<xCoord<<" y="<<yCoord<<" z="<<zValue<<std::endl;
	//SurfaceRenderer::PTransform::Point p1 = transformMatrix.transform(SurfaceRenderer::PTransform::Point(xCoord, yCoord, zValue));
	//std::cout<<"Transformed x="<<p1[0]<<" y="<<p1[1]<<" z="<<p1[2]<<std::endl;

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

        /**float tempData[] = {
                p1[0] + (-1.005*scale) + xTranslation, p1[1] + yTranslation,    p1[2],
				p1[0] + xTranslation,     p1[1] + (1.99*scale) + yTranslation, p1[2],
		        p1[0] + (1.005*scale) + xTranslation,  p1[1] + yTranslation,    p1[2],
		        p1[0] + xTranslation,     p1[1] + yTranslation,    p1[2],

                p1[0] + (1.005*scale) + xTranslation,  p1[1] + yTranslation,    p1[2],
				p1[0] + xTranslation,     p1[1] + (1.99*scale) + yTranslation, p1[2],
				p1[0] + (-1.005*scale) + xTranslation, p1[1] + yTranslation,    p1[2],
		        p1[0] + xTranslation,     p1[1] + yTranslation,    p1[2],
		    };**/
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
            /**float tempData[] = {
				// second item (left side)
				p1[0] + (-1.0*scale) + xTranslation,  p1[1] + (2.0*scale) + yTranslation,  p1[2],	// top left
				p1[0] + (-1.0*scale) + xTranslation,  p1[1] + (0.0*scale) + yTranslation,  p1[2],	// bottom left
				p1[0] + (0.0*scale) + xTranslation,   p1[1] + (0.0*scale) + yTranslation,  p1[2],	// bottom right
		        p1[0] + (-0.75*scale) + xTranslation, p1[1] + (2.0*scale) + yTranslation,  p1[2],	// top right

				// first item (right side)
				p1[0] + (0.75*scale) + xTranslation, p1[1] + (2.0*scale) + yTranslation,  p1[2],	// top left
				p1[0] + (0.0*scale) + xTranslation,  p1[1] + (0.0*scale) + yTranslation,  p1[2],	// bottom left
				p1[0] + (1.0*scale) + xTranslation,  p1[1] + (0.0*scale) + yTranslation,  p1[2],	// bottom right
		        p1[0] + (1.0*scale) + xTranslation,  p1[1] + (2.0*scale) + yTranslation,  p1[2],	// top right
		    };**/
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
		xCenter = xCoord;//+ xTranslation;
		yCenter = (yCoord*3 + 1.99*scale)/3 ;//+ yTranslation;
		radius = yCoord + 1.99*scale - yCenter;
	}
	else if (type == Valley)
	{
		xCenter = xCoord;//+ xTranslation;
		yCenter = yCoord + 1*scale ;//+ yTranslation;
		radius = 1.85 * scale;
	}

	for (int i=0; i < 10; i++)
	{
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);

        for (int i = 0; i < 180; i++)
        {
            xCenter = radius * cos(i) + xCoord;
            yCenter = radius * sin(i) + yCoord;
            glVertex3f(xCenter,yCenter, zValue);

            xCenter = radius * cos(i + 0.1) + xCoord;
            yCenter = radius * sin(i + 0.1) + yCoord;
            glVertex3f(xCenter,yCenter, zValue);
        }
        glEnd();
        glFlush();
        radius += 0.005;
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
