// Класс работающий с картой
#ifndef ACTIVEMAP_H
#define ACTIVEMAP_H

#include <SFML/Graphics.hpp>

//#include "Hero.h"
#include "TestMapStore.h"
//#include "WindowLoader.h"

using namespace sf;
class ActiveMap
{
private:
    // friend WindowLoader;
    //FullMap available to hero
    Sprite *currentMap[3][3]; //field 3x3
    //Texture *currentTexture[2][2];

    MapStore mapStore;
    float x, y;
    int centre; // в начале игры 93
    //Считывание координат игрока и определяем блок | Aналогично mapStore
    int getNumber(float x, float y)
    {
        return mapStore.getLoadNumber(x, y);
    }

    int getheroPlace()
    {
        return mapStore.getLoadNumber(this->x, this->y);
    }

    //Определение центра

    void setCentre()
    {
        std::cerr << "Okay, center is set" << std::endl;
        this->centre = getheroPlace();
    }

    String getTexturePathByNumber(int number)
    {
        return mapStore.getTexturePath(number);
    }

    float getXByNumber(int number)
    {
        return mapStore.getXbyNumber(number);
    }
    float getYByNumber(int number)
    {
        return mapStore.getYbyNumber(number);
    }

    //Создание спрайтов текстурированных
    Sprite *setSpritesTextures(Sprite *sprite, String texturePath, float x, float y)
    {
        Texture texture;
        texture.loadFromFile(texturePath);
        sprite = new Sprite();
        sprite->setTexture(texture);
        sprite->setTextureRect(IntRect(x, y, 1920, 1080));

        return sprite;
    }

    //Подгрузка нужных 9ти блоков //Загрузка текстур
    void nineNeighbours()
    { //loadFromFile(getTextureByNumber(getheroPlace() - 12));
        //  currentMap[0][0]->setTexture(*currentTexture[0][0]);
        //(IntRect(getXByNumber(getheroPlace() - 12), getYByNumber(getheroPlace() - 12), 1920, 1080));

        //------------1--------------------
        //  setSpritesTextures(currentMap[0][0], (getTextureByNumber(getheroPlace() - 12)), getXByNumber(getheroPlace() - 12), getYByNumber(getheroPlace() - 12));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                currentMap[i][j] = nullptr;
            }
        }
        currentMap[1][1] = setSpritesTextures(currentMap[1][1], getTexturePathByNumber(centre), 0, 0);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == 0)
                {
                    currentMap[i][j] = setSpritesTextures(currentMap[i][j], (getTexturePathByNumber(getheroPlace() + (-12 + j))),
                                                          getXByNumber(getheroPlace() + (-12 + j)),
                                                          getYByNumber(getheroPlace() + (-12 + j)));
                }
                else if (i == 1 && j != 1)
                {
                    currentMap[i][j] = setSpritesTextures(currentMap[i][j], (getTexturePathByNumber(getheroPlace() + (j - i))),
                                                          getXByNumber(getheroPlace() + (j - i)),
                                                          getYByNumber(getheroPlace() + (j - i)));
                }
                else if (i == 2)
                {
                    currentMap[i][j] = setSpritesTextures(currentMap[i][j], (getTexturePathByNumber(getheroPlace() + (10 + j))),
                                                          getXByNumber(getheroPlace() + (10 + j)),
                                                          getYByNumber(getheroPlace() + (10 + j)));
                };
            }
        }
        //  currentMap[0][1]; currentMap[0][2];currentMap[1][0]; currentMap[1][1]; //centre currentMap[1][2]; currentMap[2][0];  currentMap[2][1];  currentMap[2][2];
    };

public:
    ActiveMap() : mapStore()
    {
        this->x = 0;
        this->y = 0;
        setCentre();
        nineNeighbours();
    }
    void changePosition(float x, float y)
    {
        this->x = x;
        this->y = y;
        nineNeighbours();
    }

    //__________________!!!!!DANGER ZONE!!!!_________________
    ///-------GET SPRITES------------
    //1
    /* const Sprite &getFirstNeighbour() const
    {
        return *currentMap[0][0];
    }

    Sprite &getFirstNeighbour()
    {
        return *currentMap[0][0];
    }
    //2
    const Sprite &getSecondNeighbour() const
    {
        return *currentMap[0][1];
    }

    Sprite &getSecondNeighbour()
    {
        return *currentMap[0][1];
    }
    //3
    const Sprite &getThirdNeighbour() const
    {
        return *currentMap[0][2];
    }

    Sprite &getThirdNeighbour()
    {
        return *currentMap[0][2];
    }

    //4
    const Sprite &getFourthdNeighbour() const
    {
        return *currentMap[1][0];
    }

    Sprite &getFourthdNeighbour()
    {
        return *currentMap[1][0];
    }
    //5 CENTRE
    const Sprite &getFifthdNeighbour() const
    {
        return *currentMap[1][1];
    }

    Sprite &getFifthdNeighbour()
    {
        return *currentMap[1][1];
    }
    //6
    const Sprite &getSixthNeighbour() const
    {
        return *currentMap[1][2];
    }

    Sprite &getSixthNeighbour()
    {
        return *currentMap[1][2];
    }

    //7
    const Sprite &getSeventhNeighbour() const
    {
        return *currentMap[2][0];
    }

    Sprite &getSeventhNeighbour()
    {
        return *currentMap[2][0];
    }

    //8
    const Sprite &getEighthNeighbour() const
    {
        return *currentMap[2][1];
    }

    Sprite &getEighthNeighbour()
    {
        return *currentMap[2][1];
    }
    //9
    const Sprite &getNinthNeighbour() const
    {
        return *currentMap[2][2];
    }

    Sprite &getNinthNeighbour()
    {
        return *currentMap[2][2];
    }*/

    const Sprite ***getMapSprites() const
    {
        return (const Sprite ***)currentMap;
    }
};

#endif