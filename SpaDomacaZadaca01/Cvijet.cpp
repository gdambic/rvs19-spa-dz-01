#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Cvijet::Cvijet(sf::RenderWindow* win) {

	this->window = win;
}

void Cvijet::draw(float time) {

    //pozadina-----------------------------
    window->clear(sf::Color(18, 145, 252));
    //-------------------------------------


    //zemlja-------------------------------
    sf::RectangleShape pod(sf::Vector2f(1000, 1000));
    pod.setFillColor(sf::Color(145, 224, 67));

    pod.setOutlineThickness(10);
    pod.setOutlineColor(sf::Color(130, 199, 63));

    pod.setPosition(-20, 500);
    pod.setRotation(0);
    window->draw(pod);
    //-------------------------------------


    //sunce--------------------------------
    sf::CircleShape sun(20);
    sun.setFillColor(sf::Color::Yellow);


    sun.setOutlineThickness(10);
    sun.setOutlineColor(sf::Color(255, 200, 0));

    sun.setPosition(40, 40);
    sun.setOrigin(20, 20);

    //animacija sunca--
    float scale = 1.0f + std::sin(time * 4.0f) * 0.1f;
    sun.setScale(scale, scale);
    sun.setOutlineThickness(10 * scale);
    //-----------------

    window->draw(sun);
    //-------------------------------------
   

    //stabiljka cvijeta--------------------
    sf::RectangleShape stabiljka1(sf::Vector2f(10, 200));
    stabiljka1.setFillColor(sf::Color(125, 255, 125));

    stabiljka1.setPosition(290, 250);
    stabiljka1.setRotation(5);
    window->draw(stabiljka1);

    sf::RectangleShape stabiljka2(sf::Vector2f(10, 100));
    stabiljka2.setFillColor(sf::Color(125, 255, 125));

    stabiljka2.setPosition(273.5, 448);
    stabiljka2.setRotation(0);
    window->draw(stabiljka2);
    //-------------------------------------


    //listovi cvijeta----------------------
    for (int i = 0; i < 20; i++) {
        sf::CircleShape petal(30);
        petal.setFillColor(sf::Color(255, 200, 255));

        petal.setOutlineThickness(2.5);
        petal.setOutlineColor(sf::Color(245, 190, 245));

        petal.setScale(2.5, 1.0);
        petal.setPosition(300, 200);
        petal.setRotation(90 + (i * 18));

        window->draw(petal);
    }
    //-------------------------------------


    //centar cvijeta-----------------------
    sf::CircleShape flower_center(50);
    flower_center.setFillColor(sf::Color::Yellow);

    flower_center.setOutlineThickness(7.5);
    flower_center.setOutlineColor(sf::Color(255, 235, 0));

    flower_center.setPosition(250, 150);
    window->draw(flower_center);
    //-------------------------------------
}
