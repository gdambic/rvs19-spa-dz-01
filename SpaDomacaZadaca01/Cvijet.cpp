#include "Cvijet.h"
#include <iostream>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::RectangleShape stemaxis(sf::Vector2f(10.f, 200.f));
	stemaxis.setFillColor(sf::Color::Green);
	stemaxis.setPosition(145.f, 250.f);
	//stemaxis.rotate(90.f);
	window->draw(stemaxis);

	sf::ConvexShape leaf;
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(150.f, 400.f));
	leaf.setPoint(1, sf::Vector2f(350.f, 300.f));
	leaf.setPoint(2, sf::Vector2f(300.f, 200.f));
	leaf.setPoint(3, sf::Vector2f(300.f, 200.f));
	leaf.setFillColor(sf::Color::Green);
	window->draw(leaf);
	
	sf::CircleShape circle(100.f);
	circle.setFillColor(sf::Color::Yellow);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(25.f);
	circle.setPosition(50.f, 50.f);
	window->draw(circle);


	
}
