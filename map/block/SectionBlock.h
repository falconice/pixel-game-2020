//  Класс, отвечающий за описание блока карты 1920 на 1080, хранит его данные : путь к текстуре (??текстуру), номер на поле и координаты
#ifndef TEST_SECTION_BLOCK_H
#define TEST_SECTION_BLOCK_H
//#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "BlockTrigger.h"

using namespace sf;

class SectionBlock
{
private:
    int number;
    std::string texturePath;
    float x, y;

    int nieghbourUp, neighbourDown, neighbourLeft, neighbourRight;


public:
    void setSectionBlock(int number, std::string texturePath, float x, float y)
    {
        this->number = number;
      
        this->texturePath = texturePath;
        this->x = x;
        this->y = y;
        this->nieghbourUp = (number <= 11 ? 0 : number - 11);
        this->neighbourRight = (number % 11 == 0 ? 0 : number + 1);
        this->neighbourDown = (number >= 144 ? 0 : number + 11);
        this->neighbourLeft = (number % 11 == 1 ? 0 : number - 1);

    };


    float getX() //координата верхнего левого угла
    {
        return this->x;
    }

    float getY() //координата верхнего левого угла
    {
        return this->y;
    }

    int getNumber()
    {
        return this->number;
    }

    String getTexturePath()
    {
        return String(this->texturePath);
    }

    int getRightNeighbour()
    {
        return this->neighbourRight;
    };

    int getLeftNeighbour()
    {
        return this->neighbourLeft;
    };

    int getUpNeighbour()
    {
        return this->nieghbourUp;
    };

    int getDownNeighbour()
    {
        return this->neighbourDown;
    };

    SectionBlock getSectionBlock()
    {
        return *this;
    }


};

#endif