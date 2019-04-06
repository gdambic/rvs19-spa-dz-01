#include "Cvijet.h"
#include "cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
}

void Cvijet::draw()
{

	sf::CircleShape shape(200.f);
	shape.setRadius(40.f);
	shape.setOrigin(-55, -55);
	shape.setPointCount(100);
	shape.setFillColor(sf::Color::Yellow);

	sf::CircleShape shape1(200.f);
	shape1.setRadius(30);
	shape1.setOrigin(-25, -5);
	shape1.setPointCount(100);

	sf::CircleShape shape2(200.f);
	shape2.setRadius(30);
	shape2.setOrigin(5, -65);
	shape2.setPointCount(100);

	sf::CircleShape shape3(200.f);
	shape3.setRadius(30);
	shape3.setOrigin(-25, -125);
	shape3.setPointCount(100);

	sf::CircleShape shape4(200.f);
	shape4.setRadius(30);
	shape4.setOrigin(-100, -128);
	shape4.setPointCount(100);

	sf::CircleShape shape5(200.f);
	shape5.setRadius(30);
	shape5.setOrigin(-135, -65);
	shape5.setPointCount(100);

	sf::CircleShape shape6(200.f);
	shape6.setRadius(30);
	shape6.setOrigin(-100, -5);
	shape6.setPointCount(100);

	sf::RectangleShape line(sf::Vector2f(215.f, 5.f));
	line.setFillColor(sf::Color::Green);
	line.rotate(90);
	line.setOrigin(-135, 95);

	sf::ConvexShape convex;


	convex.setPointCount(4);

	
	convex.setPoint(0, sf::Vector2f(0.f, 0.f));
	convex.setPoint(1, sf::Vector2f(75.f, 10.f));
	convex.setPoint(2, sf::Vector2f(60.f, 30.f));
	convex.setPoint(3, sf::Vector2f(75.f, 50.f));
	convex.setOrigin(-95, -210);
	convex.setFillColor(sf::Color::Green);



	window->draw(shape);
	window->draw(shape1);
	window->draw(shape2);
	window->draw(shape3);
	window->draw(shape4);
	window->draw(shape5);
	window->draw(shape6);
	window->draw(line);
	window->draw(convex);

}


