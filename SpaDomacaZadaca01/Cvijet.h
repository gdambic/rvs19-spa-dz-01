#pragma once

#include <SFML/Graphics.hpp>
class Cvijet
{
public:
    Cvijet(sf::RenderWindow* window);
    void draw();
    void animate();

private:
    sf::RenderWindow* prozor;
    sf::CircleShape krug;
    sf::RectangleShape stabljika;
    sf::ConvexShape list;
    sf::ConvexShape list2;
    sf::RectangleShape trava;
    sf::Clock frameClock;
};

