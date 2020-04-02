//User Inteface
#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "launcher.h"
using namespace sf;

class userWindow
{
private:
    Launcher launcher;

public:
    void startGame()
    {
        launcher.launch();
    }
};
#endif