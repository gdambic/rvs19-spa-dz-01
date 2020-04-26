#include "Cvijet.h"
#include<iostream>
using namespace std;

Cvijet::Cvijet(sf::RenderWindow * window)
{	
	this->window = window;
}

void Cvijet::draw()
{
	sf::CircleShape cvijet(120.f, 5);
	cvijet.setFillColor(sf::Color(10, 255, 250));		
	cvijet.setOutlineColor(sf::Color(200, 10, 240));	
	cvijet.setOutlineThickness(-50);
	cvijet.setPosition(sf::Vector2f(270, 110));

	sf::RectangleShape stabljika(sf::Vector2f(260.f, 15.f));
	stabljika.setFillColor(sf::Color(0, 255, 0));
	stabljika.rotate(90.f);
	stabljika.setPosition(sf::Vector2f(397, 326));

	sf::ConvexShape list(4);
	list.setFillColor(sf::Color(0, 255, 0));
	list.setPoint(0, sf::Vector2f(398, 470));
	list.setPoint(1, sf::Vector2f(470, 450));
	list.setPoint(2, sf::Vector2f(520, 400));
	list.setPoint(3, sf::Vector2f(460, 390));

	sf::CircleShape sunce(40);
	sunce.setFillColor(sf::Color(255, 255, 0));
	sunce.setPosition(60, 80);

	window->draw(cvijet);
	window->draw(stabljika);
	window->draw(list);
	window->draw(sunce);
	
}
