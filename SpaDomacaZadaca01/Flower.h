#pragma once
#include <SFML/Graphics.hpp>
#include <vector> 

class Flower {
private:
    sf::RenderWindow* window;
    sf::Clock frameClock;

    sf::RectangleShape stem;
    sf::CircleShape center;
    std::vector<sf::CircleShape> petals;
    sf::ConvexShape leaf;

    sf::CircleShape sun;
    float currentSunRadius;
    bool isGrowing;
    float sunX;   
    bool movingRight; 

public:
    Flower(sf::RenderWindow* window);
    void draw();
};