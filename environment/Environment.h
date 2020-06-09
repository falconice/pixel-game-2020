//All background stuff
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <SFML/Graphics.hpp>

#include "../map/block/SectionBlock.h"

using namespace sf;

class Environment
{
private:
    //Sprite ground;  //земля
    //Sprite ground2; //земля
    Sprite grassStone;

   ///SectionBlock blockOne;
   // SectionBlock blockTwo;
    //SectionBlock blocks[14][11];
    
    Sprite houseS;


    //Texture groundTexture; //текстура земли
    Texture grassStoneTexture;
    Texture house;

public:
    Environment()
    {
        /*groundTexture.loadFromFile("map_textures\\ground1920.png"); //загрузка текстуры земли (из файла)
        ground.setTexture(groundTexture);
 ground.setTextureRect(IntRect(0, 0, 1920, 1080)); // "Создаем" землю
        ground.setPosition(0, 0);                         //Задаем начальную позицию
                                                          //ground.scale(1.01, 1.01);                         
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

       // blockOne.setBlockPosition(0, 0);
       // blockTwo.setBlockPosition(0, 1080);
        /* ground2.setTexture(groundTexture);
        ground2.setTextureRect(IntRect(0, 0, 1920, 1080)); // "Создаем" землю
        ground2.setPosition(7700, 4500);                   //Задаем начальную позицию
        ground2.scale(4, 4);     */
        // Увеличиваем персоажа в размере для нормального отображения
    }

    /*const Sprite &getGround() const
    {
        return this->blockOne.getGround();
    }
    const Sprite &getGround2() const
    {
        return this->blockTwo.getGround();
    }
*/
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