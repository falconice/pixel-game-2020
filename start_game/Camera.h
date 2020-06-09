#ifndef CAMERA_H
#define CAMERA_H
#include <SFML/Graphics.hpp>
using namespace sf;

View view;

View moveView(float x, float y)
{
    view.setCenter(x + 100, y+200);
    return view;
}

#endif