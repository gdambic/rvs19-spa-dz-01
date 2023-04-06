#pragma once
#include <SFML/Graphics.hpp>
class Sunce
{
private:
    sf::RenderWindow* window;
    int x = 0;
public:
    Sunce(sf::RenderWindow* window);
    void draw();
};

