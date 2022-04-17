#include "Cvijet.h"
#include<SFML/Graphics.hpp>
#include "Windows.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw() {

	sf::CircleShape latice(100.f, 8);
	latice.setFillColor(sf::Color(216, 62, 55));
	latice.setOrigin(-300, -100);

	sf::CircleShape tucak(50.f);
	tucak.setFillColor(sf::Color(254, 210, 43));
	tucak.setOrigin(-350, -150);

	sf::RectangleShape stabljika(sf::Vector2f(200.f, 10.f));
	stabljika.setFillColor(sf::Color(58, 148, 1));
	stabljika.rotate(90.f);
	stabljika.setOrigin(-300, 405);

	sf::CircleShape lijeviList(50.f, 3);
	lijeviList.setFillColor(sf::Color(58, 148, 1));
	lijeviList.setOrigin(-300, -405);

	sf::CircleShape desniList(50.f, 3);
	desniList.setFillColor(sf::Color(58, 148, 1));
	desniList.setOrigin(-400, -300);

	sf::CircleShape sunce(50.f);
	sunce.setPosition(100.f, 30.f);
	sunce.setFillColor(sf::Color(254, 210, 43));
	sunce.setOutlineThickness(10.f);
	sunce.setOutlineColor(sf::Color(231, 178, 0));

	while (clock.getElapsedTime().asMilliseconds() > 500)
	{
		sunce.setScale(1.2, 1.2);
		clock.restart();
	}
	
	window->draw(latice);
	window->draw(tucak);
	window->draw(stabljika);
	window->draw(lijeviList);
	window->draw(desniList);
	window->draw(sunce);
}
