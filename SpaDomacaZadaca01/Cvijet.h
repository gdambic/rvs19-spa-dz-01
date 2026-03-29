#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Cvijet
{
private:
    sf::RenderWindow* window;
    float x, y;
    float radius;
    float angle;

    std::vector<sf::CircleShape> petals;
    sf::CircleShape center;

public:
    Cvijet(sf::RenderWindow* win);
    void draw();
};