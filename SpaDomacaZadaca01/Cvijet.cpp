#include "Cvijet.h"
#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) {
    this->window = window;

    sunce.setRadius(20);
    sunce.setFillColor(sf::Color::Yellow);
    sunce.setPosition(20, 20);

    stabljika.setSize(sf::Vector2f(5, 200));
    stabljika.setFillColor(sf::Color::Green);
    stabljika.setPosition(150, 250);

    latica.setRadius(60);
    latica.setFillColor(sf::Color::Red);
    latica.setOutlineThickness(10);
    latica.setOutlineColor(sf::Color::Red);
    latica.setPosition(95, 175);

    tucak.setRadius(35);
    tucak.setFillColor(sf::Color::Yellow);
    tucak.setPosition(120, 200);

    list.setPointCount(4);
    list.setPoint(0, sf::Vector2f(150, 350));
    list.setPoint(1, sf::Vector2f(250, 300));
    list.setPoint(2, sf::Vector2f(350, 330));
    list.setPoint(3, sf::Vector2f(200, 380));
    list.setFillColor(sf::Color::Green);
}

void Cvijet::draw() {
    float r = sunce.getRadius();

    if (raste) {
        r += 0.05f;
        if (r >= 20.0f) raste = false;
    }
    else {
        r -= 0.05f;
        if (r <= 15.0f) raste = true;
    }

    sunce.setRadius(r);

    window->draw(sunce);
    window->draw(stabljika);
    window->draw(list);
    window->draw(latica);
    window->draw(tucak);
}