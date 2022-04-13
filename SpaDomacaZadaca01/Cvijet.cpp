#include <SFML/Graphics.hpp>
#include "Cvijet.h"
using namespace sf;
using namespace std;

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}

void Cvijet::outlineAndShape()
{
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color(255, 0, 120));

	// position of shape
	shape.setPosition(100.f, 70.f);
	shape.move(5.f, 5.f);
	sf::Vector2f position = shape.getPosition();

	// 20-pixel wide yellow outline
	shape.setOutlineThickness(40.f);
	shape.setOutlineColor(sf::Color(255,255,0));
	window->draw(shape);
}

void Cvijet::line()
{
	sf::RectangleShape line(sf::Vector2f(200.f, 7.f));

	// position of line
	line.rotate(90.f);
	line.setPosition(155.f, 210.f);
	line.move(5.f, 5.f);

	// color of line(green)
	line.setFillColor(sf::Color(0, 255, 0));
	sf::Vector2f position = line.getPosition();
	window->draw(line);

}

void Cvijet::convexShape()
{
	// create an empty shape
	sf::ConvexShape convex;
	

	// resize it to 4 points
	convex.setPointCount(4);

	// define the points
	convex.setPoint(0, sf::Vector2f(30.f, 90.f));
	convex.setPoint(1, sf::Vector2f(30.f, 100.f));
	convex.setPoint(2, sf::Vector2f(0.f, 0.f));
	convex.setPoint(3, sf::Vector2f(100.f, 120.f));

	//position of convexShape
	convex.setPosition(150.f, 295.f);
	convex.rotate(260.f);
	convex.move(5.f, 5.f);
	sf::Vector2f position = convex.getPosition();

	// color of convexShape
	convex.setFillColor(sf::Color(0, 255, 0));
	window->draw(convex);


	//NEW EMPTY SHAPE
	sf::ConvexShape convex1;

	// size it to 4 points
	convex1.setPointCount(4);

	// define the points
	convex1.setPoint(0, sf::Vector2f(30.f, 90.f));
	convex1.setPoint(1, sf::Vector2f(30.f, 100.f));
	convex1.setPoint(2, sf::Vector2f(0.f, 0.f));
	convex1.setPoint(3, sf::Vector2f(100.f, 120.f));

	//position of convexShape1
	convex1.setPosition(150.f, 350.f);
	convex1.rotate(170.f);
	convex1.move(5.f, 5.f);
	sf::Vector2f position1 = convex1.getPosition();

	// color of convexShape1
	convex1.setFillColor(sf::Color(0, 255, 0));
	window->draw(convex1);
}

void Cvijet::ShapeForAnimation()
{
	// shape in animation
	sf::CircleShape shape3(25.f);
	shape3.setFillColor(sf::Color(255, 255, 0));

	// position of shape
	shape3.setPosition(3.f, 3.f);
	shape3.setRotation(rotation);
	shape3.move(5.f, 5.f);
	sf::Vector2f position = shape3.getPosition();

	window->draw(shape3);
}

void Cvijet::animationRotation()
{
	if (clock.getElapsedTime().asMilliseconds() > 1.f) {

		if (shape3.getRotation() == 360.f)
		{
			rotation = 1;
		}
		else
		{
			shape3.setRotation(rotation++);
		}
		clock.restart();
	}
}

void Cvijet::draw()
{
	animationRotation();
	ShapeForAnimation();
	outlineAndShape();
	line();
	convexShape();
}


