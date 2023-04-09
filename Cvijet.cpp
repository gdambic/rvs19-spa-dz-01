#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

Cvijet::Cvijet(sf::RenderWindow* window) : window(window)
{
	this->window = window;
}

void Cvijet::draw() const
{
	sf::CircleShape circle(100);
	circle.setRadius(60);
	circle.setPointCount(300);
	circle.setFillColor(sf::Color::Yellow);
	circle.setPosition(sf::Vector2f(360, 240));
	circle.setOutlineThickness(45);
	circle.setOutlineColor(sf::Color::Magenta);

	float xsun = 3;
	float ysun = 3;

	sf::CircleShape sun;
	sf::Vector2f sunPosition(0, 0);
	sun.setPointCount(300);
	sun.setRadius(45);
	sun.setFillColor(sf::Color::Yellow);
	sun.setPosition(sunPosition);


	sf::RectangleShape line(sf::Vector2f(300.f, 10.f));
	line.rotate(90.f);
	line.setFillColor(sf::Color::Green);
	line.setPosition(425, 410);

	sf::ConvexShape convex;
	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(0.f, 0.f));
	convex.setPoint(1, sf::Vector2f(100.f, 10.f));
	convex.setPoint(2, sf::Vector2f(150.f, 90.f));
	convex.setPoint(3, sf::Vector2f(75.f, 100.f));
	convex.setFillColor(sf::Color::Green);
	convex.setPosition(425, 500);	
	convex.setRotation(290.f);
	
	sf::ConvexShape convex2;
	convex2.setPointCount(4);
	convex2.setPoint(0, sf::Vector2f(75.f, 100.f));
	convex2.setPoint(1, sf::Vector2f(150.f, 90.f));
	convex2.setPoint(2, sf::Vector2f(100.f, 10.f));
	convex2.setPoint(3, sf::Vector2f(0.f, 0.f));
	convex2.setFillColor(sf::Color::Green);
	convex2.setPosition(420, 530);
	convex2.setRotation(180.f);

	window->draw(circle);
	window->draw(sun);
	window->draw(line);
	window->draw(convex);
	window->draw(convex2);
}
