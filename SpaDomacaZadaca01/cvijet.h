#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Cvijet
{
public:
    Cvijet(RenderWindow& window);
    void draw();

private:

    Clock clock;
    CircleShape sunce;
    RectangleShape zbica;
    CircleShape cvetic;
    ConvexShape list;
    RenderWindow& window;
};
