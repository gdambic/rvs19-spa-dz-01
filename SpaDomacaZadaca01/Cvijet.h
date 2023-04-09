#pragma once
#include <SFML/Graphics.hpp>

class Cvijet {
private:
    sf::RenderWindow* window;
    sf::ConvexShape flowerShape;
    sf::RectangleShape stemShape;
    float swingAngle;
public:
    Cvijet(sf::RenderWindow* window);
    void draw();
};

