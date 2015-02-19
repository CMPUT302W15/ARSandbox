#ifndef GAMEICON_H
#define GAMEICON_H

#include <Images/RGBImage.h>
#include <Images/GetImageFileSize.h>
#include <Images/ReadImageFile.h>
#include <IO/File.h>
#include <IO/Directory.h>
#include <iostream>
#include <string>
#include <GL/gl.h>

class GameIcon
{
    public:
        GameIcon(float x, float y, char* iconFilename); // const std::string& filename
        virtual ~GameIcon();

        /*Public Elements*/
        float xCoord;
        float yCoord;
        Images::RGBImage iconImage;
        GLuint texId;
    protected:
    private:
};

#endif // GAMEICON_H
