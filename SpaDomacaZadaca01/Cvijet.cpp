#include "Cvijet.h"
#include <iostream>

void Cvijet::draw()
{

	sun.setFillColor(sf::Color(255, 255, 0));
	sun.setPosition(sf::Vector2f(x, y));


	if (x < 650.f)
	{
		x+=2;
	}
	else if (y < 500.f)
	{
		y+=2;
		sun.setFillColor(sf::Color(202, 202, 202));
	}
	

	elipse.setPosition(290.f, 145.f);	
	window->draw(line);

	for (int i = 0; i < 18; i++)
	{
		elipse.setPosition(250.f, 145.f);
		elipse.rotate(20.f);
		window->draw(elipse);
	}
	window->draw(circle);
	window->draw(elipse2);
	window->draw(elipse3);
	window->draw(sun);
}

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	this->circle = sf::CircleShape(50.f);
	this->line = sf::RectangleShape(sf::Vector2f(250.f, 20.f));
	this->elipse = sf::CircleShape(30.f);
	this->elipse2 = sf::CircleShape(30.f);
	this->elipse3 = sf::CircleShape(30.f);
	this->sun = sf::CircleShape(40.f);

	circle.setFillColor(sf::Color(255, 255, 0));
	circle.setOutlineColor(sf::Color(250, 150, 100));
	circle.setPosition(200.f, 100.f);

	elipse.setScale(3.f, 0.5f);
	elipse.scale(0.5f, 0.5f);

	elipse2.setFillColor(sf::Color(34, 139, 34));
	elipse2.setScale(4.f, 1.3f);
	elipse2.scale(1.f, 1.f);
	elipse2.setPosition(230.f, 310.f);
	elipse2.rotate(325.f);

	elipse3.setFillColor(sf::Color(34, 139, 34));
	elipse3.setScale(4.f, 1.3f);
	elipse3.scale(1.f, 1.f);
	elipse3.setPosition(227.f, 375.f);
	elipse3.rotate(215.f);

	line.setFillColor(sf::Color(34, 139, 34));
	line.rotate(90.f);
	line.setPosition(260.f, 190.f);
}
