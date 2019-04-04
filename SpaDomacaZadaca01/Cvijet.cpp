#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>

Cvijet::Cvijet(sf::RenderWindow* window) : 

window{window},
sun{new sf::CircleShape(25.f)}, 
flowerHead{ new sf::CircleShape(100.f)  },
flowerCore{ new sf::CircleShape(50.f)},
flowerStem{ new sf::RectangleShape(sf::Vector2f(300.f, 5.f)) },
leaf{ new sf::ConvexShape() }

{
	sun->setFillColor(sf::Color(198, 225, 24));
	sun->setPosition(600.f, 0);

	flowerHead->setFillColor(sf::Color(225, 37, 24));
	flowerHead->setPosition(350.f, 50.f);

	flowerCore->setFillColor(sf::Color(198, 225, 24));
	flowerCore->setPosition(400.f, 100.f);

	flowerStem->setFillColor(sf::Color(33, 191, 54));
	flowerStem->setPosition(450.f, 250.f);
	flowerStem->rotate(90.f);

	leaf->setPointCount(4);
	leaf->setPoint(0, sf::Vector2f(450.f, 375.f));
	leaf->setPoint(1, sf::Vector2f(475.f, 325.f));
	leaf->setPoint(2, sf::Vector2f(600.f, 315.f));
	leaf->setPoint(3, sf::Vector2f(475.f, 375.f));
	leaf->setFillColor(sf::Color(33, 191, 54));
}

Cvijet::~Cvijet() { delete sun, flowerCore, flowerHead, flowerStem, leaf; }

void Cvijet::move()
{
	flowerCore->move(-0.5f, 0);
	flowerHead->move(-0.5f, 0);
	flowerStem->move(-0.5f, 0);
	leaf->move(-0.5f, 0);
}

void Cvijet::draw()
{
	window->draw(*sun);
	window->draw(*leaf);
	window->draw(*flowerStem);
	window->draw(*flowerHead);
	window->draw(*flowerCore);
}
