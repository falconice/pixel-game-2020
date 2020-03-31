//Movemet & Animation for Hero
#ifndef MOVEMET_H
#define MOVEMET_H
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

    void stayCalm()
    {
        float sp = speed();
        mainHero.getHero().setTexture(mainHero.getStayTexture()); // накладываем текстуру покоя персонажа
        currentFrameRest += 0.015 * sp;                           //изменяем переменную кадров для прокрутки анимации
        if (currentFrameRest > 22)
            currentFrameRest -= 22; // прокручиваем анимацию
        mainHero.getHero().setTextureRect(IntRect(64 * int(currentFrameRest), 0, 64, 64));
    };

    void goRight()
    {
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            float sp = speed();
            mainHero.getHero().setTexture(mainHero.getMoveTexture()); // накладываем текстуру движения персонажа
            mainHero.getHero().move(0.1 * sp, 0);                     // походка персонажа==сдвиг его фигуры
            currentFrameUDLR += 0.015 * sp;
            if (currentFrameUDLR > 10) //прокрутка соответствующей анимации
                currentFrameUDLR -= 10;
            mainHero.getHero().setTextureRect(IntRect(64 * int(currentFrameUDLR), 192, 64, 64));
        }
    };

    void goLeft()
    { //аналогично goRight()
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            float sp = speed();
            mainHero.getHero().setTexture(mainHero.getMoveTexture());
            mainHero.getHero().move(-0.1 * sp, 0);
            currentFrameUDLR += 0.015 * sp;
            if (currentFrameUDLR > 10)
                currentFrameUDLR -= 10;
            mainHero.getHero().setTextureRect(IntRect(64 * int(currentFrameUDLR) + 64, 192, -64, 64));
        }
    };

    void goUp()
    {
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            float sp = speed();
            mainHero.getHero().setTexture(mainHero.getMoveTexture());
            mainHero.getHero().move(0, -0.1 * sp);
            currentFrameUDLR += 0.015 * sp;
            if (currentFrameUDLR > 8)
                currentFrameUDLR -= 8;
            mainHero.getHero().setTextureRect(IntRect(64 * int(currentFrameUDLR), 64, 64, 64));
        }
    };

    void goDown()
    {
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            float sp = speed();
            mainHero.getHero().setTexture(mainHero.getMoveTexture());
            mainHero.getHero().move(0, 0.1 * sp);
            currentFrameUDLR += 0.015 * sp;
            if (currentFrameUDLR > 8)
                currentFrameUDLR -= 8;
            mainHero.getHero().setTextureRect(IntRect(64 * int(currentFrameUDLR), 128, 64, 64));
        }
    };
};

#endif