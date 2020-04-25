//  Класс, отвечающий за описание блока карты 1920 на 1080, хранит его (??текстуру), номер на поле и номер загрузки
#ifndef TEST_SECTION_BLOCK_H
#define TEST_SECTION_BLOCK_H
//#include <fstream>
#include <iostream>
//#include "Environment.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class SectionBlock
{
private:
    int number;
    int blockNumber;
    std::string texturePath;
    float x, y;
    //  int loadNumber;

    // Sprite ground;
    // Texture groundTexture;

public:
    void setSectionBlock(int number, int blockNumber, std::string texturePath, float x, float y)
    {
        this->number = number;
        // std::cout << texturePath << std::endl;
        this->blockNumber = blockNumber;
        this->texturePath = texturePath;
        this->x = x;
        this->y = y;

        //groundTexture.loadFromFile(textureFile); //загрузка текстуры земли (из файла)
        // ground.setTexture(groundTexture);
        //ground.setTextureRect(IntRect(0, 0, 1920, 1080)); // "Создаем" землю
        // ground.setPosition(x, y);                         //Задаем начальную позицию
    };

    /* const Sprite &getGround() const
    {
        return this->ground;
    }*/

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
};

#endif