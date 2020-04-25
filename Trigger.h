//All trigers include mapTrigers
//Also Animation for Hero

#ifndef TRIGGER_H
#define TRIGGER_H

#include <SFML/Graphics.hpp>

#include "Hero.h"
#include "MapBorders.h"
//#include "mainHero.h"

using namespace sf;

class Trigger
{

private:
    Hero mainHero; //Персонаж (а точнее фигура с наложением текстуры персонажа)

    MapBorders mapBordersBlockOne;

    // mainHero mainHero;

    float currentFrameUDLR; //номер текущего кадра в момент управления
    float currentFrameRest; //номер текущего кадра в момент покоя
    float run = 10;         //Режим бега
    float walk = 4;         //Режим ходьбы
    float mode;             //Переменная режима в которм персонаж передвигается
    const float *spf;       //ссылка на sfp из класса UserWindow

    float speed()
    { //скорость изменения (движения и анимации)

        return *spf * mode * 200;
    };

public:
    Trigger(const float *spf) //: mainHero()
    {
        this->spf = spf; //записываем количество секнд на кадр
        currentFrameUDLR = 0;
        currentFrameRest = 0;
        mode = walk; //режим передвижения {ходьба, бег}
    };

    /*==========================================================GETTERS=======================*/

    const Sprite &getHeroSprite() const
    {
        return mainHero.getHero();
    };

    const float getXHero() const
    {
        return mainHero.getX();
    };

    const float getYHero() const
    {
        return mainHero.getY();
    };

    /*=======================================================SETTTINGS TRIGGERS====================================================*/

    void changeMode()
    {
        if (mode == walk)
        {
            mode = run;
        }
        else
        {
            mode = walk;
        }
    }

    /*=======================================================HERO TRIGGERS==========================================================*/
    void sayNo()
    {

        float sp = speed();
        mainHero.getHero().setTexture(mainHero.getSayNOTexture()); // накладываем текстуру покоя персонажа
        currentFrameRest += 0.005 * sp;                            //изменяем переменную кадров для прокрутки анимации
        if (currentFrameRest > 39)
            currentFrameRest -= 39; // прокручиваем анимацию
        mainHero.getHero().setTextureRect(IntRect(19 * int(currentFrameRest), 0, 19, 41));
    };

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

        float sp = speed();
        mainHero.getHero().setTexture(mainHero.getMoveTexture()); // накладываем текстуру движения персонажа
        if (mapBordersBlockOne.FirstBlock_CanGoRight(mainHero.getX(), mainHero.getY()) == true)
        {
            mainHero.getHero().move(0.1 * sp, 0); // походка персонажа==сдвиг его фигуры
            mainHero.changePosition(0.1 * sp, 0); //Фиксируем координаты

            currentFrameUDLR += 0.015 * sp;
            if (currentFrameUDLR > 10) //прокрутка соответствующей анимации
                currentFrameUDLR -= 10;
            mainHero.getHero().setTextureRect(IntRect(19 * int(currentFrameUDLR), 123, 19, 41));
        }
        else
        {
            sayNo();
        }
    };

    void goLeft()
    { //аналогично goRight()

        float sp = speed();
        mainHero.getHero().setTexture(mainHero.getMoveTexture());
        if (mapBordersBlockOne.FirstBlock_CanGoLeft(mainHero.getX(), mainHero.getY()) == true)
        {
            mainHero.getHero().move(-0.1 * sp, 0);
            mainHero.changePosition(-0.1 * sp, 0);

            currentFrameUDLR += 0.015 * sp;
            if (currentFrameUDLR > 10)
                currentFrameUDLR -= 10;
            mainHero.getHero().setTextureRect(IntRect(19 * int(currentFrameUDLR) + 19, 123, -19, 41));
        }
        else
        {
            sayNo();
        }
    };

    void goUp()
    {

        float sp = speed();
        mainHero.getHero().setTexture(mainHero.getMoveTexture());
        if (mapBordersBlockOne.FirstBlock_CanGoUp(mainHero.getX(), mainHero.getY()) == true)
        {
            mainHero.getHero().move(0, -0.1 * sp);
            mainHero.changePosition(0, -0.1 * sp);
            currentFrameUDLR += 0.015 * sp;
            if (currentFrameUDLR > 8)
                currentFrameUDLR -= 8;
            mainHero.getHero().setTextureRect(IntRect(19 * int(currentFrameUDLR), 41, 19, 41));
        }
        else
        {
            sayNo();
        }
    };

    void goDown()
    {

        if (mapBordersBlockOne.FirstBlock_CanGoDown(mainHero.getX(), mainHero.getY()) == true)
        {
            float sp = speed();
            mainHero.getHero().setTexture(mainHero.getMoveTexture());
            mainHero.getHero().move(0, 0.1 * sp);
            mainHero.changePosition(0, 0.1 * sp);
            currentFrameUDLR += 0.015 * sp;
            if (currentFrameUDLR > 8)
                currentFrameUDLR -= 8;
            mainHero.getHero().setTextureRect(IntRect(19 * int(currentFrameUDLR), 82, 19, 41));
        }
        else
        {
            sayNo();
        }
    };

    /*=========================================MAP TRIGGERS===========================*/

    void printCoordinates()
    {
        std::cout << "\nX: " << getXHero() << ", Y: " << getYHero(); //!!!!!!!!!!!!!!!!
    };

   /* //__________________!!!!!DANGER ZONE!!!!_________________
    ///-------GET SPRITES------------
    //1
    const Sprite &getFirstNeighbour() const
    {
        return mainHero.getFirstNeighbour();
    };

    Sprite &getFirstNeighbour()
    {
        return mainHero.getFirstNeighbour();
    };

    //2
    const Sprite &getSecondNeighbour() const
    {
        return mainHero.getSecondNeighbour();
    }

    Sprite &getSecondNeighbour()
    {
        return mainHero.getSecondNeighbour();
    }

    //3
    const Sprite &getThirdNeighbour() const
    {
        return mainHero.getThirdNeighbour();
    }

    Sprite &getThirdNeighbour()
    {
        return mainHero.getThirdNeighbour();
    }

    //4
    const Sprite &getFourthdNeighbour() const
    {
        return mainHero.getFourthdNeighbour();
    }

    Sprite &getFourthdNeighbour()
    {
        return mainHero.getFourthdNeighbour();
        ;
    }
    //5 CENTRE
    const Sprite &getFifthdNeighbour() const
    {
        return mainHero.getFifthdNeighbour();
    }

    Sprite &getFifthdNeighbour()
    {
        return mainHero.getFifthdNeighbour();
    }
    //6
    const Sprite &getSixthNeighbour() const
    {
        return mainHero.getSixthNeighbour();
    }

    Sprite &getSixthNeighbour()
    {
        return mainHero.getSixthNeighbour();
    }

    //7
    const Sprite &getSeventhNeighbour() const
    {
        return mainHero.getSeventhNeighbour();
    }

    Sprite &getSeventhNeighbour()
    {
        return mainHero.getSeventhNeighbour();
    }

    //8
    const Sprite &getEighthNeighbour() const
    {
        return mainHero.getEighthNeighbour();
    }

    Sprite &getEighthNeighbour()
    {
        return mainHero.getEighthNeighbour();
    }
    //9
    const Sprite &getNinthNeighbour() const
    {
        return mainHero.getNinthNeighbour();
    }

    Sprite &getNinthNeighbour()
    {
        return mainHero.getNinthNeighbour();
    }*/
    const Sprite ***getMapSprites() const
    {
        return mainHero.getMapSprites();
    }
};

#endif