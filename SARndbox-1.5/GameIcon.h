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
<<<<<<< HEAD
=======
		float xTranslation;
		float yTranslation;
>>>>>>> 5b436f7682cca1f87b7f8d14daabb2eeee250548

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
    protected:
    private:
};


#endif // GAMEICON_H
