#include "Cvijet.h"
#include "SFML/Graphics.hpp"
#include <time.h>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{	
	
	sf::ConvexShape list;
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(294, 404));
	list.setPoint(1, sf::Vector2f(394, 374));
	list.setPoint(2, sf::Vector2f(424, 339));
	list.setPoint(3, sf::Vector2f(364, 344));
	list.setFillColor(sf::Color::Green);
	list.setOutlineColor(sf::Color::Blue);
	list.setOutlineThickness(2);

	enum Smjer { Dolje };
	sf::Vector2i v1(0, Dolje);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		v1.y = Dolje;
		list.move(0, 150);
	}
	window->draw(list);
	

	sf::RectangleShape stem(sf::Vector2f(5, 150));
	stem.setFillColor(sf::Color::Green);
	stem.setPosition(280, 320);
	stem.setOutlineColor(sf::Color::Blue);
	stem.setOutlineThickness(2);
	window->draw(stem);
	

	sf::CircleShape srediste;
	srediste.setRadius(35);
	srediste.setFillColor(sf::Color::Yellow);
	srediste.setPosition(255, 265);
	window->draw(srediste);
	

	sf::CircleShape petal1;
	petal1.setRadius(20);
	petal1.setFillColor(sf::Color::Red);
	petal1.setPosition(250, 250);
	petal1.setOutlineColor(sf::Color::Blue);
	petal1.setOutlineThickness(2);
	window->draw(petal1);

	sf::CircleShape petal2;
	petal2.setRadius(20);
	petal2.setFillColor(sf::Color::Red);
	petal2.setPosition(278, 247);
	petal2.setOutlineColor(sf::Color::Blue);
	petal2.setOutlineThickness(2);
	window->draw(petal2);

	sf::CircleShape petal3;
	petal3.setRadius(20);
	petal3.setFillColor(sf::Color::Red);
	petal3.setPosition(299, 268);
	petal3.setOutlineColor(sf::Color::Blue);
	petal3.setOutlineThickness(2);
	window->draw(petal3);

	sf::CircleShape petal4;
	petal4.setRadius(20);
	petal4.setFillColor(sf::Color::Red);
	petal4.setPosition(294, 297);
	petal4.setOutlineColor(sf::Color::Blue);
	petal4.setOutlineThickness(2);
	window->draw(petal4);

	sf::CircleShape petal5;
	petal5.setRadius(20);
	petal5.setFillColor(sf::Color::Red);
	petal5.setPosition(268, 309);
	petal5.setOutlineColor(sf::Color::Blue);
	petal5.setOutlineThickness(2);
	window->draw(petal5);

	sf::CircleShape petal6;
	petal6.setRadius(20);
	petal6.setFillColor(sf::Color::Red);
	petal6.setPosition(245, 297);
	petal6.setOutlineColor(sf::Color::Blue);
	petal6.setOutlineThickness(2);
	window->draw(petal6);

	sf::CircleShape petal7;
	petal7.setRadius(20);
	petal7.setFillColor(sf::Color::Red);
	petal7.setPosition(238, 272);
	petal7.setOutlineColor(sf::Color::Blue);
	petal7.setOutlineThickness(2);
	window->draw(petal7);
}
