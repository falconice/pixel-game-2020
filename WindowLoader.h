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
private:
    Sprite background;         // задний план
    Texture backgroundTexture; //текстура земли
    String oldTexturePath = "";

    void LoadGround(RenderWindow *window, Movement &moveMainHero)
    {
        if (oldTexturePath != moveMainHero.getTexturePath())
        {
            backgroundTexture.loadFromFile(moveMainHero.getTexturePath()); //загрузка текстуры земли (из файла)
            oldTexturePath = moveMainHero.getTexturePath();
            background.setTexture(backgroundTexture);
            background.setTextureRect(IntRect(0, 0, 1920, 1080)); // "Создаем" землю
            background.setPosition(0, 0);
        }
    }

public:
    WindowLoader()
    {
    }
    void createQueue(RenderWindow *window, const Composition &back, Movement &moveMainHero)
    {
        LoadGround(window, moveMainHero);
        // window->setView(view);

        window->clear();

         window->draw(background);

        window->draw(back.getGrassStoneSprite());
        window->draw(moveMainHero.getHeroSprite());
    }
};

#endif