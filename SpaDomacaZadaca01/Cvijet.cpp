#include "Cvijet.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::CircleShape oblik(50.f);
	oblik.setFillColor(sf::Color::Yellow);
	oblik.setPosition(345, 325);
	oblik.setOutlineThickness(25.f);
	oblik.setOutlineColor(sf::Color::Red);

	sf::RectangleShape stabljika(sf::Vector2f(150.f, 5.f));
	stabljika.rotate(90.f);
	stabljika.setPosition(400, 450);
	stabljika.setFillColor(sf::Color::Green);

	sf::CircleShape list(40.f, 5);
	list.setFillColor(sf::Color::Green);
	list.setPosition(420, 500);
	list.rotate(30);

	srand(time(nullptr));
	int boja1 = rand() % (1000 - 100);
	int boja2 = rand() % (1000 - 100);
	int boja3 = rand() % (1000 - 100);
	int boja4 = rand() % (1000 - 100);


	oblik.setFillColor(sf::Color(boja1, boja2, boja3, boja4));
	stabljika.setFillColor(sf::Color(boja1, boja2, boja3, boja4));
	list.setFillColor(sf::Color(boja1, boja2, boja3, boja4));

	window->draw(oblik);
	window->draw(stabljika);
	window->draw(list);


}
