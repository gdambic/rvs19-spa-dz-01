#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* prozor) {
    this->prozor = prozor;
    radius = 20;
    rastuca = false;

    // Srediste (zuto)
    srediste.setRadius(radius);
    srediste.setFillColor(sf::Color::Yellow);
    srediste.setPosition(370, 270);

    // Latice (crvene)
    for (int i = 0; i < 6; i++) {
        latice[i].setRadius(20);
        latice[i].setFillColor(sf::Color::Red);
    }
    latice[0].setPosition(370, 220);
    latice[1].setPosition(420, 235);
    latice[2].setPosition(420, 285);
    latice[3].setPosition(370, 300);
    latice[4].setPosition(320, 285);
    latice[5].setPosition(320, 235);

    // Stabljika (zelena)
    stabljika.setSize(sf::Vector2f(10, 150));
    stabljika.setFillColor(sf::Color::Green);
    stabljika.setPosition(385, 320);

    // List lijevi
    list1.setPointCount(3);
    list1.setPoint(0, sf::Vector2f(385, 370));
    list1.setPoint(1, sf::Vector2f(330, 390));
    list1.setPoint(2, sf::Vector2f(385, 410));
    list1.setFillColor(sf::Color::Green);

    // List desni
    list2.setPointCount(3);
    list2.setPoint(0, sf::Vector2f(395, 390));
    list2.setPoint(1, sf::Vector2f(450, 370));
    list2.setPoint(2, sf::Vector2f(395, 410));
    list2.setFillColor(sf::Color::Green);
}

void Cvijet::draw() {
    // Animacija sredista
    if (frameClock.getElapsedTime().asSeconds() > 0.05f) {
        if (rastuca) {
            radius += 0.5f;
            if (radius >= 20) rastuca = false;
        }
        else {
            radius -= 0.5f;
            if (radius <= 15) rastuca = true;
        }
        srediste.setRadius(radius);
        srediste.setPosition(370 + (20 - radius), 270 + (20 - radius));
        frameClock.restart();
    }

    prozor->draw(stabljika);
    prozor->draw(list1);
    prozor->draw(list2);
    for (int i = 0; i < 6; i++)
        prozor->draw(latice[i]);
    prozor->draw(srediste);
}