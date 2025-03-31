#ifndef CVIJET_H
#define CVIJET_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Cvijet {
private:
    sf::RenderWindow* window;
    sf::CircleShape latica;
    sf::CircleShape centar;
    sf::RectangleShape stabljika;
    sf::ConvexShape list;
    sf::Clock frameClock;
    float laticaScale;
    bool scalingUp;

public:
    Cvijet(sf::RenderWindow* proz);
    void draw();
};

#endif