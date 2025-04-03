#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Cvijet
{
    sf::RenderWindow* window;
    sf::CircleShape sredina;
    sf::ConvexShape latice[6];
    sf::RectangleShape stabljika;
    sf::ConvexShape list;
    sf::CircleShape sunce;
    sf::RectangleShape nebo;
    std::vector<sf::CircleShape> oblaci;
    sf::Clock frameClock;
    sf::RectangleShape tlo;
    float sunceScale;
    bool smanjujeSe;
    float windOffset;
public:
    Cvijet(sf::RenderWindow* win);
    void draw();
};

