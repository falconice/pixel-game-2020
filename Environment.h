//All background stuff
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Environment
{
private:
    Sprite ground;  //земля
    Sprite ground2; //земля
    Sprite grassStone;

    Texture groundTexture; //текстура земли
    Texture grassStoneTexture;

public:
    Environment()
    {
        groundTexture.loadFromFile("map_textures\\ground1920.png"); //загрузка текстуры земли (из файла)
        ground.setTexture(groundTexture);

        grassStoneTexture.loadFromFile("map_textures\\grass_21_20.png");
        grassStone.setTexture(grassStoneTexture);

        grassStone.setTextureRect(IntRect(0, 0, 21, 20));
        grassStone.setPosition(0, 0);
        grassStone.scale(3, 3);

        ground.setTextureRect(IntRect(0, 0, 1920, 1080)); // "Создаем" землю
        ground.setPosition(0, 0);                         //Задаем начальную позицию
        //ground.scale(1.01, 1.01);                               // Увеличиваем  в размере для нормального отображения

       /* ground2.setTexture(groundTexture);
        ground2.setTextureRect(IntRect(0, 0, 1920, 1080)); // "Создаем" землю
        ground2.setPosition(7700, 4500);                   //Задаем начальную позицию
        ground2.scale(4, 4);     */                          // Увеличиваем персоажа в размере для нормального отображения
    };

    Sprite &getGround()
    {
        return this->ground;
    };

    Sprite &getGround2()
    {
        return this->ground2;
    };

    Sprite &getGrassStone()
    {
        return this->grassStone;
    };
};
#endif