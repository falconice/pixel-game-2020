//Background composition
#ifndef COMPOSITION_H
#define COMPOSITION_H
#include "Environment.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Composition
{
private:
    Environment environment; //окружение

    float currentFrameUDLR; //номер текущего кадра в момент управления
    float currentFrameRest; //номер текущего кадра в момент покоя
    float run = 10;         //Режим бега
    float walk = 4;         //Режим ходьбы
    float mode;             //Переменная режима Бег, Ходьба
    const float *sfp;       //ссылка на sfp из класса UserWindow

    /*float speed()
    { //скорость изменения (движения и анимации)

        return *sfp * mode * 200;
    }*/

public:
    /*void createBackground()
    {
        environment.getGround();
        

    }*/

    const Sprite &getGrassStoneSprite() const
    {
        return environment.getGrassStone();
    }

    /*const  Sprite& getGroundSprite() const
    {
        return environment.getGround();
    }

     const  Sprite& getGroundSprite2() const
    {
        return environment.getGround2();
    }*/

    const Sprite &getGround2Sprite() const
    {
        return environment.getHouse();
    }
};

#endif