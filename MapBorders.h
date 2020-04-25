// Map Borders of Section 1

#ifndef MAP_SECTION_H
#define MAP_SECTION_H
//#include <fstream>
//#include <iostream>
//#include "Environment.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class MapBorders
{

public:
    /*  void reader()
    {
        std::string line;
        std::ifstream mapIn("Level_1.map");
        if (mapIn.is_open())
        {
            while (getline(mapIn, line))
            {
                std::cout << line << std::endl;
            }
        }
        mapIn.close();
    }*/

    bool FirstBlock_CanGoUp(float x, float y)
    {

        if  (-8640 < y )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool FirstBlock_CanGoDown(float x, float y)
    {

        if  ( y < 6480)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool FirstBlock_CanGoRight(float x, float y)
    {

        if  ( x < 13440)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool FirstBlock_CanGoLeft(float x, float y)
    {

        if  (-7680 < x )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif