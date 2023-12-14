#ifndef HERO_H
#define HERO_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Hero
{
private:
    Sprite hero; // герой
    String name; // имя персонажа
    int id;      // персональный id
    int level;
    Texture movementHero; // кадры движения
    Texture stayHero;     // кадры покоя
    Texture sayNoTexture; // кадры отказа от действия
    float x, y;

    void setPosition(float x, float y)
    {
        this->x = x;
        this->y = y;
        hero.setPosition({x, y});
    };

public:
    Hero()
    {
        movementHero.loadFromFile("characters_textures\\spritesheet_Lucy_19_41.png");    // загрузка текстуры движения персонажа  (из файла)
        stayHero.loadFromFile("characters_textures\\spritesheet_LucyStay_41_19.png");    // загрузка текстуры покоя персонажа  (из файла)
        sayNoTexture.loadFromFile("characters_textures\\spritesheet_Lucy_NO_41_19.png"); // загрузка текстуры отрицания действия
        hero.setTextureRect(sf::Rect<int>({0, 0}, {19, 41}));                            // "Создаем" персонажа
        /* // hero.setPosition(870, 340);                                             //Задаем начальную позицию*/
        this->setPosition(870, 340); // Запоминаем начальную позицию

        hero.scale({(double)(3.5), (double)(3.5)}); // Увеличиваем персоажа в размере для нормального отображения
    };

    //-------------GETTTERS----------------------
    const Sprite &getHero() const
    {
        return this->hero;
    }
    Sprite &getHero()
    {
        return this->hero;
    }

    const Texture &getMoveTexture() const
    {
        return this->movementHero;
    }

    const Texture &getStayTexture() const
    {
        return this->stayHero;
    };

    const Texture &getSayNOTexture() const
    {
        return this->sayNoTexture;
    };

    const float getX() const
    {
        return this->x;
    }

    const float getY() const
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

    //---------Other Getter
};
#endif