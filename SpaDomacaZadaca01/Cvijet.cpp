#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
	: window(window)
{
}

void Cvijet::draw()
{	
	//stabljika
	sf::RectangleShape stabljika(sf::Vector2f(250.f, 7.f));
	stabljika.setFillColor(sf::Color(34, 139, 34));
	stabljika.setPosition(300, 350);
	stabljika.rotate(90);
	window->draw(stabljika);

	//list
	sf::ConvexShape list;
	list.setFillColor(sf::Color(34, 139, 34));
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(300.f, 500.f));
	list.setPoint(1, sf::Vector2f(250.f, 450.f));
	list.setPoint(2, sf::Vector2f(180.f, 425.f));
	list.setPoint(3, sf::Vector2f(250.f, 500.f));
	window->draw(list);

	//latice
	sf::CircleShape latice(60.f);
	latice.setPosition(240.f, 240.f);
	latice.setFillColor(sf::Color(255, 0, 0));
	window->draw(latice);

	//cvijet
	sf::CircleShape cvijet(40.f);
	cvijet.setPosition(260.f, 260.f);
	cvijet.setFillColor(sf::Color(255, 255, 0));
	window->draw(cvijet);
}

