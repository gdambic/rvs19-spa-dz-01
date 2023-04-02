#include "Sunce.h"

Sunce::Sunce(sf::RenderWindow* window)
{
	this->window = window;
}

void Sunce::draw()
{
	x++;
	sf::CircleShape _Sunce(60.f, 10.f);
	_Sunce.setFillColor(sf::Color(255, 184, 28, 255));
	_Sunce.setPosition(x, y);
	window->draw(_Sunce);
	if (x > 900) {
		x = -225;
	}
}
