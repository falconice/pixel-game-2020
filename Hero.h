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

public:
    Hero()
    {
        movementHero.loadFromFile("spritesheet_Lucy.png"); //загрузка текстуры движения персонажа  (из файла)
        stayHero.loadFromFile("spritesheet_LucyStay.png"); //загрузка текстуры покоя персонажа  (из файла)
        hero.setTextureRect(IntRect(0, 0, 64, 64));        // "Создаем" персонажа
        hero.setPosition(0, 0);                            //Задаем начальную позицию
        hero.scale(4, 4);                                  // Увеличиваем персоажа в размере для нормального отображения
    };

    Sprite& getHero() 
    {
        return this->hero;
    };

    Texture&  getMoveTexture()
    {
        return this->movementHero;
    };

    Texture&  getStayTexture()
    {
        return this->stayHero;
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
};
#endif