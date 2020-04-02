//Movemet & Animation for Hero
#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "Hero.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Movement
{
private:
    Hero mainHero; //Персонаж (а точнее фигура с наложением текстуры персонажа)

    float currentFrameUDLR; //номер текущего кадра в момент управления
    float currentFrameRest; //номер текущего кадра в момент покоя
    float run = 10;         //Режим бега
    float walk = 4;         //Режим ходьбы
    float mode;             //Переменная режима в которм персонаж передвигается
    const float *sfp;       //ссылка на sfp из класса UserWindow

    float speed()
    { //скорость изменения (движения и анимации)

        return *sfp * mode * 200;
    };

public:
    Movement(const float *sfp)
    {
        this->sfp = sfp; //записываем количество секнд на кадр
        currentFrameUDLR = 0;
        currentFrameRest = 0;
        mode = walk; //режим передвижения {ходьба, бег}
    };

    Sprite &getHeroSprite()
    {
        return mainHero.getHero();
    };

    void sayNo()
    {
        if (Keyboard::isKeyPressed(Keyboard::N))
        {
            float sp = speed();
            mainHero.getHero().setTexture(mainHero.getSayNOTexture()); // накладываем текстуру покоя персонажа
            currentFrameRest += 0.005 * sp;                            //изменяем переменную кадров для прокрутки анимации
            if (currentFrameRest > 39)
                currentFrameRest -= 39; // прокручиваем анимацию
            mainHero.getHero().setTextureRect(IntRect(19 * int(currentFrameRest), 0, 19, 41));
        }
    }

    void stayCalm()
    {
        float sp = speed();
        mainHero.getHero().setTexture(mainHero.getStayTexture()); // накладываем текстуру покоя персонажа
        currentFrameRest += 0.015 * sp;                           //изменяем переменную кадров для прокрутки анимации
        if (currentFrameRest > 22)
            currentFrameRest -= 22; // прокручиваем анимацию
        mainHero.getHero().setTextureRect(IntRect(19 * int(currentFrameRest), 0, 19, 41));
    };

    void goRight()
    {
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            float sp = speed();
            mainHero.getHero().setTexture(mainHero.getMoveTexture()); // накладываем текстуру движения персонажа
            mainHero.getHero().move(0.1 * sp, 0);                     // походка персонажа==сдвиг его фигуры
            currentFrameUDLR += 0.015 * sp;
            if (currentFrameUDLR > 10) //прокрутка соответствующей анимации
                currentFrameUDLR -= 10;
            mainHero.getHero().setTextureRect(IntRect(19 * int(currentFrameUDLR), 123, 19, 41));
        }
    };

    void goLeft()
    { //аналогично goRight()
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            float sp = speed();
            mainHero.getHero().setTexture(mainHero.getMoveTexture());
            mainHero.getHero().move(-0.1 * sp, 0);
            currentFrameUDLR += 0.015 * sp;
            if (currentFrameUDLR > 10)
                currentFrameUDLR -= 10;
            mainHero.getHero().setTextureRect(IntRect(19 * int(currentFrameUDLR) + 19, 123, -19, 41));
        }
    };

    void goUp()
    {
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            float sp = speed();
            mainHero.getHero().setTexture(mainHero.getMoveTexture());
            mainHero.getHero().move(0, -0.1 * sp);
            currentFrameUDLR += 0.015 * sp;
            if (currentFrameUDLR > 8)
                currentFrameUDLR -= 8;
            mainHero.getHero().setTextureRect(IntRect(19 * int(currentFrameUDLR), 41, 19, 41));
        }
    };

    void goDown()
    {
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            float sp = speed();
            mainHero.getHero().setTexture(mainHero.getMoveTexture());
            mainHero.getHero().move(0, 0.1 * sp);
            currentFrameUDLR += 0.015 * sp;
            if (currentFrameUDLR > 8)
                currentFrameUDLR -= 8;
            mainHero.getHero().setTextureRect(IntRect(19 * int(currentFrameUDLR), 82, 19, 41));
        }
    };
};

#endif