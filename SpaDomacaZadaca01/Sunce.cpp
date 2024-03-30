#include "Sunce.h"

Sunce::Sunce(float radius, float speed)
    : positionX(-radius * 2), speed(speed)
{
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Yellow);
}

void Sunce::setPosition(float x, float y)
{
    shape.setPosition(x, y);
}

void Sunce::move(float deltaTime)
{
    positionX += speed * deltaTime;

    
    if (positionX > 800) 
    {
        positionX = -shape.getRadius() * 2;
    }

    shape.setPosition(positionX, shape.getPosition().y);
}

void Sunce::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}
