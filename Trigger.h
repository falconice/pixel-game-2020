//All trigers include mapTrigers
//Also Animation for Hero

#ifndef TRIGGER_H
#define TRIGGER_H

#include <SFML/Graphics.hpp>

#include "Hero.h"
#include "MapBorders.h"
#include "MapStore.h"

using namespace sf;

class Trigger
{

private:
    Hero mainHero; //Персонаж (а точнее фигура с наложением текстуры персонажа)

    MapBorders mapBordersBlockOne;

    MapStore mapStore;

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
    Trigger(const float *spf) : mapStore()
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
                                                                  // if (mapBordersBlockOne.FirstBlock_CanGoRight(mainHero.getX(), mainHero.getY()) == true)
                                                                  //  {

        if (1850 < mainHero.getX() && mainHero.getX() < 1860)
        {
            mapStore.changeMainFrame(mapStore.getRight(mapStore.getMainFrame())); // берем правого соседа главного кадра и сетим его как главный кадр

            mainHero.changePosition(mapBordersBlockOne.FirstBlock_TeleportRight(mainHero.getX(), mainHero.getY()), 0);
        }

        mainHero.getHero().move(0.1 * sp, 0); // походка персонажа==сдвиг его фигуры
        mainHero.changePosition(0.1 * sp, 0); //Фиксируем координаты

        currentFrameUDLR += 0.015 * sp;
        if (currentFrameUDLR > 10) //прокрутка соответствующей анимации
            currentFrameUDLR -= 10;
        mainHero.getHero().setTextureRect(IntRect(19 * int(currentFrameUDLR), 123, 19, 41));
        // }
        // else
        // {
        //     sayNo();
        // }
    };

    void goLeft()
    { //аналогично goRight()

        float sp = speed();
        mainHero.getHero().setTexture(mainHero.getMoveTexture());
        // if (mapBordersBlockOne.FirstBlock_CanGoLeft(mainHero.getX(), mainHero.getY()) == true)
        // {
        if (mainHero.getX() > -2 && mainHero.getX() < 5)
        {
            mapStore.changeMainFrame(mapStore.getLeft(mapStore.getMainFrame()));

            mainHero.changePosition(mapBordersBlockOne.FirstBlock_TeleportLeft(mainHero.getX(), mainHero.getY()), 0);
        }

        mainHero.getHero().move(-0.1 * sp, 0);
        mainHero.changePosition(-0.1 * sp, 0);

        currentFrameUDLR += 0.015 * sp;
        if (currentFrameUDLR > 10)
            currentFrameUDLR -= 10;
        mainHero.getHero().setTextureRect(IntRect(19 * int(currentFrameUDLR) + 19, 123, -19, 41));
        // }
        // else
        // {
        //     sayNo();
        // }
    };

    void goUp()
    {

        float sp = speed();
        mainHero.getHero().setTexture(mainHero.getMoveTexture());
        // if (mapBordersBlockOne.FirstBlock_CanGoUp(mainHero.getX(), mainHero.getY()) == true)
        // {
        if (mainHero.getY() > -65 && mainHero.getY() < 2)
        {
            mapStore.changeMainFrame(mapStore.getUp(mapStore.getMainFrame()));

            mainHero.changePosition(0, mapBordersBlockOne.FirstBlock_TeleportUp(mainHero.getX(), mainHero.getY()));
        }

        mainHero.getHero().move(0, -0.1 * sp);
        mainHero.changePosition(0, -0.1 * sp);
        //?
        currentFrameUDLR += 0.015 * sp;
        if (currentFrameUDLR > 8)
            currentFrameUDLR -= 8;
        mainHero.getHero().setTextureRect(IntRect(19 * int(currentFrameUDLR), 41, 19, 41));
        // }
        // else
        // {
        //     sayNo();
        // }
    };

    void goDown()
    {
        float sp = speed();
        mainHero.getHero().setTexture(mainHero.getMoveTexture());

        // if (mapBordersBlockOne.FirstBlock_CanGoDown(mainHero.getX(), mainHero.getY()) == true)
        // {

        if (935 < mainHero.getY() && mainHero.getY() < 1005)
        {
            mapStore.changeMainFrame(mapStore.getDown(mapStore.getMainFrame()));

            mainHero.changePosition(0, mapBordersBlockOne.FirstBlock_TeleportDown(mainHero.getX(), mainHero.getY()));
        }
        mainHero.getHero().move(0, 0.1 * sp);
        mainHero.changePosition(0, 0.1 * sp);
        //?
        currentFrameUDLR += 0.015 * sp;
        if (currentFrameUDLR > 8)
            currentFrameUDLR -= 8;
        mainHero.getHero().setTextureRect(IntRect(19 * int(currentFrameUDLR), 82, 19, 41));
        // }
        // else
        // {
        //     sayNo();
        // }
    };

    String getTexturePath()
    {
        return mapStore.getCurrentTexturePath();
    }
    // const Sprite &getBackGround() const
    // {
    //     return mapStore.getGround();
    // }

    /*=========================================MAP TRIGGERS===========================*/

    void printCoordinates()
    {
        std::cout << "\nX: " << getXHero() << ", Y: " << getYHero(); //!!!!!!!!!!!!!!!!
    };
};

#endif