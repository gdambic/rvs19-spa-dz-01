#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
    sf::RenderWindow& window;
    sf::CircleShape center;
    sf::CircleShape petals[6];   
    sf::RectangleShape stem;
    sf::ConvexShape leaf;
    sf::CircleShape sun;

    float sunRadius;
    bool shrinking;
    float time;
    sf::Clock frameClock;
public:
    Cvijet(sf::RenderWindow& win);
    void draw();
};

