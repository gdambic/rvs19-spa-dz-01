#include "Cvijet.h"
#include <iostream>


Cvijet::Cvijet(sf::RenderWindow* window) {
		this->window = window;
	}

void Cvijet::draw() {
	sf::RectangleShape stemaxis(sf::Vector2f(15.f, 100.f));
	stemaxis.setFillColor(sf::Color::Green);
	stemaxis.setPosition(650.f, 450.f);
	window->draw(stemaxis);

	sf::ConvexShape leaf;
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(660.f, 500.f));
	leaf.setPoint(1, sf::Vector2f(500.f, 450.f));
	leaf.setPoint(2, sf::Vector2f(530.f, 420.f));
	leaf.setPoint(3, sf::Vector2f(550.f, 400.f));
	leaf.setFillColor(sf::Color::Green);
	window->draw(leaf);



	sf::CircleShape circle(50.f);
	circle.setFillColor(sf::Color::Yellow);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(25.f);
	circle.setPosition(610.f, 330.f);
	window->draw(circle);
}

