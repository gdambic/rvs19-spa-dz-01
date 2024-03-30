#pragma once
#include <SFML/Graphics.hpp>
class Sunce
{
private:
        sf::CircleShape shape;
        float positionX;
        float speed;

    public:
        Sunce(float radius, float speed);
        void setPosition(float x, float y);
        void move(float deltaTime);
        void draw(sf::RenderWindow& window);
};

