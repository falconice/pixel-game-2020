// All background stuff
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <SFML/Graphics.hpp>

#include "../map/block/SectionBlock.h"

using namespace sf;

class Environment
{
private:
    Sprite grassStone;
    Sprite houseS;

    Texture grassStoneTexture;
    Texture house;

public:
    Environment()
    {

        // Увеличиваем  в размере для нормального отображения*/

        grassStoneTexture.loadFromFile("map_textures\\grass_21_20.png");
        grassStone.setTexture(grassStoneTexture);

        grassStone.setTextureRect(IntRect(0, 0, 21, 20));
        grassStone.setPosition(0, 0);
        grassStone.scale(3, 3);

        house.loadFromFile("map_textures\\HouseStart6.png");
        houseS.setTexture(house);

        houseS.setTextureRect(IntRect(0, 0, 128, 128));
        houseS.setPosition(800, 0);
        houseS.scale(9, 9);
    }

    const Sprite &getHouse() const
    {
        return this->houseS;
    }

    const Sprite &getGrassStone() const
    {
        return this->grassStone;
    }
};
#endif