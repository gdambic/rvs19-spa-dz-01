#pragma once
#include <SFML/Graphics.hpp>

class Cvijet {
private:
    sf::RenderWindow* prozor;

    // Tijelo cvijeta (stabljika)
    sf::RectangleShape stabljika;

    // Latice (krugovi oko sredista)
    sf::CircleShape latica[6];

    // Srediste cvijeta
    sf::CircleShape srediste;

    // List
    sf::ConvexShape list;

    // Sunce
    sf::CircleShape sunce;

    // Animacija sunca
    sf::Clock frameClock;
    float sunRadius;
    float sunSpeed;
    bool sunGrowing;

    void initShapes();

public:
    Cvijet(sf::RenderWindow* prozor);
    void draw();
};
