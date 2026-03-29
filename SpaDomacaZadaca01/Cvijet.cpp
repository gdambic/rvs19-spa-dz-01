#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) {
    this->window = window; 
}

void Cvijet::draw() {
   
    sf::RectangleShape stabljika(sf::Vector2f(10.f, 300.f));
    stabljika.setFillColor(sf::Color::Green);
    stabljika.setPosition(150.f, 250.f);

    
    sf::CircleShape latice(100.f);
    latice.setFillColor(sf::Color::Red);
    latice.setPosition(55.f, 120.f);

    
    sf::CircleShape tucak(65.f);
    tucak.setFillColor(sf::Color::Yellow);
    tucak.setPosition(90.f, 155.f);

    sf::ConvexShape list;
    list.setPointCount(4);
    list.setFillColor(sf::Color::Green);
    list.setPoint(0, sf::Vector2f(155.f, 420.f));
    list.setPoint(1, sf::Vector2f(250.f, 370.f));
    list.setPoint(2, sf::Vector2f(450.f, 350.f));
    list.setPoint(3, sf::Vector2f(250.f, 450.f));
 
    sf::CircleShape sunce(40.f);
    sunce.setFillColor(sf::Color::Yellow);
    sunce.setOrigin(40.f, 40.f); 
    sunce.setPosition(600.f, 100.f);

    float t = clock.getElapsedTime().asSeconds();
    float skalaZrake = 1.1f + sin(t * 4.0f) * 0.3f;

    for (int i = 0; i < 8; i++) {
        sf::RectangleShape zraka(sf::Vector2f(40.f, 4.f));
        zraka.setFillColor(sf::Color::Yellow);

        zraka.setOrigin(-15.f, 2.f);
        zraka.setPosition(600.f, 100.f);

        zraka.setRotation(i * 45.f + t * 50.f);

        zraka.setScale(skalaZrake, 1.0f);

        window->draw(zraka);
    }

    window->draw(stabljika);
    window->draw(latice);
    window->draw(tucak);
    window->draw(list);
    window->draw(sunce);
    
}