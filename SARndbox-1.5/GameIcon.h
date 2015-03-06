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
		enum Type {Mountain, Valley};

        float xCoord;
        float yCoord;
		float x_offset;
		float y_offset;
		float z_offset;
		float scale;

		float data[];

		Type type;
        GLuint texId;

        /*Public methods*/
        void generateIcon();
		void drawIcon();
		void setType(const char* typeString);
    protected:
    private:
};


#endif // GAMEICON_H
