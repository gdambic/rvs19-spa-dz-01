#include "Cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
}

void Cvijet::draw()
{
	//pozadina
	sf::CircleShape shape0(800.f);
	shape0.setFillColor(sf::Color(30, 30, 255));
	shape0.setPosition(-250, -250);
	// circle žute boje
	sf::CircleShape shape1(30.f);
	shape1.setFillColor(sf::Color(255, 255, 0));
	//obrub ljuÈibasti
	shape1.setOutlineThickness(40.f);
	shape1.setOutlineColor(sf::Color(220, 0, 255));
	shape1.setPosition(250, 200);
	//sunce
	sf::CircleShape shape2(30.f);
	shape2.setFillColor(sf::Color(255, 255, 0));
	shape2.setPosition(40, 40);
	//stabljika
	sf::RectangleShape rectangle1(sf::Vector2f(10.f,200.f));
	rectangle1.setFillColor(sf::Color(0, 255, 0));
	rectangle1.setPosition(275, 300);
	//list
	sf::ConvexShape convex;
	convex.setPointCount(5);
	convex.setPoint(0, sf::Vector2f(0.f, 0.f));
	convex.setPoint(1, sf::Vector2f(150.f, 5.f));
	convex.setPoint(2, sf::Vector2f(120.f, 45.f));
	convex.setPoint(3, sf::Vector2f(30.f, 50.f));
	convex.setPoint(4, sf::Vector2f(0.f, 25.f));
	convex.setFillColor(sf::Color(0, 255, 0));
	convex.setPosition(275, 350);
	//trava - zemlja
	sf::RectangleShape rectangle2(sf::Vector2f(3000.f, 250.f));
	rectangle2.setPosition(-50.f, 500.f);
	rectangle2.setFillColor(sf::Color(150, 75, 0));

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		window->clear();
		//iscrtavanje
		window->draw(shape0);
		window->draw(rectangle2);
		window->draw(shape1);
		window->draw(shape2);
		window->draw(rectangle1);
		window->draw(convex);
		//animacija
		shape2.move(sf::Vector2f(0.4f, 0.0f));
		window->display();

	}
}