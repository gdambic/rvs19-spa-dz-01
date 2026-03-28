#pragma once
#include <SFML/Graphics.hpp>
#include <array>

class Cvijet
{
private:
    sf::RenderWindow* prozor;
    std::array<sf::CircleShape, 10> latice;
    sf::CircleShape sredina;
    sf::RectangleShape stapka;
    sf::RectangleShape listLijevi;
    sf::RectangleShape listDesni;
    sf::Clock frameClock;
    float sredinaRadius;
    bool smanjuje;

public:
    Cvijet(sf::RenderWindow* prozor);
    void draw();
};




