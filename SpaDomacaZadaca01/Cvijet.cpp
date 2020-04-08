#include "Cvijet.h"
#include <SFML/Graphics.hpp>


using namespace std;


Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{



	sf::CircleShape shape(45.f);
	shape.setFillColor(sf::Color(150, 100, 250));
	shape.setOutlineThickness(5.f);
	shape.setOutlineColor(sf::Color(250, 50, 20));
	shape.setPosition(100.f, 100.f);

	window->draw(shape);
	sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
	line.rotate(90.f);
	line.setFillColor(sf::Color(100, 250, 50));
	line.setPosition(150.f, 195.f);
	window->draw(line);
	sf::ConvexShape convex;

	convex.setPointCount(3);
	convex.setPoint(0, sf::Vector2f(30.f, 150.f));
	convex.setPoint(1, sf::Vector2f(145.f, 250.f));
	convex.setPoint(2, sf::Vector2f(145.f, 345.f));
	convex.setFillColor(sf::Color(100, 240, 40));
	window->draw(convex);


	convex.setPointCount(3);
	convex.setPoint(0, sf::Vector2f(270.f, 150.f));
	convex.setPoint(1, sf::Vector2f(150.f, 250.f));
	convex.setPoint(2, sf::Vector2f(150.f, 345.f));
	convex.setFillColor(sf::Color(100, 240, 40));
	window->draw(convex);









	
}