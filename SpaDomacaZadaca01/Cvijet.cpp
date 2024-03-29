#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	//cvijet
	sf::CircleShape shape(50);
	shape.setFillColor(sf::Color(255, 254, 145));
	shape.setOutlineThickness(10);
	sf::Vector2f shapePosition(305, 250);
	shape.setOutlineColor(sf::Color(237, 28, 36));
	shape.setPosition(shapePosition);
	window->draw(shape);

	//stabljika
	sf::RectangleShape line(sf::Vector2f(150, 5));
	line.rotate(90);
	line.setPosition(sf::Vector2f(355, 350));
	line.setFillColor(sf::Color(80, 207, 94));
	window->draw(line);

	//list
	sf::ConvexShape list;
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(200, 350));
	list.setPoint(1, sf::Vector2f(200, 300));
	list.setPoint(2, sf::Vector2f(250, 300));
	list.setPoint(3, sf::Vector2f(350, 450));
	list.setFillColor(sf::Color(80, 207, 94));
	window->draw(list);

	animacija();
}

void Cvijet::animacija()
{
	sf::CircleShape myCircle(50);
	sf::Vector2f myCirclePosition(0, 0);
	myCircle.setPosition(myCirclePosition);
	myCircle.setFillColor(sf::Color(207, 190, 54));


	if (frameClock.getElapsedTime().asMilliseconds() > 4000)
	{

		myCircle.setPosition(0.f - 200.f * (frameClock.getElapsedTime().asMilliseconds() / 1000.f), 30.f);

		if (frameClock.getElapsedTime().asMilliseconds() >= 2000)
		{
			frameClock.restart();
		}
	}
	else 
	{
		myCircle.setPosition(0.f + 200.f * (frameClock.getElapsedTime().asMilliseconds() / 1000.f), 30.f);
	}
	
	window->draw(myCircle);
}
