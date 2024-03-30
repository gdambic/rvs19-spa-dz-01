#include "Sunce.h"

Sunce::Sunce(sf::RenderWindow* window)
{
	this->window = window;
}

void Sunce::draw()
{
	sf::CircleShape shape(90.f);
	shape.setFillColor(sf::Color(252, 227, 3));
	shape.setPosition(-45, -45);
	window->draw(shape);
}
