#pragma once
#include <SFML/Graphics.hpp>

class Cvijet {
public:
    Cvijet(sf::RenderWindow* window);

    void draw();
    void update();

private:
    sf::RenderWindow* window;
    sf::Vector2f centerPosition = sf::Vector2f(400, 300);
    float outerCircleRadius = 60;
    float innerCircleRadius = 30;
    float circleScaleSpeed = 50;
    float stemLength = 150;

    void drawFlower();
    void drawStem();
};
