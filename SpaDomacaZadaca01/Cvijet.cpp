#include "Cvijet.h"

using namespace std;

Cvijet::Cvijet(sf::RenderWindow* window) : window(window) {
    latice1.setRadius(25.0f);
    latice1.setFillColor(sf::Color::Yellow);
    latice1.setOrigin(150.0f, 150.0f);
    latice1.setOutlineColor(sf::Color::Red);
    latice1.setOutlineThickness(-2.0f);

    latice2.setRadius(50.0f);
    latice2.setFillColor(sf::Color::White);
    latice2.setOrigin(50.0f, 50.0f);
    latice2.setOutlineColor(sf::Color::Magenta);
    latice2.setOutlineThickness(-10.0f);

    latice3.setRadius(20.0f);
    latice3.setFillColor(sf::Color::Blue);
    latice3.setOrigin(20.0f, 20.0f);
    latice3.setOutlineColor(sf::Color::Black);
    latice3.setOutlineThickness(-3.0f);

    stabljika.setPointCount(10);
    stabljika.setPoint(0, sf::Vector2f(-2.0f, 10.0f));
    stabljika.setPoint(1, sf::Vector2f(-2.0f, 45.0f));
    stabljika.setPoint(2, sf::Vector2f(-70.0f, 15.0f));
    stabljika.setPoint(3, sf::Vector2f(-2.0f, 50.0f));
    stabljika.setPoint(4, sf::Vector2f(-2.0f, 180.0f));
    stabljika.setPoint(5, sf::Vector2f(2.0f, 180.0f));
    stabljika.setPoint(6, sf::Vector2f(2.0f, 100.0f));
    stabljika.setPoint(7, sf::Vector2f(70.0f, 90.0f));
    stabljika.setPoint(8, sf::Vector2f(2.0f, 80.0));
    stabljika.setPoint(9, sf::Vector2f(2.0f, 10.0f));
    stabljika.setFillColor(sf::Color::Green);

}

void Cvijet::draw() {

    window->draw(stabljika);
    window->draw(latice2);
    window->draw(latice1);
    window->draw(latice3);
    latice1.rotate(okretanje);

}



