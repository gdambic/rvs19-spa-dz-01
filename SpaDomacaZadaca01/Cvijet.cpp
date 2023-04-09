#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace sf;

void Cvijet::draw_flower(float x, float y, float radius)
{
    float m, n;
    RectangleShape line(Vector2f(3.5f, 60.f));
    line.setFillColor(Color(0, 100, 0, 255));
    sf::CircleShape middle(radius);
    middle.setFillColor(Color::Red);

    sf::CircleShape side(13.f, 3);
    side.setFillColor(Color(0, 100, 0, 255));
    side.setPosition(x - 19, y + 45);
    side.rotate(10.f);

    sf::CircleShape side2(13.f, 3);
    side2.setFillColor(Color(0, 100, 0, 255));
    side2.setPosition(x - 2, y + 70);
    side2.rotate(-10.f);

    line.setPosition(x, y + 50);

    m = x - radius;
    n = y - radius;



    middle.setPosition(m, n+10);

    window->draw(line);
    window->draw(middle);

    window->draw(side);
    window->draw(side2);
}




void Cvijet::draw_sun()
{
    CircleShape sun(60.f);
    sun.setFillColor(sf::Color(255, 128, 0));
    sun.setOutlineThickness(30.f);
    sun.setOutlineColor(sf::Color(255, 0, 0));
    sun.setPosition(600.f, 70.f);
    window->draw(sun);
}
void Cvijet::draw_cloud()
{
    sf::ConvexShape cloud;
    cloud.setPointCount(11);
    cloud.setFillColor(sf::Color(255, 255, 255));



    cloud.setPoint(0, sf::Vector2f(10.f, 70.f));
    cloud.setPoint(1, sf::Vector2f(50.f, 90.f));
    cloud.setPoint(2, sf::Vector2f(70.f, 60.f));
    cloud.setPoint(3, sf::Vector2f(100.f,90.f));
    cloud.setPoint(4, sf::Vector2f(120.f, 70.f));
    cloud.setPoint(5, sf::Vector2f(110.f, 50.f));
    cloud.setPoint(6, sf::Vector2f(100.f, 40.f));
    cloud.setPoint(7, sf::Vector2f(80.f, 50.f));
    cloud.setPoint(8, sf::Vector2f(50.f, 40.f));
    cloud.setPoint(9, sf::Vector2f(30.f, 50.f));
    cloud.setPoint(10, sf::Vector2f(10.f, 70.f));
    window->draw(cloud);
}


Cvijet::Cvijet(RenderWindow* window)
{
    this->window = window;
}

void Cvijet::draw(float radius)
{

    draw_flower(90, 300, radius);
    draw_sun();
    draw_cloud();
}
