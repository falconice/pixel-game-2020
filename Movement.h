//KeyboardControll
#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <SFML/Graphics.hpp>

#include "Trigger.h"

using namespace sf;

class Movement
{
private:
    Trigger trigger;

    float run = 10; //Режим бега
    float walk = 4; //Режим ходьбы

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

        //SayNo
        //StayCalm
        //ChangeMode

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

    /*////-----------------------
    //__________________!!!!!DANGER ZONE!!!!_________________
    ///-------GET SPRITES------------
    //1
    const Sprite &getFirstNeighbour() const
    {
        return trigger.getFirstNeighbour();
    };

    Sprite &getFirstNeighbour()
    {
        return trigger.getFirstNeighbour();
    };

    //2
    const Sprite &getSecondNeighbour() const
    {
        return trigger.getSecondNeighbour();
    }

    Sprite &getSecondNeighbour()
    {
        return trigger.getSecondNeighbour();
    }

    //3
    const Sprite &getThirdNeighbour() const
    {
        return trigger.getThirdNeighbour();
    }

    Sprite &getThirdNeighbour()
    {
        return trigger.getThirdNeighbour();
    }

    //4
    const Sprite &getFourthdNeighbour() const
    {
        return trigger.getFourthdNeighbour();
    }

    Sprite &getFourthdNeighbour()
    {
        return trigger.getFourthdNeighbour();
        ;
    }
    //5 CENTRE
    const Sprite &getFifthdNeighbour() const
    {
        return trigger.getFifthdNeighbour();
    }

    Sprite &getFifthdNeighbour()
    {
        return trigger.getFifthdNeighbour();
    }
    //6
    const Sprite &getSixthNeighbour() const
    {
        return trigger.getSixthNeighbour();
    }

    Sprite &getSixthNeighbour()
    {
        return trigger.getSixthNeighbour();
    }

    //7
    const Sprite &getSeventhNeighbour() const
    {
        return trigger.getSeventhNeighbour();
    }

    Sprite &getSeventhNeighbour()
    {
        return trigger.getSeventhNeighbour();
    }

    //8
    const Sprite &getEighthNeighbour() const
    {
        return trigger.getEighthNeighbour();
    }

    Sprite &getEighthNeighbour()
    {
        return trigger.getEighthNeighbour();
    }
    //9
    const Sprite &getNinthNeighbour() const
    {
        return trigger.getNinthNeighbour();
    }

    Sprite &getNinthNeighbour()
    {
        return trigger.getNinthNeighbour();
    }*/
    const Sprite ***getMapSprites() const
    {
        return trigger.getMapSprites();
    };

};

#endif