#include "Cvijet.h"

void Cvijet::sunce()
{
	sf::CircleShape sunce(20);
	sunce.setFillColor(sf::Color::Yellow);
	sf::Time elapsed = clock.getElapsedTime();

	
		if (clock.getElapsedTime().asMilliseconds()>8000)
		{
			sunce.setRadius(30 - 5 * ((clock.getElapsedTime().asMilliseconds() - 3000) / 3000));
			clock.restart();
		}
		else
		{
		sunce.setRadius(30 + 5 * (clock.getElapsedTime().asMilliseconds() / 3000));
	}

	
	

	window->draw(sunce);
}

void Cvijet::cvijet()
{
	sf::CircleShape cvijet(50);
	cvijet.setFillColor(sf::Color::Yellow);
	cvijet.setOutlineColor(sf::Color::Magenta);
	cvijet.setOutlineThickness(50);
	cvijet.setPosition(100, 80);

	window->draw(cvijet);
}

void Cvijet::stabljika()
{
	sf::RectangleShape stabljika(sf::Vector2f(10, 350));
	stabljika.setFillColor(sf::Color::Green);
	stabljika.setPosition(140, 130);

	window->draw(stabljika);
}

void Cvijet::list()
{
	sf::ConvexShape list(4);
	list.setPointCount(67);
	list.setPoint(0, sf::Vector2f(0, 0));
	list.setPoint(1, sf::Vector2f(140, -50));
	list.setPoint(2, sf::Vector2f(350, -60));
	list.setPoint(3, sf::Vector2f(150, 30));
	list.setPosition(140, 400);
	list.setFillColor(sf::Color::Green);

	window->draw(list);
}

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::crtaj()
{
	stabljika();
	sunce();
	list();
	cvijet();
}
