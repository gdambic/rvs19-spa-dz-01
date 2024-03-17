#pragma once
#include <SFML/Graphics.hpp>

class Cvijet {
private:
    sf::RenderWindow* window;
    float sunSize;
    bool increasing;

public:
    Cvijet(sf::RenderWindow* window);
    void draw();
};