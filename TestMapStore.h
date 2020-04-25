//Хранит обьекты Section Blockи подготвылиывет к загрузке и выгрузке
//Хранилище карты отвечает за поиск и отдачу нужных элементов
#ifndef MAP_STORE_H
#define MAP_STORE_H

#include <SFML/Graphics.hpp>
#include "SectionBlock.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace sf;

class MapStore
{
private:
    //String textPaths[153];
    SectionBlock map[14][11];
    int numberStore[14][11];

    void fillNumberStore()
    {
        int count = 1;

        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                numberStore[i][j] = count;
                count++;
            }
        }
    };

    void loadMapFromFile()
    {

        std::string line;
        int number;
        std::ifstream mapIn("block1.description");

        if (mapIn.is_open())
        {
            for (int i = 0; i < 14; i++)
            {
                for (int j = 0; j < 11; j++)
                {

                    if (getline(mapIn, line))
                    {
                        int number, blockNumber;
                        std::string path;
                        float x, y;

                        std::istringstream iss(line);
                        iss >> number >> blockNumber >> path >> x >> y;

                        //if (numberStore[i][j] == number)

                        map[i][j].setSectionBlock(number, blockNumber, path, x, y);
                    }
                }
            }
        }
        mapIn.close();
    }

    int getNumber(float x, float y)
    {
        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if ((map[i][j].getX() <= x && x <= map[i][j].getX() + 1920) &&
                    (map[i][j].getY() <= y && y <= map[i][j].getY() + 1080))
                {
                    return map[i][j].getNumber();
                }
            }
        }
    };

    String getPath(int number)
    {
        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (map[i][j].getNumber() == number)
                {
                    return map[i][j].getTexturePath();
                }
            }
        }
    };

    float getX(int number)
    {
        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (map[i][j].getNumber() == number)
                {
                    return map[i][j].getX();
                }
            }
        }
    };

    float getY(int number)
    {
        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (map[i][j].getNumber() == number)
                {
                    return map[i][j].getY();
                }
            }
        }
    };

public:
    MapStore()
    {
        fillNumberStore();
        loadMapFromFile();
    };

    //возвращает номер блока по координатам

    int getLoadNumber(float x, float y)
    {
        return getNumber(x, y);
    }

    String getTexturePath(int number)
    {
        return getPath(number);
    }

    float getXbyNumber(int number)
    {
        return getX(number);
    }

    float getYbyNumber(int number)
    {
        return getY(number);
    }
};

#endif