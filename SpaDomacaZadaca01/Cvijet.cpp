#include <iostream>
#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include <vector>
#include <math.h>

Cvijet::Cvijet(sf::RenderWindow* window) {
    this->window = window;
    this->clock = sf::Clock::Clock();
}


void Cvijet::draw() {


    int latice = 8;
    int centerRadius = 25;
    int latRadius = 30;


    float delta = 2 * 3.1415 / latice;

    for (unsigned int i = 0; i < latice; ++i) {

        sf::CircleShape latice;
        latice.setRadius(latRadius);
        latice.setFillColor(sf::Color(255, 0, 0));
        latice.setPosition(100, 190);
        latice.setOrigin(latRadius + (latRadius + centerRadius) * std::sin(i * delta), latRadius + (latRadius + centerRadius) * std::cos(i * delta));
        latice.setOutlineColor(sf::Color::Black);
        latice.setOutlineThickness(1);
        window->draw(latice);
    }


    sf::CircleShape tucak;
    tucak.setRadius(25);
    tucak.setFillColor(sf::Color(255, 255, 0));
    tucak.setPosition(75, 165);
    window->draw(tucak);

    sf::RectangleShape line(sf::Vector2f(180.f, 5.f));
    line.setFillColor(sf::Color(15, 250, 7));
    line.rotate(90.f);
    line.setPosition(100, 275);
    window->draw(line);

    sf::ConvexShape convex;
    convex.setPointCount(4);
    convex.setFillColor(sf::Color(15, 250, 7));
    convex.setPoint(0, sf::Vector2f(100, 400));
    convex.setPoint(1, sf::Vector2f(180, 340));
    convex.setPoint(2, sf::Vector2f(200, 360));
    convex.setPoint(3, sf::Vector2f(180, 380));
    window->draw(convex);

    sf::Int32 t = clock.getElapsedTime().asMilliseconds();

    if (t > 500) {

        if (radiusDirectionPlus == true) {
            radius = radius + 10.f;
        }
        else {
            radius = radius - 10.f;
        }

        if (radius > 70.f) {
            this->radiusDirectionPlus = false;
        }
        else if (radius < 40.f) {
            this->radiusDirectionPlus = true;
        }

        clock.restart();
    }


    sf::CircleShape octagon(radius, 8);
    octagon.setFillColor(sf::Color(250, 250, 7));
    octagon.setPosition(300, 75);
    window->draw(octagon);

}




    



