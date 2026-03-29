#pragma once
#include <SFML/Graphics.hpp>
#include<vector>

class Cvijet {
private:
    sf::RenderWindow* window;

    std::vector<sf::CircleShape> latice;
    sf::CircleShape sredina;
    sf::RectangleShape stabljika;
    sf::ConvexShape list;

    sf::CircleShape sunce;

    float offset = 0.0f;
    bool desno = true;

    float sunScale = 1.0f;
    bool sunGrowing = false;

    sf::Clock clock;


public:
    Cvijet(sf::RenderWindow* window);
    void draw();
};