#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::print_flower()
{
	flower.setFillColor(sf::Color::Yellow);
	flower.setPosition(50, 50);
	flower.setRadius(20.f);
	flower.setOutlineThickness(50.f);
	flower.setOutlineColor(sf::Color::Blue);
	window->draw(flower);

	sf::Vector2f rectanglePosition(65, 140);
	straw.setPosition(rectanglePosition);
	straw.setFillColor(sf::Color::Green);
	straw.setSize(sf::Vector2f(10, 200));
	window->draw(straw);

	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(65, 340));
	leaf.setPoint(1, sf::Vector2f(65, 270));
	leaf.setPoint(2, sf::Vector2f(150, 150));
	leaf.setPoint(3, sf::Vector2f(150, 200));
	leaf.setFillColor(sf::Color::Green);
	window->draw(leaf);
}

void Cvijet::animate_dot()
{
	dot.setFillColor(sf::Color::Red);
	dot.setPosition(300, 300);

	if (clock.getElapsedTime().asSeconds() < 1)
	{

		dot.setRadius(20);
	}
	if (clock.getElapsedTime().asSeconds() >= 1)
	{
		dot.setRadius(40);
	}
	if (clock.getElapsedTime().asSeconds() >= 2)
	{
		dot.setRadius(60);
	}
	if (clock.getElapsedTime().asSeconds() >= 3)
	{
		clock.restart();
	}
	window->draw(dot);
}


void Cvijet::draw()
{
	print_flower();
	animate_dot();
}
