#include "Sunce.h"
#include <iostream>

Sunce::Sunce(sf::RenderWindow* window)
{
	this->window = window;
	
}



void Sunce::draw()
{
	x++;

	sf::CircleShape Sun(80.f, 8.f);
	Sun.setFillColor(sf::Color::Yellow);
	Sun.setPosition(x, y);
	window->draw(Sun);


}

