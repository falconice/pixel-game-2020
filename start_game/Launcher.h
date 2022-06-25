//User Inteface
#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <SFML/Graphics.hpp>
#include "../character/Movement.h"
#include "../environment/Composition.h"

#include "WindowLoader.h"

#include "Camera.h"
using namespace sf;

class Launcher
{
private:
    Composition back;

    Clock clock; //Для нормального движения персонажей
    float spf;   //секунд на кадр

    VideoMode mode;        //формат окна
    String title;          //название окна
    RenderWindow *window;  //для пересоздания окна при переключении режимов
    Movement moveMainHero; //двигающийся персонаж

    WindowLoader queue;

public:
    Launcher() : moveMainHero(&spf)
    { //конструктор окна
        mode = VideoMode().getDesktopMode(); ///VideoMode(800, 400)
        title = "Pixel Game 2020";
        window = new RenderWindow(mode, title, Style::Fullscreen ); //Игровое окно, на весь экран Style::Fullscreen

        view.reset(FloatRect(0, 0, 1920, 1080));

        //window->setVerticalSyncEnabled(true); //vsync on
        window->setFramerateLimit(60); //fps 60
    }

    void launch()
    {
        //открытие окна

        window->display();
        while (window->isOpen())
        {
            spf = clock.getElapsedTime().asSeconds(); //записываем кол-во секунд на кадр
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

        
            moveMainHero.move();

            moveView(moveMainHero.getXHero(), moveMainHero.getYHero());

            queue.createQueue(window, back, moveMainHero);


            window->display();
        }
    }
};
#endif