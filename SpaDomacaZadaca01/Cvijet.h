#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
    sf::RenderWindow* window;
    int pomak = 0;
    bool gore = true;
public:
    Cvijet(sf::RenderWindow* prozor);
    void draw();
};

