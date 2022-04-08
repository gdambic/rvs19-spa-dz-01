#include "Sunce.h"

Sunce::Sunce(sf::RenderWindow* window, float x, float y)
{
	this->window = window;
	setPosition(x, y);

	// Min size: 45, max size: 130
	// TODO: implement min/max size definition
	this->size = 40.f;
	this->sizeChangingDir = 1;
	this->circle = sf::CircleShape(size);

	circle.setFillColor(sf::Color(255, 255, 0));
	circle.setPosition(x, y);
}

void Sunce::tick(sf::Time& dt)
{
	float change = (0.075f * sizeChangingDir) * dt.asMilliseconds();

	if (sizeChangingDir > 0) {
		if (size >= 40.f) {
			size = 40.f;
			sizeChangingDir = -1;
		}
	}
	else if (sizeChangingDir < 0) {
		if (size <= 25.f) {
			size = 25.f;
			sizeChangingDir = 1;
		}
	}

	size += change;
	circle.setRadius(size);
}

void Sunce::draw()
{
	window->draw(circle);
}

void Sunce::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Sunce::getSize()
{
	return size;
}
