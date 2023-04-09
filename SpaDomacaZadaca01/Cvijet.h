#pragma once
#include <SFML/Graphics.hpp>
class Cvijet {
public:
    Cvijet(sf::RenderWindow* window);
    void draw();

private:
    sf::RenderWindow* window_;
    sf::CircleShape sun;
    sf::CircleShape flower;
    sf::RectangleShape stem;
    sf::ConvexShape leaf;
    sf::Clock frameClock;
    float sunSize;
    bool increasing;
};

