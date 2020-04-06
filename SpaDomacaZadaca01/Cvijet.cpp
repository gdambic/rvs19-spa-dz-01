#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	x = 300.f;
}

void Cvijet::draw()
{
	//Cvijet
	sf::CircleShape shape(50.f);
	shape.setPosition(100.f, 100.f);
	shape.setFillColor(sf::Color(255, 255, 0));
	shape.setOutlineThickness(50.f);
	shape.setOutlineColor(sf::Color(255, 255, 255));
	window->draw(shape);

	sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
	line.setPosition(150.f, 250.f);
	line.rotate(90.f);
	line.setFillColor(sf::Color(0, 255, 0));
	window->draw(line);

	sf::ConvexShape convex;
	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(150.f, 350.f));
	convex.setPoint(1, sf::Vector2f(200.f, 300.f));
	convex.setPoint(2, sf::Vector2f(250.f, 275.f));
	convex.setPoint(3, sf::Vector2f(225.f, 300.f));
	convex.setFillColor(sf::Color(0, 255, 0));
	window->draw(convex);
	
	sf::ConvexShape convex2;
	convex2.setPointCount(4);
	convex2.setPoint(0, sf::Vector2f(150.f, 375.f));
	convex2.setPoint(1, sf::Vector2f(100.f, 325.f));
	convex2.setPoint(2, sf::Vector2f(50.f, 300.f));
	convex2.setPoint(3, sf::Vector2f(75.f, 325.f));
	convex2.setFillColor(sf::Color(0, 255, 0));
	window->draw(convex2);

	//Sunce
	sf::CircleShape shape2(25.f);
	shape2.setFillColor(sf::Color(255, 255, 0));

	//Animacija Sunca
	if (clock.getElapsedTime().asSeconds() < 1.0f)
	{
		shape2.setPosition(x, 50.f);
		window->draw(shape2);
	}
	if (clock.getElapsedTime().asSeconds() > 1.0f)
	{
		x += 50.f;
		if (x > 500)
		{
			x = 300.f;
		}
		clock.restart();
	}
}
