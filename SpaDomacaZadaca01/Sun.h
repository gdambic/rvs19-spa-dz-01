#pragma once
#include <SFML/Graphics.hpp>

class Sun {
public:
    Sun(double radius, sf::Color color);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    sf::CircleShape sun;
    float speed; 
    float positionY; 
    bool increasing; 
};
