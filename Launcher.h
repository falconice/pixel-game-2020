//User Inteface
#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Movement.h"
#include "Composition.h"
using namespace sf;

class Launcher
{
private:
    Composition back;

    Clock clock; //Для нормального движения персонажей
    float sfp;   //секунд на кадр

    VideoMode mode;        //формат окна
    String title;          //название окна
    RenderWindow *window;  //для пересоздания окна при переключении режимов
    Movement moveMainHero; //двигающийся персонаж

public:
    Launcher() : moveMainHero(&sfp)
    { //конструктор окна
        mode = VideoMode().getDesktopMode();
        title = "Pixel Game 2020";
        window = new RenderWindow(mode, title, Style::Fullscreen); //Игровое окно, на весь экран
        window->setVerticalSyncEnabled(true);                      //vsync on
        window->setFramerateLimit(60);                             //fps 60
    }

    void launch()
    {
        //открытие окна

        window->display();
        while (window->isOpen())
        {
            sfp = clock.getElapsedTime().asSeconds(); //записываем кол-во секунд на кадр
            clock.restart();
            Event event;
            while (window->pollEvent(event))
            {
                if (event.type == Event::Closed || (Keyboard::isKeyPressed(Keyboard::Escape)))
                {
                    //Добавить сохранение перед выходом
                    window->close();
                }
            };
            if (Keyboard::isKeyPressed(Keyboard::F)) // переход в оконной режим ,  содержащий кнопки свернуть, развернуть и закрыть
            {
                window->close();
                window = new RenderWindow(mode, title, Style::Default);
            }

            moveMainHero.stayCalm(); // Порядок не менять, последние кадры перекрывают первые!
            moveMainHero.goRight();
            moveMainHero.goLeft();
            moveMainHero.goDown();
            moveMainHero.goUp();
            moveMainHero.sayNo();

            window->clear();
            window->draw(back.getGroundSprite());
            window->draw(back.getGrassStoneSprite());
            window->draw(moveMainHero.getHeroSprite());

            window->display();
        }
    }
};
#endif