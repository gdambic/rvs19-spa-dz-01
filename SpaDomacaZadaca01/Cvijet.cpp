#include "Cvijet.h"
#include <iostream>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{	
	//flower head
	sf::CircleShape flower(150.f);
	flower.setFillColor(sf::Color(255, 234, 0));
	flower.setPosition(sf::Vector2f(280.f, 80.f));
	window->draw(flower);
	flower.setOutlineThickness(-50.f);
	flower.setOutlineColor(sf::Color(255, 87, 51));
	window->draw(flower);

	//branch
	sf::RectangleShape line(sf::Vector2f(200.f, 10.f));
	line.setPosition(sf::Vector2f(433.f, 379.f));
	line.setFillColor(sf::Color(100, 250, 50));
	line.rotate(90.f);
	window->draw(line);

	//leaf on the branch
	sf::ConvexShape leaf;
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(433.f, 490.f));
	leaf.setPoint(1, sf::Vector2f(533.f, 490.f));
	leaf.setPoint(2, sf::Vector2f(633.f, 445.f));
	leaf.setPoint(3, sf::Vector2f(533.f, 445.f));
	leaf.setFillColor(sf::Color(100, 250, 50));
	window->draw(leaf);

	//animated sun
	sf::CircleShape sun(40.f);
	sun.setPosition(sf::Vector2f(50.f, 50.f));
	sun.setFillColor(sf::Color(255, 234, 0));

	if (clock.getElapsedTime().asMilliseconds() > 1000.f) {
		sun.setRadius(40.f - 10.f * ((clock.getElapsedTime().asMilliseconds() - 1000.f) / 1000.f) );
		if (clock.getElapsedTime().asMilliseconds() >= 2000.f) {
			clock.restart();
		}
	}
	else {
		sun.setRadius(30.f + 10.f * (clock.getElapsedTime().asMilliseconds() / 1000.f));
	}
	window->draw(sun);
}
