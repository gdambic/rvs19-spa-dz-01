#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) : window(window) {
    pistil.setRadius(100);
    pistil.setFillColor(sf::Color::Color(92, 64, 51, 255));
    pistil.setPosition(300.f, 200.f);

    stem.setSize(sf::Vector2f(10.f, 500.f));
    stem.setFillColor(sf::Color::Green);
    stem.setPosition(395.f, 310.f);

    petal1.setPointCount(7);
    petal1.setPoint(0, sf::Vector2f(50.f, 0.f));
    petal1.setPoint(1, sf::Vector2f(100.f, 100.f)); 
    petal1.setPoint(2, sf::Vector2f(0.f, 100.f));
    petal1.setPoint(3, sf::Vector2f(50.f, 200.f));
    petal1.setPoint(4, sf::Vector2f(100.f, 100.f));
    petal1.setPoint(5, sf::Vector2f(0.f, 100.f));
    petal1.setPoint(6, sf::Vector2f(50.f, 0.f));
    petal1.setFillColor(sf::Color::Yellow);
    petal1.setPosition(350.f, 80.f);

    petal2.setPointCount(7);
    petal2.setPoint(0, sf::Vector2f(50.f, 0.f));
    petal2.setPoint(1, sf::Vector2f(100.f, 100.f));
    petal2.setPoint(2, sf::Vector2f(0.f, 100.f));
    petal2.setPoint(3, sf::Vector2f(50.f, 200.f));
    petal2.setPoint(4, sf::Vector2f(100.f, 100.f));
    petal2.setPoint(5, sf::Vector2f(0.f, 100.f));
    petal2.setPoint(6, sf::Vector2f(50.f, 0.f));
    petal2.setFillColor(sf::Color::Yellow);
    petal2.setPosition(200.f, 200.f);
    petal2.rotate(315);

    petal3.setPointCount(7);
    petal3.setPoint(0, sf::Vector2f(50.f, 0.f));
    petal3.setPoint(1, sf::Vector2f(100.f, 100.f));
    petal3.setPoint(2, sf::Vector2f(0.f, 100.f));
    petal3.setPoint(3, sf::Vector2f(50.f, 200.f));
    petal3.setPoint(4, sf::Vector2f(100.f, 100.f));
    petal3.setPoint(5, sf::Vector2f(0.f, 100.f));
    petal3.setPoint(6, sf::Vector2f(50.f, 0.f));
    petal3.setFillColor(sf::Color::Yellow);
    petal3.setPosition(530.f, 130.f);
    petal3.rotate(45);

    petal4.setPointCount(7);
    petal4.setPoint(0, sf::Vector2f(50.f, 0.f));
    petal4.setPoint(1, sf::Vector2f(100.f, 100.f));
    petal4.setPoint(2, sf::Vector2f(0.f, 100.f));
    petal4.setPoint(3, sf::Vector2f(50.f, 200.f));
    petal4.setPoint(4, sf::Vector2f(100.f, 100.f));
    petal4.setPoint(5, sf::Vector2f(0.f, 100.f));
    petal4.setPoint(6, sf::Vector2f(50.f, 0.f));
    petal4.setFillColor(sf::Color::Yellow);
    petal4.setPosition(350.f, 320.f);

    petal5.setPointCount(7);
    petal5.setPoint(0, sf::Vector2f(50.f, 0.f));
    petal5.setPoint(1, sf::Vector2f(100.f, 100.f));
    petal5.setPoint(2, sf::Vector2f(0.f, 100.f));
    petal5.setPoint(3, sf::Vector2f(50.f, 200.f));
    petal5.setPoint(4, sf::Vector2f(100.f, 100.f));
    petal5.setPoint(5, sf::Vector2f(0.f, 100.f));
    petal5.setPoint(6, sf::Vector2f(50.f, 0.f));
    petal5.setFillColor(sf::Color::Yellow);
    petal5.setPosition(230.f, 460.f);
    petal5.rotate(240);

    petal6.setPointCount(7);
    petal6.setPoint(0, sf::Vector2f(50.f, 0.f));
    petal6.setPoint(1, sf::Vector2f(100.f, 100.f));
    petal6.setPoint(2, sf::Vector2f(0.f, 100.f));
    petal6.setPoint(3, sf::Vector2f(50.f, 200.f));
    petal6.setPoint(4, sf::Vector2f(100.f, 100.f));
    petal6.setPoint(5, sf::Vector2f(0.f, 100.f));
    petal6.setPoint(6, sf::Vector2f(50.f, 0.f));
    petal6.setFillColor(sf::Color::Yellow);
    petal6.setPosition(620.f, 370.f);
    petal6.rotate(120);
}

void Cvijet::draw() {
    window->draw(pistil);
    window->draw(stem);
    window->draw(petal1);
    window->draw(petal2);
    window->draw(petal3);
    window->draw(petal4);
    window->draw(petal5);
    window->draw(petal6);
}
