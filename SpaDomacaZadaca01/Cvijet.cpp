#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
    this->window = window;
}

void Cvijet::draw(sf::RenderWindow& window)
{
    //sun
    sf::CircleShape sunce(10.f);
    sunce.setFillColor(sf::Color(255, 255, 0));
    sunce.setPosition(sf::Vector2f(5, 5));
    sf::Time elapsed1 = clock.getElapsedTime();

    if (clock.getElapsedTime().asMilliseconds()>2000)
    {
        sunce.setRadius(30.f - 10.f * ((clock.getElapsedTime().asMilliseconds() - 2000) / 2000.f));
        if (clock.getElapsedTime().asMilliseconds() >= 4000)
        {
            clock.restart();
        }
    }
    else
    {
        sunce.setRadius(20.f + 10.f * (clock.getElapsedTime().asMilliseconds() / 2000.f));
    }
    window.draw(sunce);

    //flower_head
    sf::CircleShape head(100.f);
    head.setFillColor(sf::Color(255, 255, 0));
    head.setOutlineThickness(50.f);
    head.setOutlineColor(sf::Color(255, 0, 0));
    head.setPosition(sf::Vector2f(80, 80));
    window.draw(head);

    //line
    sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
    line.rotate(90.f);
    line.setFillColor(sf::Color(100, 250, 50));
    line.setPosition(sf::Vector2f(183, 329));
    line.setSize(sf::Vector2f(250.f, 10.f));
    window.draw(line);

    //leaf
    leaf.setPointCount(4);
    leaf.setPoint(0, sf::Vector2f(175.f, 440.f));
    leaf.setPoint(1, sf::Vector2f(240.f, 400.f));
    leaf.setPoint(2, sf::Vector2f(400.f, 360.f));
    leaf.setPoint(3, sf::Vector2f(260.f, 450.f));
    leaf.setFillColor(sf::Color(100, 250, 50));
    window.draw(leaf);
}