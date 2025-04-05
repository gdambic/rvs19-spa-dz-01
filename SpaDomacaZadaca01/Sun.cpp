#include "Sun.h"

Sun::Sun(double radius, sf::Color color)
    : speed(5.f), positionY(100.f), increasing(true) {
    sun.setRadius(radius);
    sun.setFillColor(color);
    sun.setPosition(100.f - radius, positionY); // Center the sun horizontally
}

void Sun::update(float deltaTime) {
    if (increasing) {
        positionY -= speed * deltaTime;
        if (positionY <= 50.f) {
            increasing = false; // Change direction
        }
    }
    else {
        positionY += speed * deltaTime;
        if (positionY >= 100.f) {
            increasing = true; // Change direction
        }
    }
    sun.setPosition(700.f - sun.getRadius(), positionY); // Update the position
}

void Sun::draw(sf::RenderWindow& window) {
    window.draw(sun);
}