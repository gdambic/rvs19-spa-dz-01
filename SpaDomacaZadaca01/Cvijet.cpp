#include "Cvijet.h"


Cvijet::Cvijet(RenderWindow * window)
{
	this->window = window;
}

void Cvijet::draw()
{
	krug.setOrigin(25.f, 25.f);
	krug.setPosition(330.f, 220.f);
	krug.setFillColor(sf::Color(255, 239, 10));
	krug.setOutlineThickness(30.f);
	krug.setOutlineColor(sf::Color(91, 53, 0));
	krug.setPointCount(100);

	stabljika.setPosition(410.f, 420.f);
	stabljika.setRotation(90.f);
	stabljika.setFillColor(Color(54, 204, 0));

	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(405.f, 500.f));
	list.setPoint(1, sf::Vector2f(500.f, 450.f));
	list.setPoint(2, sf::Vector2f(620.f, 460.f));
	list.setPoint(3, sf::Vector2f(530.f, 510.f));
	list.setFillColor(sf::Color(54, 204, 0));

	animacija.setPosition(405.f, 295.f);
	animacija.setFillColor(Color(232, 116, 0));
	animacija.rotate(50.f);

	window->draw(stabljika);
	window->draw(krug);
	window->draw(list);
	window->draw(animacija);
}
