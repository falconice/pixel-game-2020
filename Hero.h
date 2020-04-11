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
    float x, y;

    void setPosition(float x, float y)
    {
        this->x = x;
        this->y = y;
    };

public:
    Hero()
    {
        movementHero.loadFromFile("characters\\spritesheet_Lucy_19_41.png");    //загрузка текстуры движения персонажа  (из файла)
        stayHero.loadFromFile("characters\\spritesheet_LucyStay_41_19.png");    //загрузка текстуры покоя персонажа  (из файла)
        sayNoTexture.loadFromFile("characters\\spritesheet_Lucy_NO_41_19.png"); // загрузка текстуры отрицания действия
        hero.setTextureRect(IntRect(0, 0, 19, 41));                             // "Создаем" персонажа
        hero.setPosition(870, 340);                                             //Задаем начальную позицию
        this->setPosition(870, 340);                                            //Запоминаем начальную позицию

        hero.scale(3.5, 3.5); // Увеличиваем персоажа в размере для нормального отображения
    };

    //-------------GETTTERS----------------------
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

    float getX()
    {
        return this->x;
    }

    float getY()
    {
        return this->y;
    }

    //-------------SETTTERS----------------------
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

    void setY(float y)
    {
        this->y = y;
    };
    void setX(float x)
    {
        this->x = x;
    };

    void changePosition(float OffsetX, float OffsetY)
    {
        setPosition(this->getX() + OffsetX, this->getY() + OffsetY);
    };
};
#endif