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
	sf::CircleShape sunce(40, 13);
	sunce.setFillColor(sf::Color::Yellow);
	sunce.setPosition(x, 20);
	window->draw(sunce);
	x++;
}
