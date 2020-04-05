#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include<iostream>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	//Draw line
	sf::RectangleShape line(sf::Vector2f(180.f, 5.f));
	line.rotate(90.f);
	line.setPosition(442.f, 300.f);
	line.setFillColor(sf::Color(0, 128, 0));

	//Draw square
	sf::CircleShape square(60.f, 4);
	square.rotate(90.f);
	square.setPosition(500.f, 275.f);

	//Draw circle
	sf::CircleShape circle(200.f);
	circle.setRadius(25.f);
	circle.setPointCount(100);
	circle.setFillColor(sf::Color(150, 50, 250));
	circle.setPosition(414.f, 309.f);

	window->draw(line);
	window->draw(square);
	window->draw(circle);
}







