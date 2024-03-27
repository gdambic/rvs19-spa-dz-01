#pragma once
#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) : window(window), sunRadius(50), increasing(true) {}

void Cvijet::draw() {
    if (frameClock.getElapsedTime().asSeconds() > 0.5) {
        if (increasing) {
            sunRadius += 1;
            if (sunRadius >= 50) {
                increasing = false;
            }
        }
        else {
            sunRadius -= 1;
            if (sunRadius <= 25) {
                increasing = true;
            }
        }
        frameClock.restart();
    }

    sf::CircleShape sun(sunRadius);
    sun.setFillColor(sf::Color(255, 255, 0));
    sun.setPosition(50, 50);

    window->draw(sun);

    sf::RectangleShape peteljka(sf::Vector2f(10, 200));
    peteljka.setFillColor(sf::Color(0, 255, 0));
    peteljka.setPosition(395, 400);

    sf::CircleShape latica(90, 7);
    latica.setFillColor(sf::Color(255, 0, 0)); 
    latica.setPosition(300, 260);

    sf::CircleShape centar(50);
    centar.setFillColor(sf::Color(255, 255, 0));
    centar.setPosition(340, 300);

    window->draw(peteljka);
    window->draw(latica);
    window->draw(centar);
}