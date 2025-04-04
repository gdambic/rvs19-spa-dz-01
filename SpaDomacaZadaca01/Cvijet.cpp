#define _USE_MATH_DEFINES
#include "Cvijet.h"
#include <math.h>

Cvijet::Cvijet(sf::RenderWindow* window) {
    this->window = window;
    angle = 0;
}

void Cvijet::draw() {
    angle += 0.05f;
    const int petalCount = 7;
    const int radius = 60;
    const int petalRadius = 25;

    sf::CircleShape centerCircle(40 + 10 * sin(angle)); //radijus se krece izmedu 30 i 50 ovisno o stupnju (nadam se da je u redu što ne koristim sf::Clock)
    centerCircle.setFillColor(sf::Color::Yellow);
    centerCircle.setOrigin(centerCircle.getRadius(), centerCircle.getRadius());
    centerCircle.setPosition(400, 300);

    sf::RectangleShape stem(sf::Vector2f(10, 250));
    stem.setFillColor(sf::Color::Green);
    stem.setOrigin(stem.getSize().x / 2, 0);
    stem.setPosition(400, 300);

    sf::CircleShape leaf1(15);
    leaf1.setFillColor(sf::Color::Green);
    leaf1.setOrigin(leaf1.getRadius(), leaf1.getRadius());
    leaf1.setPosition(385, 420);

    sf::CircleShape leaf2(15);
    leaf2.setFillColor(sf::Color::Green);
    leaf2.setOrigin(leaf2.getRadius(), leaf2.getRadius());
    leaf2.setPosition(415, 470);

    window->draw(stem);

    for (int i = 0; i < petalCount; ++i) {
        double petalAngle = angle + i * (2 * M_PI / petalCount); //racunanje kuta izmedu latica 
        /* 
        koristit cemo parametarsku jednazbu kruznice za rotaciju latica
        
        x(fi) = r * cos(fi) + p
        y(fi) = r * sin(fi) + q
        */
        double x = centerCircle.getPosition().x + radius * cos(petalAngle);
        double y = centerCircle.getPosition().y + radius * sin(petalAngle);

        sf::CircleShape petal(petalRadius);
        petal.setFillColor(sf::Color::Red);
        petal.setOrigin(petalRadius, petalRadius);
        petal.setPosition(x, y);
        petal.setRotation(petalAngle * 180 / M_PI); // prebacivanje iz radijana u stupnjeve 

        window->draw(petal);
    }
    window->draw(centerCircle);
    window->draw(leaf1);
    window->draw(leaf2);
}