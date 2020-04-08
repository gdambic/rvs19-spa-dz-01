#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include<vector>
#include<iostream>
using namespace std;


Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	duration = float();
	increase = 1;
	direction = 1;
	a = 255;
	b = 0;
	c = 0;

	sf::Color boja = sf::Color(a, b, c);
	std::vector <sf::CircleShape> dijelovi;

	sf::CircleShape petals1(40);
	petals1.setFillColor(sf::Color( a,b,c));
	petals1.setPosition(200, 126);
	petals1.setOutlineColor(sf::Color(255,255,255));
	petals1.setOutlineThickness(5);

	dijelovi.push_back(petals1);

	sf::CircleShape petals3(40);
	petals3.setFillColor(sf::Color(a, b, c));
	petals3.setPosition(211, 225);
	petals3.setOutlineColor(sf::Color(255, 255, 255));
	petals3.setOutlineThickness(5);

	dijelovi.push_back(petals3);

	sf::CircleShape petals2(40);
	petals2.setFillColor(sf::Color(a, b, c));
	petals2.setPosition(245, 170);
	petals2.setOutlineColor(sf::Color(255, 255, 255));
	petals2.setOutlineThickness(5);

	dijelovi.push_back(petals2);

	sf::CircleShape petals5(40);
	petals5.setFillColor(sf::Color(a, b, c));
	petals5.setPosition(149, 217);
	petals5.setOutlineColor(sf::Color(255, 255, 255));
	petals5.setOutlineThickness(5);

	dijelovi.push_back(petals5);


	sf::CircleShape petals4(40);
	petals4.setFillColor(sf::Color(a, b, c));
	petals4.setPosition(144, 155);
	petals4.setOutlineColor(sf::Color(255, 255, 255));
	petals4.setOutlineThickness(5);

	dijelovi.push_back(petals4);

	sf::CircleShape center(25);

	center.setFillColor(sf::Color(a, b, c));
	center.setPosition(210, 200);
	center.setOutlineThickness(5);
	center.setOutlineColor(sf::Color(204, 204, 0));

	dijelovi.push_back(center);

	this->dijelovi = dijelovi;

	sf::RectangleShape stem(sf::Vector2f(225, 7));
	stem.setPosition(227, 280);
	stem.setFillColor(sf::Color(0, 102, 0));
	stem.rotate(90);
	stem.setOutlineColor(sf::Color(0, 153, 0));
	stem.setOutlineThickness(3);

	this->stem = stem;

	sf::ConvexShape leaf;
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(230, 505));
	leaf.setPoint(1, sf::Vector2f(320, 456));
	leaf.setPoint(2, sf::Vector2f(375, 370));
	leaf.setPoint(3, sf::Vector2f(320, 380));
	leaf.setFillColor(sf::Color(0, 102, 0));
	leaf.setOutlineColor(sf::Color(0, 153, 0));
	leaf.setOutlineThickness(3);

	this->leaf = leaf;
}

void Cvijet::draw()
{
	sf::Time time = frameClock.restart();
	duration += time.asSeconds();
	sf::Color boja = sf::Color(a, b, c);

	window->draw(stem);
	window->draw(leaf);
	for (int i = 0; i < dijelovi.size(); i++)
	{
		if (duration > 0.1f)
		{

			dijelovi[i].setRadius(dijelovi[i].getRadius() + direction);
			dijelovi[i].setFillColor(boja);
		}
		window->draw(dijelovi[i]);
		
	}
	if (duration > 0.1f)
	{
		increase += direction;
		if (increase > 8 || increase < -8)
		{
			direction *= -1;
		}
		duration = 0;
		
		if (a == 255)
		{
			a -= 3;
			c += 3;	
		}
		
		if (a!=255)
		{
			for (int i = 0; i < 255; i++)
			{
				a -= 3;
				c += 3;	
			}	
		}
	}
}
	



