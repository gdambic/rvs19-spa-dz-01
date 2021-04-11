#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}
void Cvijet::draw()
{
	sf::CircleShape shape(50.f, 10);
	/*sf::Texture texture;
	if (!texture.loadFromFile("download.png")) {
		std::cout << "Texture failed to load!";
	}*/
	shape.setPosition(50.f, 50.f);
	shape.setFillColor(sf::Color(200, 26, 185));
	/*shape.setTexture(&texture);
	shape.setTextureRect(sf::IntRect(10, 10, 100, 100));*/

	shape.setOutlineThickness(30);
	shape.setOutlineColor(sf::Color(0, 0, 153));
	window->draw(shape);

	sf::RectangleShape stablo(sf::Vector2f(120.f, 50.f));
	stablo.setSize(sf::Vector2f(5.f, 150.f));
	stablo.setFillColor(sf::Color(0, 204, 0));
	stablo.setPosition(98.f, 180.f);

	window->draw(stablo);

	sf::RectangleShape list(sf::Vector2f(120.f, 50.f));
	list.setSize(sf::Vector2f(80.f, 40.f));
	list.setFillColor(sf::Color(0, 204, 0));

	list.setRotation(135.f);
	list.setPosition(183.f, 220.f);
	window->draw(list);
	/*sf::RectangleShape list2(sf::Vector2f(120.f, 50.f));
	list2.setSize(sf::Vector2f(40.f, 80.f));
	list2.setFillColor(sf::Color(0, 204, 0));

	list2.setRotation(135.f);
	list2.setPosition(103.f, 248.f);
	window->draw(list2);*/
	sf::RectangleShape zemlja(sf::Vector2f(120.f, 80.f));
	zemlja.setSize(sf::Vector2f(25.f, 150.f));
	zemlja.setRotation(90.f);
	zemlja.setPosition(180.f, 330.f);
	zemlja.setFillColor(sf::Color(102, 51, 0));

	window->draw(zemlja);

}