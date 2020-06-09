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

        //  if  (-8640 < y )
        if (0 < y)
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

        // if (y < 6480)
        if (y < 940) // <1080 //936.5
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

        //if (x < 13440)
        if (x < 1860) //<1920 // 1853.5
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

        //if (-7680 < x)
        if (0 < x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //bool firstBlockStaircase
    //firstBlock chest

    float FirstBlock_TeleportLeft(float x, float y) //<----
    {
        // if  (-5 < x && x < 5) ///y==const
        // {
        return (+1852);
    }

    float
    FirstBlock_TeleportRight(float x, float y) //---->
    {
        // if  (1850 < x && x < 1860) ///y==const
        // {
        return (-1852);
        // }
    }

    float FirstBlock_TeleportUp(float x, float y) //^
    {
        // if (-65 < y && y < 2)
        // { ///x==const
        return (+935);
        // }
    }

    float FirstBlock_TeleportDown(float x, float y) //v
    {
        // if (935 < y && y < 1005) ///x==const
        // {
        return (-935);
        // }
    }
};

#endif