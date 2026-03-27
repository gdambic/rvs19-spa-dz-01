#pragma once
#include <SFML/Graphics.hpp>

class Cvijet {
private:
    sf::RenderWindow* prozor;
    sf::CircleShape srediste;
    sf::CircleShape latice[6];
    sf::RectangleShape stabljika;
    sf::ConvexShape list1;
    sf::ConvexShape list2;
    sf::Clock frameClock;
    float radius;
    bool rastuca;

public:
    Cvijet(sf::RenderWindow* prozor);
    void draw();
};