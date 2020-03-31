

#include <SFML/Graphics.hpp>
#include <cassert>

using namespace sf;

class userWindow
{
private:
    Clock clock; //Для нормального движения персонажей

    Texture movementHero;
    Texture stayHero;
    float currentFrameLR = 0;
    float currentFrameRest = 0;
    float run = clock.getElapsedTime().asSeconds() * 10; //Режим бега
    float walk = clock.getElapsedTime().asSeconds() * 5; //Режим ходьбы

public:
    void display()
    {

        RenderWindow window(VideoMode().getDesktopMode(), "Game");

        movementHero.loadFromFile("spritesheet_Lucy.png");
        stayHero.loadFromFile("spritesheet_LucyStay.png");

        Sprite heroSprite;
        heroSprite.setTextureRect(IntRect(0, 0, 64, 64));
        heroSprite.setTexture(movementHero);
        heroSprite.setPosition(0, 0);
        heroSprite.scale(4, 4);

        float time = walk;
        clock.restart();

        window.display();
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    window.close();
                }
            }

            heroSprite.setTextureRect(IntRect(0, 0, 64, 64));
            heroSprite.setTexture(stayHero);
            currentFrameRest += 0.015 * walk;
            if (currentFrameRest > 22)
                currentFrameRest -= 22;
            heroSprite.setTextureRect(IntRect(64 * int(currentFrameRest), 0, 64, 64));

            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                heroSprite.setTexture(movementHero);
                heroSprite.move(-0.1 * time, 0);
                currentFrameLR += 0.015 * walk;
                if (currentFrameLR > 10)
                    currentFrameLR -= 10;
                heroSprite.setTextureRect(IntRect(64 * int(currentFrameLR) + 64, 192, -64, 64));
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                heroSprite.setTexture(movementHero);
                heroSprite.move(0.1 * time, 0);
                currentFrameLR += 0.015 * walk;
                if (currentFrameLR > 10)
                    currentFrameLR -= 10;
                heroSprite.setTextureRect(IntRect(64 * int(currentFrameLR), 192, 64, 64));
            }
            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                heroSprite.setTexture(movementHero);
                heroSprite.move(0, -0.1 * time);
                currentFrameLR += 0.015 * walk;
                if (currentFrameLR > 8)
                    currentFrameLR -= 8;
                heroSprite.setTextureRect(IntRect(64 * int(currentFrameLR), 64, 64, 64));
            }
            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                heroSprite.setTexture(movementHero);
                heroSprite.move(0, 0.1 * time);
                currentFrameLR += 0.015 * walk;
                if (currentFrameLR > 8)
                    currentFrameLR -= 8;
                heroSprite.setTextureRect(IntRect(64 * int(currentFrameLR), 128, 64, 64));
            }

            window.clear();

            window.draw(heroSprite);
            window.display();
        }
    }
};
