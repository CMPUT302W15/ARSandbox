#ifndef GAMEICON_H
#define GAMEICON_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <GL/gl.h>
#include <GL/glut.h>

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
		float DEG2RAD;

		float * data;

		bool complete;

		Type type;
        GLuint texId;

        /*Public methods*/
		void drawIcon();
		void drawCircle();
		void setType(const char* typeString);
		void toggleComplete();
		void translate(float xTranslation, float yTranslation);
    protected:
    private:
};


#endif // GAMEICON_H
