#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "userWindow.h"
using namespace sf;

class Game
{
private:
    userWindow uWindow;

public:
    void play()
    {
        uWindow.startGame();
        //Сделать сохранение
        //Сделать Загрузку
        //TODO : Play, Exit, Save, Load, Mode = (Hard, Normal, Easy)

        // Hero girl;
        //girl.create();
    };
};
#endif