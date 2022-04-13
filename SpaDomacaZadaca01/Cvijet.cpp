#include "Cvijet.h"
#include "Cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	draw_circle();
	draw_line();
	draw_convex();
}

void Cvijet::draw_circle()
{
	sf::CircleShape circle;
	circle.setRadius(55.f);
	circle.setFillColor(sf::Color(235, 246, 80));
	circle.setPointCount(100);

	circle.setOutlineThickness(20);
	circle.setOutlineColor(sf::Color(250, 57, 57));

	circle.setPosition(100, 110);

	window->draw(circle);
}

void Cvijet::draw_line()
{
	sf::RectangleShape line(sf::Vector2f(150.f, 12.f));
	line.rotate(90);
	line.setFillColor(sf::Color(119, 230, 123));

	line.setPosition(160, 240);
	window->draw(line);
}

void Cvijet::draw_convex()
{
	sf::ConvexShape convex;
	convex.setPointCount(4);
	convex.setFillColor(sf::Color(119, 230, 123));

	//convex.setPosition(160, 300);

	convex.setPoint(0, sf::Vector2f(160,300));
	convex.setPoint(1, sf::Vector2f(220, 250));
	convex.setPoint(2, sf::Vector2f(320, 240));
	convex.setPoint(3, sf::Vector2f(235, 310));

	window->draw(convex);
}