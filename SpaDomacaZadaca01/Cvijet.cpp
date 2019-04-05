#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow * window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::RectangleShape backg(sf::Vector2f(800, 600));
	backg.setFillColor(sf::Color(85, 85, 255));

	sf::RectangleShape rectangle(sf::Vector2f(20, 600));
	rectangle.setPosition(390, 120);
	rectangle.setFillColor(sf::Color(10, 180, 20));

	sf::CircleShape shape01 = sf::CircleShape(120,8);
	shape01.setPosition(280, 120);
	shape01.setFillColor(sf::Color(255, 85, 85));
	shape01.setOutlineThickness(10);
	shape01.setOutlineColor(sf::Color(212, 10, 10));

	sf::CircleShape shape02(80, 8);
	shape02.setPosition(320, 160);
	shape02.setFillColor(sf::Color(255, 210, 10));

	
	sf::ConvexShape convexA;
	convexA.setPointCount(5);
	convexA.setPoint(0, sf::Vector2f(200, 240));
	convexA.setPoint(1, sf::Vector2f(400, 440));
	convexA.setPoint(2, sf::Vector2f(400, 490));
	convexA.setPoint(3, sf::Vector2f(240, 380));
	convexA.setPoint(4, sf::Vector2f(200, 220));
	convexA.setFillColor(sf::Color(10, 150, 10));

	window->draw(backg);

	window->draw(rectangle);
		
	window->draw(convexA);

	window->draw(shape01);

	window->draw(shape02);
		
}

