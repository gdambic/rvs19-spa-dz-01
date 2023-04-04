#pragma once
#include <SFML/Graphics.hpp>
class Flower
{
private:
    sf::RenderWindow* window;
    float radius;
public:
    Flower(sf::RenderWindow* window);
    int randc();
    void draw();
};

