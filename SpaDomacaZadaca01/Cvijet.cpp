#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) : window(window), sunSize(20.f), increasing(true) {}

void Cvijet::draw() {

    if (increasing) {
        sunSize += 0.1f;
        if (sunSize >= 20.f) {
            increasing = false;
        }
    }
    else {
        sunSize -= 0.1f;
        if (sunSize <= 15.f) {
            increasing = true;
        }
    }

    sf::RectangleShape stem(sf::Vector2f(10.f, 200.f));
    stem.setFillColor(sf::Color(0, 128, 0));
    stem.setPosition(150.f, 300.f);
    window->draw(stem);


    sf::CircleShape sun(sunSize);
    sun.setFillColor(sf::Color(255, 255, 0));
    sun.setPosition(25.f, 25.f);
    window->draw(sun);


    sf::CircleShape petal(100.f);
    petal.setFillColor(sf::Color::Red);
    petal.setPosition(55.f, 125.f);
    window->draw(petal);



    sf::CircleShape center(55.f);
    center.setFillColor(sf::Color::Yellow);
    center.setPosition(105.f, 175.f);
    window->draw(center);


    sf::ConvexShape leaf;
    leaf.setPointCount(4);
    leaf.setPoint(0, sf::Vector2f(0.f, 10.f));
    leaf.setPoint(1, sf::Vector2f(60.f, 50.f));
    leaf.setPoint(2, sf::Vector2f(100.f, 150.f));
    leaf.setPoint(3, sf::Vector2f(100.f, 150.f));
    leaf.setFillColor(sf::Color(0, 128, 0));
    leaf.setPosition(300.f, 300.f);
    leaf.rotate(90.f);
    window->draw(leaf);
}
