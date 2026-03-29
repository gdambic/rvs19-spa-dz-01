#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
    sf::RenderWindow* window;

    float radijusSunca;
    bool smanjujeSe;
    sf::Clock frameClock;

public:
    Cvijet(sf::RenderWindow* window);
    void draw();
};