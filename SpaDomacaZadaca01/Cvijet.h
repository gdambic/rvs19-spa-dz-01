#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
    sf::RenderWindow* window;
    sf::Clock frameClock;
    float sunRadius;
    bool growing;

public:
    Cvijet(sf::RenderWindow* window);
    void draw();
};