#ifndef WINDOW_LOADER_H
#define WINDOW_LOADER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Movement.h"
#include "Composition.h"

#include "Camera.h"
using namespace sf;

class WindowLoader
{
public:
    void createQueue(RenderWindow *window, Composition back, Movement moveMainHero)
    {
        window->setView(view);
        window->clear();
        window->draw(back.getGroundSprite());
       // window->draw(back.getGround2Sprite());

        window->draw(back.getGrassStoneSprite());
        window->draw(moveMainHero.getHeroSprite());

      
    }
};

#endif