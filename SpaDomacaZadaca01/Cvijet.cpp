#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* proz) : window(proz), laticaScale(1.0f), scalingUp(true) {
    latica.setRadius(50.f);
    latica.setPosition(100.f, 50.f);
    latica.setFillColor(sf::Color::Red);
    latica.setOutlineColor(sf::Color::Black);
    latica.setOutlineThickness(2.f);
    latica.setScale(laticaScale, laticaScale);

    centar.setRadius(30.f);
    centar.setPosition(120.f, 70.f);
    centar.setFillColor(sf::Color::Yellow);

    stabljika.setSize(sf::Vector2f(10.f, 100.f));
    stabljika.setPosition(140.f, 150.f);
    stabljika.setFillColor(sf::Color::Green);

    list.setPointCount(4);
    list.setPoint(0, sf::Vector2f(150.f, 220.f));
    list.setPoint(1, sf::Vector2f(200.f, 250.f));
    list.setPoint(2, sf::Vector2f(180.f, 200.f));
    list.setPoint(3, sf::Vector2f(130.f, 170.f));
    list.setFillColor(sf::Color::Green);
}

void Cvijet::draw() {
    float elapsedTime = frameClock.restart().asSeconds();
    float scaleChange = 0.1f * elapsedTime;

    if (scalingUp) {
        laticaScale += scaleChange;
        if (laticaScale > 1.2f) scalingUp = false;
    } else {
        laticaScale -= scaleChange;
        if (laticaScale < 0.8f) scalingUp = true;
    }

    latica.setScale(laticaScale, laticaScale);

    window->draw(latica);
    window->draw(centar);
    window->draw(stabljika);
    window->draw(list);
}