#include "Flower.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

Flower::Flower(sf::RenderWindow* window, sf::Clock frameClock) {
	
	this->window = window;
	this->frameClock = frameClock;
}

void Flower::draw_flower()
{
	sf::CircleShape flower_shape(50.f);
	flower_shape.setFillColor(sf::Color(50, 20, 0));
	flower_shape.setOutlineThickness(35.f);
	flower_shape.setOutlineColor(sf::Color::Yellow);
	flower_shape.setOrigin(-70, -50);
	window->draw(flower_shape);

	sf::RectangleShape stem(sf::Vector2f(120.f, 50.f));
	stem.setSize(sf::Vector2f(20.f, 300.f));
	stem.setFillColor(sf::Color(0,150,50));
	stem.setOrigin(-110, -149);
	window->draw(stem);

	sf::RectangleShape stem2(sf::Vector2f(120.f, 50.f));
	stem2.setSize(sf::Vector2f(20.f, 150.f));
	stem2.setFillColor(sf::Color(0, 150, 50));
	stem2.setOrigin(-310, 0);
	stem2.rotate(45.f);
	window->draw(stem2);

	sf::CircleShape floor(700.f);
	floor.setFillColor(sf::Color(0, 100, 50));
	floor.setOrigin(300, -380);
	window->draw(floor);

	float radius = 50.f;
	if ((int)frameClock.getElapsedTime().asSeconds() % 2 == 0)
	{
		radius = 75.f;
	}
	sf::CircleShape sun(radius);
	sun.setFillColor(sf::Color::Yellow);
	sun.setOrigin(-620, -20);
	window->draw(sun);




}





