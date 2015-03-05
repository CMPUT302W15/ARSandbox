#ifndef GAMEICON_H
#define GAMEICON_H

#include <iostream>
#include <string>
#include <GL/gl.h>

class GameIcon
{
    public:
        GameIcon(float x, float y, const char* typeString); // const std::string& filename
        GameIcon();
        virtual ~GameIcon();

        enum IconType {Mountain, Valley};


        /*Public Elements*/

        float xCoord;
        float yCoord;
        float zValue;
        float scale;
        IconType type;

        GLuint texId;

        /*Public methods*/
        void generateIcon();
        void setType(const char* typeString);
        void drawIcon();
    protected:
    private:
};
#endif // GAMEICON_H
