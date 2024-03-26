#pragma once
#include <SFML/Graphics.hpp>

class Cvijet {
public:
    Cvijet(sf::RenderWindow* window);
    void draw();

private:
    sf::RenderWindow* window;
    sf::CircleShape pistil;
    sf::RectangleShape stem;
    sf::ConvexShape petal1;
    sf::ConvexShape petal2;
    sf::ConvexShape petal3;
    sf::ConvexShape petal4;
    sf::ConvexShape petal5;
    sf::ConvexShape petal6;
};
