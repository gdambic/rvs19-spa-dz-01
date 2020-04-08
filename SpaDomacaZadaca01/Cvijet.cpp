#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;

}

void Cvijet::draw()
{

	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color(255, 255, 0));
	shape.setOutlineThickness(30.f);
	shape.setOutlineColor(sf::Color(250, 0, 0));
	shape.setPosition(300.f, 50.f);
	sf::Vector2f position = shape.getPosition();


	sf::RectangleShape stabljika(sf::Vector2f(150.f, 10.f));
	stabljika.rotate(90.f);
	stabljika.setFillColor(sf::Color(0, 255, 0));
	stabljika.setPosition(350.f, 180.f);

	sf::ConvexShape list;
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(350.f, 250.f));
	list.setPoint(1, sf::Vector2f(385.f, 220.f));
	list.setPoint(2, sf::Vector2f(480.f, 210.f));
	list.setPoint(3, sf::Vector2f(385.f, 250.f));
	list.setFillColor(sf::Color(0, 255, 0));

	sf::CircleShape sunce(50.f);
	sunce.setFillColor(sf::Color(255, 255, 0));

	sf::Time elapsed1 = frameClock.getElapsedTime();

	if (elapsed1.asMilliseconds() >= 1000)
	{
		int velicina = 50;
		velicina += 30;
		sunce.setRadius(velicina);
		sunce.setOrigin(sunce.getRadius(), sunce.getRadius());
		sunce.setPosition(sf::Vector2f(100, 50));
		window->draw(sunce);
		if (elapsed1.asMilliseconds() >= 2000)
		{
			frameClock.restart();
		}
	}


	window->draw(shape);
	window->draw(stabljika);
	window->draw(list);
	window->draw(sunce);

}

