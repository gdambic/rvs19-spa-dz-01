#pragma once
#include <SFML/Graphics.hpp>

class Cvijet {
private:
    sf::RenderWindow* prozor;

    sf::RectangleShape nebo;
    sf::RectangleShape trava;

    sf::CircleShape sunce;
    float sunce_polumjer;
    float sunce_smjer;

    sf::CircleShape oblak_prvi[3];
    sf::CircleShape oblak_drugi[3];
    float oblak_prvi_x;
    float oblak_drugi_x;
    float oblak_prvi_smjer;
    float oblak_drugi_smjer;

    sf::CircleShape latica[6];
    sf::CircleShape srediste;
    sf::RectangleShape stabljika;
    sf::ConvexShape list_lijevi;
    sf::ConvexShape list_desni;

    sf::Clock sat;

public:
    Cvijet(sf::RenderWindow* prozor);
    void draw();
};