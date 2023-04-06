#include "Sunce.h"
#include <ctime>
#include <chrono>
#include <thread>

Sunce::Sunce(sf::RenderWindow* window)
{
	this->window = window;
}

void Sunce::draw()
{
	sf::CircleShape sunce(60, 20);
	sunce.setPosition(x, 70);
	sunce.setFillColor(sf::Color::Yellow);
	window->draw(sunce);
	x++;
}
