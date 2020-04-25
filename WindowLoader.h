#ifndef WINDOW_LOADER_H
#define WINDOW_LOADER_H

#include <SFML/Graphics.hpp>
#include <iostream>
//#include "ActiveMap.h"
#include "Movement.h"
#include "Composition.h"

#include "Camera.h"
using namespace sf;

class WindowLoader
{
private:
    //ActiveMap activeMap;

    const Sprite ***map;

    void LoadGround(RenderWindow *window, const Movement &moveMainHero)
    {
        // activeMap.changePosition(moveMainHero.getXHero(), moveMainHero.getYHero());

        //window->draw(moveMainHero.getFirstNeighbour());
        //  window->draw(moveMainHero.getSecondNeighbour());
        //window->draw(moveMainHero.getThirdNeighbour());

        // window->draw(moveMainHero.getFourthdNeighbour());
        // window->draw(moveMainHero.getFifthdNeighbour());
        // window->draw(moveMainHero.getSixthNeighbour());

        // window->draw(moveMainHero.getSeventhNeighbour());
        //  window->draw(moveMainHero.getEighthNeighbour());
        // window->draw(moveMainHero.getNinthNeighbour());

        map = moveMainHero.getMapSprites();

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                window->draw(*((const Sprite *(*)[3])map)[i][j]);
            }
        }

        // back.getGroundSprite());
        // window->draw(back.getGroundSprite2());
    }

public:
    WindowLoader() //: activeMap()
    {
    }
    void createQueue(RenderWindow *window, const Composition &back, const Movement &moveMainHero)
    {
       // window->setView(view);
        window->clear();

        LoadGround(window, moveMainHero);

        window->draw(back.getGrassStoneSprite());
        window->draw(moveMainHero.getHeroSprite());
    }
};

#endif