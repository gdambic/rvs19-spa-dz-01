#include "Cvijet.h"
#include <ctime>

Cvijet::Cvijet(sf::RenderWindow* window)
{
    this->window = window;
}

void Cvijet::draw()
{
    int boja1 = rand() % 250 + 1;
    int boja2 = rand() % 250 + 1;
    int boja3 = rand() % 250 + 1;
    sf::CircleShape cvijet(50.f);
    sf::Color boja = sf::Color::Red;
    boja = sf::Color(boja1, boja2, boja3);
    cvijet.setFillColor(boja);

    srand(time(0));
    int pomak = rand() % (400 - 250 + 1) + 10;
    sf::CircleShape sunce(50.f);
    sunce.setPosition(20, 5.f);
    sunce.setFillColor(sf::Color(250, 250, 0));
    sunce.move(pomak, 25.f);
    window->draw(sunce);

    cvijet.setOutlineThickness(25.f);
    cvijet.setPosition(340, 240.f);
    cvijet.setOutlineColor(sf::Color(128, 30, 128));
    window->draw(cvijet);

    sf::RectangleShape stabljika(sf::Vector2f(235.f, 20.f));
    stabljika.setPosition(401, 364.f);
    stabljika.setFillColor(sf::Color(0, 250, 0));
    stabljika.rotate(90.f);
    window->draw(stabljika);

    sf::RectangleShape zemlja(sf::Vector2f(1000.f, 25.f));
    zemlja.setPosition(0, 575.f);
    zemlja.setFillColor(sf::Color(125, 90, 75));
    zemlja.rotate(0.f);
    window->draw(zemlja);

    sf::ConvexShape list;
    list.setPointCount(7);
    list.setPoint(0, sf::Vector2f(411, 448));
    list.setPoint(1, sf::Vector2f(456, 429));
    list.setPoint(2, sf::Vector2f(515, 438));
    list.setPoint(3, sf::Vector2f(501, 485));
    list.setPoint(4, sf::Vector2f(455, 495));
    list.setPoint(5, sf::Vector2f(411, 488));
    list.setPoint(6, sf::Vector2f(381, 468));
    list.setFillColor(sf::Color(0, 250, 0));
    window->draw(list);

}