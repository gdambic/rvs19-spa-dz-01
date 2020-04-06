#include "Cvijet.h"
#include <iostream>

Cvijet::Cvijet(sf::RenderWindow* window)
{
    this->window = window;
}

void Cvijet::draw(sf::RenderWindow& window)
{
    cvijet.setRadius(90.f);
    cvijet.setFillColor(sf::Color(255, 255, 0));
    cvijet.setOutlineThickness(45.f);
    cvijet.setOutlineColor(sf::Color(255, 0, 0));
    cvijet.setPosition(sf::Vector2f(80, 80));

    sf::RectangleShape stabljika(sf::Vector2f(150.f, 5.f));
    stabljika.rotate(90.f);
    stabljika.setPosition(sf::Vector2f(175, 305));
    stabljika.setSize(sf::Vector2f(280, 10));
    stabljika.setFillColor(sf::Color(0, 255, 0));

    list.setPointCount(4);
    list.setPoint(0, sf::Vector2f(175.f, 440.f));
    list.setPoint(1, sf::Vector2f(240.f, 400.f));
    list.setPoint(2, sf::Vector2f(400.f, 360.f));
    list.setPoint(3, sf::Vector2f(260.f, 450.f));
    list.setFillColor(sf::Color(0, 255, 0));
    window.draw(list);

    sunce.setRadius(20.f);
    sunce.setFillColor(sf::Color(255, 255, 0));
    sunce.setPosition(sf::Vector2f(10, 10));
    
    sf::Time elapsedTime = frameClock.getElapsedTime();
    //std::cout << elapsedTime.asMilliseconds() << std::endl;

    if (frameClock.getElapsedTime().asMilliseconds() > 2000)
    {
        sunce.setRadius(25.f - 5.f * ((frameClock.getElapsedTime().asMilliseconds() - 2000) / 2000.f));
        if (frameClock.getElapsedTime().asMilliseconds() >= 4000)
        {
            frameClock.restart();
        }
    }
    else
    {
        sunce.setRadius(20.f + 5.f * (frameClock.getElapsedTime().asMilliseconds() / 2000.f));
    }
    //std::cout << sunce.getRadius() << std::endl;


    window.draw(cvijet);
    window.draw(sunce);
    window.draw(stabljika);
}