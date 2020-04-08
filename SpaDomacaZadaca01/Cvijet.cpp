#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;

}

void Cvijet::draw()
{
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color(255, 255, 0));


	shape.setOutlineThickness(30.f);
	shape.setOutlineColor(sf::Color(250, 0, 0));


	shape.setPosition(280.f, 50.f);


	sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
	line.rotate(90.f);


	line.setPosition(330.f, 180.f);
	line.setFillColor(sf::Color(0, 255, 0));

	sf::ConvexShape convex;

	convex.setPointCount(4);

	convex.setPoint(0, sf::Vector2f(330.f, 250.f));
	convex.setPoint(1, sf::Vector2f(385.f, 220.f));
	convex.setPoint(2, sf::Vector2f(480.f, 210.f));
	convex.setPoint(3, sf::Vector2f(385.f, 250.f));
	convex.setFillColor(sf::Color(0, 255, 0));

	sf::CircleShape shape1(30.f);

	shape1.setFillColor(sf::Color(250, 250, 0));
	shape1.setPosition(100.f, 20.f);

	sf::Time elapsed1 = frameClock.getElapsedTime();

	if (elapsed1.asMilliseconds() >= 1000) {

		int r = 30;
		r += 5;
		shape1.setRadius(r);
		window->draw(shape1);

		if (elapsed1.asMilliseconds() >= 2000) frameClock.restart();
	}

	window->draw(shape);
	window->draw(line);
	window->draw(convex);
	window->draw(shape1);
}