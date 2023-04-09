#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
    window_ = window;

    sun.setFillColor(sf::Color::Yellow);
    sun.setPosition(10.f, 10.f);

    flower.setRadius(80.f);
    flower.setFillColor(sf::Color::Yellow);
    flower.setPosition(100.f, 70.f);
    flower.setOutlineThickness(50.f);
    flower.setOutlineColor(sf::Color::Red);

    stem.setSize(sf::Vector2f(13.f, 200.f));
    stem.setFillColor(sf::Color::Green);
    stem.setPosition(180.f, 280.f);

    leaf.setPointCount(4);
    leaf.setPoint(0, sf::Vector2f(190.f, 400.f));
    leaf.setPoint(1, sf::Vector2f(300.f, 350.f));
    leaf.setPoint(2, sf::Vector2f(470.f, 350.f));
    leaf.setPoint(3, sf::Vector2f(300.f, 430.f));
    leaf.setFillColor(sf::Color::Green);

    frameClock.restart();
    sunSize = 20.f;
    increasing = false;
}

void Cvijet::draw()
{
    float deltaTime = frameClock.restart().asSeconds();
    if (sunSize <= 15.f) {
        increasing = true;
    }
    else if (sunSize >= 20.f) {
        increasing = false;
    }
    if (increasing) {
        sunSize += deltaTime * 10.f;
    }
    else {
        sunSize -= deltaTime * 10.f;
    }
    sun.setRadius(sunSize);

    window_->draw(sun);
    window_->draw(flower);
    window_->draw(stem);
    window_->draw(leaf);
}
