#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	Time vrijeme = sat.getElapsedTime();

	sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
	rectangle.setSize(sf::Vector2f(1000.f, 1000.f));
	rectangle.setFillColor(sf::Color(0, 0, 200));


	sf::RectangleShape floor(sf::Vector2f(120.f, 50.f));
	floor.setSize(sf::Vector2f(1000.f, 1000.f));
	floor.setFillColor(sf::Color(0, 200, 0));
	floor.setPosition(0.f, 450.f);


	sf::CircleShape octagon(80.f, 8);
	octagon.setFillColor(sf::Color(250, 250, 0));
	octagon.setPosition(75.f, 75.f);
	octagon.setRotation(vrijeme.asMilliseconds() / 10);
	octagon.setOrigin(50, 50);
	octagon.setRadius(50);


	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color(0, 250, 0));
	shape.setOutlineThickness(30.f);
	shape.setOutlineColor(sf::Color(250, 0, 0));
	shape.setPosition(350.f, 200.f);


	sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
	line.rotate(90.f);
	line.setFillColor(sf::Color(0, 250, 0));
	line.setPosition(400.f, 330.f);


	sf::ConvexShape convex;
	convex.setPointCount(5);
	convex.setPoint(0, sf::Vector2f(0.f, 0.f));
	convex.setPoint(1, sf::Vector2f(100.f, 10.f));
	convex.setPoint(2, sf::Vector2f(60.f, 30.f));
	convex.setPoint(3, sf::Vector2f(20.f, 80.f));
	convex.setPoint(4, sf::Vector2f(0.f, 50.f));
	convex.setFillColor(sf::Color(100, 10, 100));
	convex.setPosition(400.f, 330.f);

	window->draw(rectangle);
	window->draw(floor);
	window->draw(octagon);
	window->draw(shape);
	window->draw(line);
	window->draw(convex);
}
