#include "Flower.h"
#include <cmath>

Flower::Flower(sf::RenderWindow* window)
    : window(window), currentSunRadius(20.f), sunX(30.f), isGrowing(true), movingRight(true) {

    sun.setRadius(currentSunRadius);
    sun.setFillColor(sf::Color::Yellow);
    sun.setPosition(sunX, 30.f);


    stem.setSize(sf::Vector2f(10.f, 150.f));
    stem.setFillColor(sf::Color(34, 139, 34));
    stem.setPosition(195.f, 250.f);

    for (int i = 0; i < 6; ++i) {
        sf::CircleShape petal(30.f);
        petal.setFillColor(sf::Color(255, 182, 193));
        petal.setOrigin(30.f, 30.f);
        float angle = i * 60.f * 3.14159f / 180.f;
        petal.setPosition(200.f + 40.f * std::cos(angle), 200.f + 40.f * std::sin(angle));
        petals.push_back(petal);
    }

    center.setRadius(25.f);
    center.setFillColor(sf::Color::Yellow);
    center.setOrigin(25.f, 25.f);
    center.setPosition(200.f, 200.f);

    leaf.setPointCount(4);
    leaf.setPoint(0, sf::Vector2f(0.f, 0.f));
    leaf.setPoint(1, sf::Vector2f(50.f, -20.f));
    leaf.setPoint(2, sf::Vector2f(80.f, 0.f));
    leaf.setPoint(3, sf::Vector2f(40.f, 20.f));
    leaf.setFillColor(sf::Color(50, 205, 50));
    leaf.setPosition(205.f, 320.f);
}

void Flower::draw() {
    if (isGrowing) {
        currentSunRadius += 0.02f;
        if (currentSunRadius >= 22.f) isGrowing = false;
    }
    else {
        currentSunRadius -= 0.02f;
        if (currentSunRadius <= 18.f) isGrowing = true;
    }
    sun.setRadius(currentSunRadius);


    float speed = 0.35f;
    if (movingRight) {
        sunX += speed;

        if (sunX >= 500.f) movingRight = false;
    }
    else {
        sunX -= speed;
        if (sunX <= 10.f) movingRight = true;
    }


    sun.setPosition(sunX, 30.f);

    window->draw(sun);
    window->draw(stem);
    window->draw(leaf);
    for (auto& petal : petals) {
        window->draw(petal);
    }
    window->draw(center);
}