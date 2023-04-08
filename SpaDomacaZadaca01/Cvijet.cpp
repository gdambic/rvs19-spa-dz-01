#include "Cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow* window)
{
}

void Cvijet::draw(sf::RenderWindow &window)
{
	window.draw(shape);
	shape.setRadius(50);
	shape.setFillColor(sf::Color::Yellow);
	shape.setOutlineThickness(10);
	shape.setOutlineColor(sf::Color::Red);
	shape.sf::CircleShape::setPosition(300, 200);

	window.draw(line);
	line.setRotation(90);
	line.setSize(sf::Vector2f(150, 5));
	line.setFillColor(sf::Color::Green);
	line.sf::RectangleShape::setPosition(350, 300);

	window.draw(convex);
	convex.setPointCount(3);
	convex.setPoint(0, sf::Vector2f(10, 50));
	convex.setPoint(1, sf::Vector2f(100, 10));
	convex.setPoint(2, sf::Vector2f(120, 30));
	convex.setFillColor(sf::Color::Green);
	convex.sf::ConvexShape::setPosition(340, 326);

	window.draw(ground);
	ground.setSize(sf::Vector2f(800, 80));
	ground.setFillColor(sf::Color(150, 100, 0));
	ground.sf::RectangleShape::setPosition(0, 440);
		

		
	}



