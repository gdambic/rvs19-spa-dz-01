#include "Cvijet.h"
#include <cmath>

Cvijet::Cvijet(sf::RenderWindow* window) : window(window) {}

void Cvijet::draw() {
    drawStem();
    drawFlower();
}

void Cvijet::update() {
    static sf::Clock frameClock;
    float dt = frameClock.restart().asSeconds();

    float scaleFactor = std::sin(circleScaleSpeed * dt);
    float scaleChange = 0.1f * scaleFactor;

    innerCircleRadius += scaleChange;


    float maxInnerRadius = outerCircleRadius - 5.0f;
    if (innerCircleRadius < 15) {
        circleScaleSpeed *= -1;
    }
    else if (innerCircleRadius > maxInnerRadius) {
        circleScaleSpeed *= -1;
    }
}

void Cvijet::drawFlower() {

    sf::CircleShape outerCircle(outerCircleRadius);
    outerCircle.setFillColor(sf::Color::Red);
    outerCircle.setPosition(centerPosition - sf::Vector2f(outerCircleRadius, outerCircleRadius));
    window->draw(outerCircle);


    sf::CircleShape innerCircle(innerCircleRadius);
    innerCircle.setFillColor(sf::Color::Yellow);
    innerCircle.setPosition(centerPosition - sf::Vector2f(innerCircleRadius, innerCircleRadius));
    window->draw(innerCircle);


    sf::ConvexShape leaf;
    leaf.setPointCount(4);
    leaf.setPoint(0, sf::Vector2f(centerPosition.x + 55, centerPosition.y + 75));
    leaf.setPoint(1, sf::Vector2f(centerPosition.x + 120, centerPosition.y + 70));
    leaf.setPoint(2, sf::Vector2f(centerPosition.x, centerPosition.y + stemLength - 20));
    leaf.setPoint(3, sf::Vector2f(centerPosition.x, centerPosition.y + stemLength));
    leaf.setFillColor(sf::Color::Green);
    window->draw(leaf);
}


void Cvijet::drawStem() {
    sf::RectangleShape stem(sf::Vector2f(10, stemLength));
    stem.setPosition(centerPosition.x - 5, centerPosition.y);
    stem.setFillColor(sf::Color::Green);
    window->draw(stem);
}
