#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::drow()
{
	//STABILJKA
		sf::ConvexShape stabiljka;
		stabiljka.setPointCount(4);
		stabiljka.setPoint(0, sf::Vector2f(199, 300));
		stabiljka.setPoint(1, sf::Vector2f(201, 300));
		stabiljka.setPoint(2, sf::Vector2f(201, 800));
		stabiljka.setPoint(3, sf::Vector2f(199, 800));
		stabiljka.setFillColor(sf::Color::Green);
		stabiljka.setPosition(40, 40);

	//LIST
		sf::ConvexShape list;
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(0, 0));
	list.setPoint(1, sf::Vector2f(-100, 50));
	list.setPoint(2, sf::Vector2f(-100, 150));
	list.setPoint(3, sf::Vector2f(0, 100));
	list.setFillColor(sf::Color::Green);
	list.setPosition(340, 450);

	//TUCAK

		sf::CircleShape tucak(40.f);
		tucak.setFillColor(sf::Color::Yellow);
		tucak.setOutlineThickness(60.f);
		tucak.setOutlineColor(sf::Color::Red);
		tucak.setPosition(200, 200);

	this->window->draw(tucak);
	this->window->draw(list);
	this->window->draw(stabiljka);


}
