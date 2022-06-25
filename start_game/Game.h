#ifndef GAME_H
#define GAME_H

#include "userWindow.h"

class Game
{
private:
    UserWindow uWindow;

public:
    // TODO : Play, Exit, Save, Load, Mode = (Hard, Normal, Easy)
    void play()
    {
        uWindow.startGame();
    };
};
#endif