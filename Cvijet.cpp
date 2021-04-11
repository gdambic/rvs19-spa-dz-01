#include "Cvijet.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Cvijet::Cvijet(sf::RenderWindow* window)
{
    this->window = window;

}

void Cvijet::draw()
{

    draw_background();
    draw_sunce();
    draw_trup();
    draw_latice();

}


void Cvijet::draw_trup() {

    sf::RectangleShape stabljika;

    stabljika.setSize(sf::Vector2f(300, 15));
    stabljika.setFillColor(sf::Color(138, 194, 73));
    stabljika.rotate(-90);
    stabljika.setPosition(600, 550);

    window->draw(stabljika);

   
    sf::CircleShape centar;

    centar.setRadius(40);
    centar.setFillColor(sf::Color::Yellow);
    centar.setOrigin(40, 40);
    centar.setPosition(607.5, 220);
    window->draw(centar);
    

    sf::ConvexShape list1;

    list1.setPointCount(4);

    list1.setPoint(0, sf::Vector2f(615, 450));
    list1.setPoint(1, sf::Vector2f(665, 470));
    list1.setPoint(2, sf::Vector2f(765, 400));
    list1.setPoint(3, sf::Vector2f(665, 400));
    list1.setFillColor(sf::Color(60, 142, 65));

    window->draw(list1);

    sf::ConvexShape list2;

    list2.setPointCount(4);

    list2.setPoint(0, sf::Vector2f(600, 450));
    list2.setPoint(1, sf::Vector2f(550, 470));
    list2.setPoint(2, sf::Vector2f(450, 400));
    list2.setPoint(3, sf::Vector2f(550, 400));
    list2.setFillColor(sf::Color(60, 142, 65));

    window->draw(list2);
}

void Cvijet::draw_latice()
{

    sf::CircleShape latice;;
    latice.setRadius(45);
    latice.move(607.5, 220);
    latice.setRotation(0);
    for (int i = 0; i < 13; i++) {

        latice.rotate(30);
        window->draw(latice);
        latice.setFillColor(sf::Color(68, 46, 133));
        latice.setOutlineThickness(2);
        latice.setOutlineColor(sf::Color(68, 46, 133));
    }
}

void Cvijet::draw_sunce()
{
    auto t = clock.getElapsedTime();
    stringstream ss;

    ss << t.asSeconds();
    int timer;
    ss >> timer;

    int radius = 100;
    sf::CircleShape sunce;
    sunce.setRadius(radius);
    sunce.setFillColor(sf::Color(253, 184, 19));
    sunce.setOrigin(radius, radius);
    sunce.setOutlineColor(sf::Color(241, 112, 34));
    sunce.setOutlineThickness(10);
    sunce.setPosition(250, 250);

    if (timer % 2 == 0)sunce.setRadius(radius*2-50),sunce.setPosition(200, 200);

    window->draw(sunce);
}

void Cvijet::draw_background()const {
    sf::RectangleShape nebo(sf::Vector2f(800, 550));
    nebo.setPosition(0, 0);
    nebo.setFillColor(sf::Color(135, 206, 235));
    window->draw(nebo);

    sf::RectangleShape trava(sf::Vector2f(800, 50));
    trava.setPosition(0, 550);
    trava.setFillColor(sf::Color(124, 252, 0));
    window->draw(trava);
}