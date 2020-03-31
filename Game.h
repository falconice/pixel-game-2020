#include <SFML/Graphics.hpp>
#include <cassert>
#include "Hero.h"
using namespace sf;

class Game
{

public:
    void play()
    {
        Hero girl;
        girl.create();
    };
};