#include "Pozadina.h"

Pozadina::Pozadina(sf::RenderWindow* window)
{
	this->window = window;

	grass = sf::RectangleShape(sf::Vector2f(window->getSize().x, 80));
	grass.setPosition(0, window->getSize().y - 80);
	grass.setFillColor(sf::Color(0, 155, 0));

	sun = sf::CircleShape(50);
	sun.setPosition(10, 10);
	sun.setFillColor(sf::Color::Yellow);
}

void Pozadina::draw()
{
	window->draw(grass);
	window->draw(sun);
}
