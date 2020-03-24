#include "Cvijet.h"

void Cvijet::setup()
{
	background.setFillColor(sf::Color(100, 150, 100));
	background.setPosition(0.f, 0.f);
	rect.setFillColor(green);
	rect.setPosition(70.0, 135.0);

	circle.setFillColor(sf::Color(250, 250, 150));
	circle.setOutlineThickness(25.f);
	circle.setOutlineColor(sf::Color(250, 50, 50));
	circle.setOrigin(50.f, 50.f);
	circle.setPosition(75.f, 75.f);

	convex.setPointCount(4);
	convex.setFillColor(green);
	convex.setPoint(0, sf::Vector2f(0.f, 0.f));
	convex.setPoint(1, sf::Vector2f(250.f, 10.f));
	convex.setPoint(2, sf::Vector2f(120.f, 45.f));
	convex.setPoint(3, sf::Vector2f(30.f, 50.f));
	convex.setPosition(40.f, 550);
	convex.rotate(-20.f);
	convex.scale(1.5f, 1.5f);

	convex2.setPointCount(4);
	convex2.setFillColor(green);
	convex2.setPoint(0, sf::Vector2f(0.f, 0.f));
	convex2.setPoint(1, sf::Vector2f(150.f, 10.f));
	convex2.setPoint(2, sf::Vector2f(120.f, 90.f));
	convex2.setPoint(3, sf::Vector2f(30.f, 100.f));
	convex2.setPosition(-50.f, 500.f);
	convex2.rotate(20.f);
}

Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
	setup();
}

void Cvijet::draw()
{
	window->draw(background);
	auto color = background.getFillColor();
	if (up) {
		color.r++;
		if (color.r == 150)
			up = !up;
	}
	else {
		color.r--;
		if (color.r == 50)
			up = !up;
	}
	background.setFillColor(color);
	circle.rotate(1.f);
	window->draw(rect);
	window->draw(circle);
	window->draw(convex);
	window->draw(convex2);
}
