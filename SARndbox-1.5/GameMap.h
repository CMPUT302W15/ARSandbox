#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "GameIcon.h"

class GameMap
{
    public:
        GameMap();
        virtual ~GameMap();

        int numIcons;
        GameIcon* icons;
    protected:
    private:
};

#endif // GAMEMAP_H
