#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
    sf::RenderWindow* window;
    float sunac;
    bool raste;
    sf::Clock frameclock;

    float oblaci;
    bool oblakdesno;

    float cvijetanim;

public:
    Cvijet(sf::RenderWindow* window);
    void draw();
};