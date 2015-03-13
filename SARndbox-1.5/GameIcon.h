#ifndef GAMEICON_H
#define GAMEICON_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/gl.h>

#include <Geometry/ProjectiveTransformation.h>
#include "SurfaceRenderer.h"

class GameIcon
{
    public:
        GameIcon(float x, float y, const char* iconType); // const std::string& filename
        GameIcon();
        virtual ~GameIcon();


        /*Public Elements*/
		enum Type {Mountain, Valley, None};

        float xCoord;
        float yCoord;
		float zValue;

		float scale;
		float xTranslation;
		float yTranslation;

		float DEG2RAD;

		float * data;

		bool complete;

		Type type;
        GLuint texId;

        /*Public methods*/
		void drawIcon(SurfaceRenderer::PTransform transformMatrix);
		void drawCircle();
		void setType(const char* typeString);
		void toggleComplete();
    protected:
    private:
};


#endif // GAMEICON_H
