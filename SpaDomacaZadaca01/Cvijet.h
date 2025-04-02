#pragma once
#include <SFML/Graphics.hpp>

class Cvijet {
private:
    sf::RenderWindow* window;

    sf::CircleShape sredina;
    std::vector<sf::CircleShape> latice;
    sf::RectangleShape stapka;

    // Za animaciju
    sf::Clock frameClock;
    bool smanjuje = true;
    float trenutniRadijus = 25.0;
    float kut = 0.0f;

public:
    Cvijet(sf::RenderWindow* win);
    void draw();
};
