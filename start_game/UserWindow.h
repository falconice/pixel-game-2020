// User Inteface
#ifndef USERWINDOW_H
#define USERWINDOW_H

#include "launcher.h"

class UserWindow
{
private:
    Launcher launcher;

public:
    void startGame()
    {
        launcher.launch();
    }

    //Сделать сохранение
    // void saveGame();
    //Сделать Загрузку
    // void loadGame();
};
#endif