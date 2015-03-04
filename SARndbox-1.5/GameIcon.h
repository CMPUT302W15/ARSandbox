#ifndef GAMEICON_H
#define GAMEICON_H

#include <iostream>
#include <string>
#include <GL/gl.h>

class GameIcon
{
    public:
        GameIcon(float x, float y, const char* iconType); // const std::string& filename
        GameIcon();
        virtual ~GameIcon();

        /*Public Elements*/
        float xCoord;
        float yCoord;
        const char* type;
        GLuint texId;

        /*Public methods*/
        void generateImage();
    protected:
    private:
};

enum Type {Mountain, Valley, River};

#endif // GAMEICON_H
