#ifndef HERO_H
#define HERO_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Hero
{
private:
    Sprite hero; //герой
    String name; //имя персонажа
    int id;      //персональный id
    int level;
    Texture movementHero; //кадры движения
    Texture stayHero;     //кадры покоя
    Texture sayNoTexture; // кадры отказа от действия

public:
    Hero()
    {
        movementHero.loadFromFile("characters\\spritesheet_Lucy_19_41.png"); //загрузка текстуры движения персонажа  (из файла)
        stayHero.loadFromFile("characters\\spritesheet_LucyStay_41_19.png"); //загрузка текстуры покоя персонажа  (из файла)
        sayNoTexture.loadFromFile("characters\\spritesheet_Lucy_NO_41_19.png");    // загрузка текстуры отрицания действия
        hero.setTextureRect(IntRect(0, 0, 19, 41));              // "Создаем" персонажа
        hero.setPosition(800, 400);                              //Задаем начальную позицию
        hero.scale(3.5, 3.5);                                    // Увеличиваем персоажа в размере для нормального отображения
    };

    Sprite &getHero()
    {
        return this->hero;
    };

    Texture &getMoveTexture()
    {
        return this->movementHero;
    };

    Texture &getStayTexture()
    {
        return this->stayHero;
    };

    Texture &getSayNOTexture()
    {
        return this->sayNoTexture;
    };

    void setHero(Sprite hero)
    {
        this->hero = hero;
    };

    void setMoveTexture(Texture movementTexture)
    {
        this->movementHero = movementTexture;
    };

    void setStayTexture(Texture stayTexture)
    {
        this->movementHero = stayTexture;
    };

    void setSayNoTexture(Texture sayNoTexture)
    {
        this->sayNoTexture = sayNoTexture;
    };
};
#endif