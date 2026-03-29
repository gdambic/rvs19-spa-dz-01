#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
    this->window = window;
    sunRadius = 20.0f;
    growing = true;
}

void Cvijet::draw()
{
    float dt = frameClock.restart().asSeconds();

    if (growing)
        sunRadius += 20.0f * dt;
    else
        sunRadius -= 20.0f * dt;

    if (sunRadius > 30.0f)
        growing = false;
    if (sunRadius < 20.0f)
        growing = true;

    sf::RectangleShape stalk(sf::Vector2f(10.0f, 150.0f));
    stalk.setPosition(395.0f, 300.0f);
    stalk.setFillColor(sf::Color::Green);
    window->draw(stalk);

    sf::CircleShape petal(30.0f);
    petal.setFillColor(sf::Color::Magenta);

    petal.setPosition(340.0f, 220.0f);
    window->draw(petal);

    petal.setPosition(430.0f, 220.0f);
    window->draw(petal);

    petal.setPosition(340.0f, 310.0f);
    window->draw(petal);

    petal.setPosition(430.0f, 310.0f);
    window->draw(petal);

    sf::CircleShape center(sunRadius);
    center.setFillColor(sf::Color::Yellow);
    center.setPosition(400.0f - sunRadius, 280.0f - sunRadius);
    window->draw(center);
}