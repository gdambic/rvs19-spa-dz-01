#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
}

void Cvijet::draw(sf::Clock time)
{
	double color = abs(sin(time.getElapsedTime().asMicroseconds() / 1000000.0) * 254);
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color(color, color, 255 - color));
	shape.setPosition(100.f, 100.f);

	shape.setOutlineThickness(30.f);
	shape.setOutlineColor(sf::Color(color, 255 - color, 255 - color));

	sf::RectangleShape rectangle(sf::Vector2f(10.f, 150.f));
	rectangle.setFillColor(sf::Color(255 - color, color, 255 - color));
	rectangle.setPosition(145.f, 230.f);
	rectangle.setRotation(-10 + color / 20);

	sf::ConvexShape convex;
	convex.setPointCount(4);
	convex.setFillColor(sf::Color(255 - color, color, 255 - color));
	convex.setPosition(145.f, 226.f);


	convex.setPoint(0, sf::Vector2f(0.f, 70.f));
	convex.setPoint(1, sf::Vector2f(60.f, 30.f));
	convex.setPoint(2, sf::Vector2f(170.f, 15.f));
	convex.setPoint(3, sf::Vector2f(60.f, 80.f));
	convex.setRotation(-10 + color / 20);

	window->draw(shape);
	window->draw(rectangle);
	window->draw(convex);
}
