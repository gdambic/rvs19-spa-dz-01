#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::CircleShape mirko(45.f);
	mirko.setOutlineThickness(35.f);
	mirko.setPosition(sf::Vector2f(100.f, 100.f));
	mirko.setFillColor(sf::Color(192.f, 0.f, 255.f));
	mirko.setOutlineColor(sf::Color(0.f, 128.f, 192.f));

	sf::RectangleShape stabljika(sf::Vector2f(10.f, 185.f));
	stabljika.setPosition(sf::Vector2f(140.f, 225.f));
	stabljika.setFillColor(sf::Color(0.f, 128.f, 0.f));

	sf::ConvexShape list(4);
	list.setFillColor(sf::Color(0.f, 128.f, 0.f));
	list.setPoint(0, sf::Vector2f(148.f, 325.f));
	list.setPoint(1, sf::Vector2f(250.f, 300.f));
	list.setPoint(2, sf::Vector2f(350.f, 325.f));
	list.setPoint(3, sf::Vector2f(250.f, 375.f));

	window->draw(stabljika);
	window->draw(list);
	window->draw(mirko);
}
