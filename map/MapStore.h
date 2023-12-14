#ifndef MAP_STORE_H
#define MAP_STORE_H
#include <SFML/Graphics.hpp>
#include "block/SectionBlock.h"

#include <iostream>
#include <fstream>
#include <sstream>

class MapStore
{
private:
    Sprite background;         // задний план
    Texture backgroundTexture; // текстура земли

    int numberStore[14][11];
    SectionBlock map[14][11];
    int mainFrame;

    /// from 91 to 92

    void loadMapStorage()
    {
        int count = 1;
        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                numberStore[i][j] = count;
                count++;
            }
        }
        std::string line;
        std::ifstream mapIn("block1.textures");

        if (mapIn.is_open())
        {
            while (getline(mapIn, line))
            {

                int number;
                std::string path;
                float x, y;

                std::istringstream iss(line);
                iss >> number >> path >> x >> y;

                for (int i = 0; i < 14; i++)
                {
                    for (int j = 0; j < 11; j++)
                    {
                        if (numberStore[i][j] == number)
                        {
                            map[i][j].setSectionBlock(number, path, x, y);
                        };
                    }
                }
            }
        }
        mapIn.close();
    }

    SectionBlock getFrameByNumber(int number)
    {

        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (map[i][j].getNumber() == number)
                {
                    return map[i][j].getSectionBlock();
                };
            };
        };
    }

    void createMainSprite()
    {
        backgroundTexture.loadFromFile(std::filesystem::path(getFrameByNumber(mainFrame).getTexturePath())); // загрузка текстуры земли (из файла)
        background.setTexture(backgroundTexture);
        background.setTextureRect(sf::Rect<int>({0, 0}, {1920, 1080})); // "Создаем" землю
        background.setPosition({0.0, 0.0});
    }

public:
    MapStore()
    {
        loadMapStorage();
        mainFrame = 93;
    }

    int getMainFrame()
    {
        return this->mainFrame;
    }

    int getUp(int currentFrameNumber)
    {
        std::cout << "Get UP ^, new frame is:" << getFrameByNumber(currentFrameNumber).getUpNeighbour() << std::endl;
        return getFrameByNumber(currentFrameNumber).getUpNeighbour();
    }

    int getRight(int currentFrameNumber)
    {
        std::cout << "Get Right --> , new frame is:" << getFrameByNumber(currentFrameNumber).getRightNeighbour() << std::endl;
        return getFrameByNumber(currentFrameNumber).getRightNeighbour();
    }

    int getDown(int currentFrameNumber)
    {
        std::cout << "Get Down v , new frame is:" << getFrameByNumber(currentFrameNumber).getDownNeighbour() << std::endl;
        return getFrameByNumber(currentFrameNumber).getDownNeighbour();
    }

    int getLeft(int currentFrameNumber)
    {
        return getFrameByNumber(currentFrameNumber).getLeftNeighbour();
    }

    void changeMainFrame(int newFrameNumber)
    {
        this->mainFrame = newFrameNumber;
    }

    String getCurrentTexturePath()
    {
        return getFrameByNumber(mainFrame).getTexturePath();
    }
};

#endif