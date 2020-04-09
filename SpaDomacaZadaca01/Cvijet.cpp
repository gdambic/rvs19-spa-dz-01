#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <ctime>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw() const
{
	sf::CircleShape flwr(50.f, 8);
	flwr.setFillColor(sf::Color::Magenta);
	flwr.setPosition(300.f, 365.f);

	window->draw(flwr);

	sf::CircleShape tucak(20.f);
	tucak.setFillColor(sf::Color::Yellow);
	tucak.setPosition(330.f, 395.f);

	window->draw(tucak);

	sf::RectangleShape line(sf::Vector2f(90.f, 5.f));
	line.setPosition(353.f, 462.f);
	line.rotate(90.f);
	line.setFillColor(sf::Color::Green);

	window->draw(line);
	
	sf::CircleShape leaf(20.f, 3);
	leaf.setPosition(353.f, 462.f);
	leaf.setFillColor(sf::Color::Green);
	leaf.rotate(90.f);

	window->draw(leaf);

	sf::CircleShape sonac(35.f);
	sonac.setFillColor(sf::Color::Yellow);
	sonac.setPosition(10.f, 120.f);

	

	srand(time(0));

	int change1 = rand() % (450 - 120 + 1) + 1;
	int change2 = rand() % (700 - 120 + 1) + 1;
	sonac.setPosition(change2, change1);

	window->draw(sonac);




	



}
