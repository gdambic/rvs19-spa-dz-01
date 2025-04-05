#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	clock.restart();
}

void Cvijet::draw()
{

	sf::CircleShape shape(20);
	shape.setFillColor(sf::Color(rand() % 256,rand() %  255, rand() % 256));
	shape.setPosition(20, 20);

	sf::CircleShape krug2(120);
	krug2.setFillColor(sf::Color(255, 255, 0));
	krug2.setPosition(100, 100);
	krug2.setOutlineThickness(35);
	krug2.setOutlineColor(sf::Color(rand() % 255, 0, 0));

	sf::RectangleShape line(sf::Vector2f(250, 10));
	line.setFillColor(sf::Color(0, 255, 0));
	line.setPosition(225, 375);
	line.rotate(90);

	sf::ConvexShape convex;
	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(120, 140));
	convex.setPoint(1, sf::Vector2f(150, 10));
	convex.setPoint(2, sf::Vector2f(120, 90));
	convex.setPoint(3, sf::Vector2f(0, 50));
	convex.setFillColor(sf::Color(0, 250, 0));
	convex.setPosition(365, 370);
	convex.rotate(90);

	sf::RectangleShape rectangle(sf::Vector2f(150, 50));
	rectangle.setSize(sf::Vector2f(135, 100));
	rectangle.setFillColor(sf::Color(255, 255, 255));
	rectangle.setPosition(100, 450);


	sf::CircleShape shape4(20);
	shape4.setFillColor(sf::Color(rand() % 256, rand() % 255, rand() % 256));
	shape4.setPosition(110, 550);

	sf::CircleShape shape5(20);
	shape5.setFillColor(sf::Color(rand() % 256, rand() % 255, rand() % 256));
	shape5.setPosition(180, 550);


	float speed2 = 90;
	sf::Time deltaTime2 = clock.getElapsedTime();
	float movement2 = speed2 * deltaTime2.asSeconds();
	rectangle.move(movement2, 0);

	
	float speed = 90;
	sf::Time deltaTime = clock.getElapsedTime();
	float movement = speed * deltaTime.asSeconds();
	convex.move(movement, 0);
	shape4.move(movement, 0);
	shape5.move(movement, 0);

	window->draw(shape);
	window->draw(krug2);
	window->draw(line);
	window->draw(convex);
	window->draw(rectangle);
	window->draw(shape4);
	window->draw(shape5);
	window->display();
}
