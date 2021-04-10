#include "Cloud.h"

Cloud::Cloud(sf::RenderWindow* window, float size)
{
    this->window = window;
    this->size = size;
}

Cloud::~Cloud()
{
    Cloud::~Cloud();
}

void Cloud::draw()
{
    window->draw(circle());
}

sf::CircleShape Cloud::circle()
{
    sf::CircleShape circle(750);
    circle.setFillColor(sf::Color(128, 128, 128));
    circle.setPosition(-350, -1375);
    return circle;
}
