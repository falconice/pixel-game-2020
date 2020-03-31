#include <SFML/Graphics.hpp>
#include <cassert>
#include "userWindow.h"
using namespace sf;

class Hero
{
private:
String name;
int age;
int level;

public:
    void create()
    {
        userWindow window;
        window.display();
    };
};