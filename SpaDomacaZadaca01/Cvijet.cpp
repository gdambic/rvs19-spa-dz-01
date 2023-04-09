#include "Cvijet.h"
#include <SFML/Graphics.hpp>


Cvijet::Cvijet(sf::RenderWindow* window) {
    this->window = window;

    flowerShape.setPointCount(6);
    flowerShape.setPoint(0, sf::Vector2f(0.f, 10.f));
    flowerShape.setPoint(1, sf::Vector2f(8.7f, 5.f));
    flowerShape.setPoint(2, sf::Vector2f(8.7f, -5.f));
    flowerShape.setPoint(3, sf::Vector2f(0.f, -10.f));
    flowerShape.setPoint(4, sf::Vector2f(-8.7f, -5.f));
    flowerShape.setPoint(5, sf::Vector2f(-8.7f, 5.f));
    flowerShape.setFillColor(sf::Color::Yellow);
    flowerShape.setPosition(5000.f, 5000.f);
    flowerShape.setScale(8.f, 8.f);

    stemShape.setSize(sf::Vector2f(20.f, 800.f));
    stemShape.setFillColor(sf::Color::Green);
    stemShape.setPosition(390.f, 500.f);

    swingAngle = 0.f;
}


void Cvijet::draw() {
    window->draw(stemShape);

    swingAngle += 0.05f;
    if (swingAngle > 6.283f) {
        swingAngle = 0.f;
    }
    flowerShape.setPosition(stemShape.getPosition() + sf::Vector2f(5.f, -20.f));
    flowerShape.setRotation(sinf(swingAngle) * 20.f);
    window->draw(flowerShape);
}