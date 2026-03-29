#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
    sf::RenderWindow* window;
    sf::CircleShape outerCircle;  // crvena latica
    sf::CircleShape innerCircle;  // žuti centar
    sf::VertexArray petals;
    sf::RectangleShape stem;      // stabljika
    sf::ConvexShape leaf;         // list

    sf::CircleShape sunce;
    sf::Clock frameClock;   // mjeri vrijeme između frameova
    float radius = 20.f;    // trenutni radius
    bool shrinking = true;  // smanjuje li se ili povećava
   


public:
    Cvijet(sf::RenderWindow* window);
    void draw();
};

