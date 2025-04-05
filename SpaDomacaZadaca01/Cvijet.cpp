#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{

	this->window = window;
}

void Cvijet::draw()
{
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color(255, 255, 0));
	shape.setOutlineThickness(10.f);
	shape.setOutlineColor(sf::Color(255, 255, 255));
	shape.setPosition(300, 200);

	sf::RectangleShape rectangle(sf::Vector2f(5.f, 200.f));
	rectangle.setPosition(350, 300);
	rectangle.setFillColor(sf::Color(0, 255, 0));
	
	this->window->draw(rectangle);
	this->window->draw(shape);
	
}
