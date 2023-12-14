// KeyboardControll
#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <SFML/Graphics.hpp>

#include "Trigger.h"

using namespace sf;

class Movement
{
private:
    Trigger trigger;

    float run = 10; // Режим бега
    float walk = 4; // Режим ходьбы

public:
    Movement(const float *spf) : trigger(spf){

                                 };

    const Sprite &getHeroSprite() const
    {
        return trigger.getHeroSprite();
    };

    const float getXHero() const
    {
        return trigger.getXHero();
    };

    const float getYHero() const
    {
        return trigger.getYHero();
    };

    void move()
    {

        // SayNo
        // StayCalm
        // ChangeMode

        if (Keyboard::isKeyPressed(Keyboard::LShift))
        {
            trigger.changeMode();
        }
        else if (Keyboard::isKeyPressed(Keyboard::D))
        {
            trigger.goRight();
        }
        else if (Keyboard::isKeyPressed(Keyboard::A))
        {
            trigger.goLeft();
        }
        else if (Keyboard::isKeyPressed(Keyboard::W))
        {
            trigger.goUp();
        }
        else if (Keyboard::isKeyPressed(Keyboard::S))
        {
            trigger.goDown();
        }
        else if (Keyboard::isKeyPressed(Keyboard::P))
        {
            trigger.printCoordinates();
        }
        else
        {
            trigger.stayCalm();
        }
    }

    inline sf::String getTexturePath()
    {
        return trigger.getTexturePath();
    }
};

#endif