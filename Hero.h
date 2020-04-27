#ifndef HERO_H
#define HERO_H

#include <SFML/Graphics.hpp>

#include "ActiveMap.h"
using namespace sf;

class Hero
{
private:
    Sprite hero; //герой
    String name; //имя персонажа
    int id;      //персональный id
    int level;
    Texture movementHero; //кадры движения
    Texture stayHero;     //кадры покоя
    Texture sayNoTexture; // кадры отказа от действия
    float x, y;

    ActiveMap activeMap;

    void setPosition(float x, float y)
    {
        this->x = x;
        this->y = y;
    };

public:
    Hero() : activeMap()
    {
        movementHero.loadFromFile("characters\\spritesheet_Lucy_19_41.png");    //загрузка текстуры движения персонажа  (из файла)
        stayHero.loadFromFile("characters\\spritesheet_LucyStay_41_19.png");    //загрузка текстуры покоя персонажа  (из файла)
        sayNoTexture.loadFromFile("characters\\spritesheet_Lucy_NO_41_19.png"); // загрузка текстуры отрицания действия
        hero.setTextureRect(IntRect(0, 0, 19, 41));                             // "Создаем" персонажа
        hero.setPosition(870, 340);                                             //Задаем начальную позицию
        this->setPosition(870, 340);                                            //Запоминаем начальную позицию

        hero.scale(3.5, 3.5); // Увеличиваем персоажа в размере для нормального отображения
    };

    //-------------GETTTERS----------------------
    const Sprite &getHero() const
    {
        return this->hero;
    }
    Sprite &getHero()
    {
        return this->hero;
    }

    const Texture &getMoveTexture() const
    {
        return this->movementHero;
    }

    const Texture &getStayTexture() const
    {
        return this->stayHero;
    };

    const Texture &getSayNOTexture() const
    {
        return this->sayNoTexture;
    };

    const float getX() const ////!11111111111
    {
        return this->x;
    }

    const float getY() const /////!!!!!!!!!!!!!
    {
        return this->y;
    }

    //-------------SETTTERS----------------------
    void setHero(Sprite hero)
    {
        this->hero = hero;
    };

    void setMoveTexture(Texture movementTexture)
    {
        this->movementHero = movementTexture;
    };

    void setStayTexture(Texture stayTexture)
    {
        this->movementHero = stayTexture;
    };

    void setSayNoTexture(Texture sayNoTexture)
    {
        this->sayNoTexture = sayNoTexture;
    };

    void setY(float y)
    {
        this->y = y;
    };
    void setX(float x)
    {
        this->x = x;
    };

    void changePosition(float OffsetX, float OffsetY)
    {

        setPosition(this->getX() + OffsetX, this->getY() + OffsetY);
    };

    void changeMap()
    {
        activeMap.changePosition(x, y);
    };

    //---------Other Getter

    /* const Sprite &getActiveMapSprites(){
       
    }*/

    /*//__________________!!!!!DANGER ZONE!!!!_________________
    ///-------GET SPRITES------------
    //1
    const Sprite &getFirstNeighbour() const
    {
        return activeMap.getFirstNeighbour();
    };

    Sprite &getFirstNeighbour()
    {
        return activeMap.getFirstNeighbour();
    };

    //2
    const Sprite &getSecondNeighbour() const
    {
        return activeMap.getSecondNeighbour();
    }

    Sprite &getSecondNeighbour()
    {
        return activeMap.getSecondNeighbour();
    }

    //3
    const Sprite &getThirdNeighbour() const
    {
        return activeMap.getThirdNeighbour();
    }

    Sprite &getThirdNeighbour()
    {
        return activeMap.getThirdNeighbour();
    }

    //4
    const Sprite &getFourthdNeighbour() const
    {
        return activeMap.getFourthdNeighbour();
    }

    Sprite &getFourthdNeighbour()
    {
        return activeMap.getFourthdNeighbour();
        ;
    }
    //5 CENTRE
    const Sprite &getFifthdNeighbour() const
    {
        return activeMap.getFifthdNeighbour();
    }

    Sprite &getFifthdNeighbour()
    {
        return activeMap.getFifthdNeighbour();
    }
    //6
    const Sprite &getSixthNeighbour() const
    {
        return activeMap.getSixthNeighbour();
    }

    Sprite &getSixthNeighbour()
    {
        return activeMap.getSixthNeighbour();
    }

    //7
    const Sprite &getSeventhNeighbour() const
    {
        return activeMap.getSeventhNeighbour();
    }

    Sprite &getSeventhNeighbour()
    {
        return activeMap.getSeventhNeighbour();
    }

    //8
    const Sprite &getEighthNeighbour() const
    {
        return activeMap.getEighthNeighbour();
    }

    Sprite &getEighthNeighbour()
    {
        return activeMap.getEighthNeighbour();
    }
    //9
    const Sprite &getNinthNeighbour() const
    {
        return activeMap.getNinthNeighbour();
    }

    Sprite &getNinthNeighbour()
    {
        return activeMap.getNinthNeighbour();
    }*/
    const Sprite ***getMapSprites() const
    {
        return activeMap.getMapSprites();
    }
};
#endif