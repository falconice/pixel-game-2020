//Ground Map
#ifndef MAP_H
#define MAP_H
#include <fstream>
#include <iostream>
//#include "Environment.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Map
{

public:
    void reader()
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
    }
};
#endif