#pragma once
#include <SFML/Graphics.hpp>

class Cvijet {
public:
    Cvijet(sf::RenderWindow* window);
    void draw();

private:
    sf::RenderWindow* window;

    sf::CircleShape sunce;
    sf::CircleShape tucak;
    sf::CircleShape latica;
    sf::RectangleShape stabljika;
    sf::ConvexShape list;

    bool raste = true;
};

