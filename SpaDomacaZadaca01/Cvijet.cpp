#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{

	//pozadina dan 
	sf::Texture background;
	background.loadFromFile("slikice/dan.jpg");
	sf::Sprite bk(background);
	//pozadina noc
	sf::Texture background2;
	background2.loadFromFile("slikice/noc.jpg");
	sf::Sprite bk2(background2);

	//Background
	if (frameClock.getElapsedTime().asMilliseconds() <= 1950)
	{
		background2.loadFromFile("slikice/dan.jpg");
		bk.setTexture(background);
		window->draw(bk);
	}
	if (frameClock.getElapsedTime().asMilliseconds() > 1950)
	{
		background2.loadFromFile("slikice/noc.jpg");
		bk2.setTexture(background2);
		window->draw(bk2);
	}
	//tucak i cvijet
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
	sf::ConvexShape conve;
	conve.setPointCount(4);
	conve.setPoint(0, sf::Vector2f(200, 350));
	conve.setPoint(1, sf::Vector2f(200, 300));
	conve.setPoint(2, sf::Vector2f(250, 300));
	conve.setPoint(3, sf::Vector2f(350, 450));
	conve.setFillColor(sf::Color(80, 207, 94));
	window->draw(conve);

	animacija();
}

void Cvijet::animacija()
{
	sf::CircleShape myCircle(20);
	sf::Vector2f myCirclePosition(0, 0);
	myCircle.setPosition(myCirclePosition);
	myCircle.setFillColor(sf::Color(207, 190, 54));

	//tucak i cvijet
	sf::CircleShape shape(50);
	shape.setFillColor(sf::Color(255, 254, 145));
	shape.setOutlineThickness(10);
	sf::Vector2f shapePosition(305, 250);
	shape.setOutlineColor(sf::Color(237, 28, 36));
	shape.setPosition(shapePosition);

		//Cvijet
		if (frameClock.getElapsedTime().asMilliseconds() >= 2000)
		{
			shape.setOutlineColor(sf::Color(237, 28, 36));
			shape.setFillColor(sf::Color(237, 28, 36));
		}

		//CSunce/mjesec
		if (frameClock.getElapsedTime().asMilliseconds() >= 1950)
		{
			myCircle.setFillColor(sf::Color(255, 255, 255));
		}

		


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
	window->draw(shape);
}
