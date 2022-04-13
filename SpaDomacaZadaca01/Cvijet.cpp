#include <iostream>
#include "Cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{

	CircleShape sun(40.f);
	sun.setPosition(20.f, 50.f);
	sun.setFillColor(Color(255, 255, 0));
	sun.setOutlineThickness(5);
	sun.setOutlineColor(Color(102, 102, 0));

	if (clock.getElapsedTime().asMilliseconds() > 2000)
	{
		sun.setRadius(40.f - 10.f * ((clock.getElapsedTime().asMilliseconds() - 2000) / 2000.f));
		
		if (clock.getElapsedTime().asMilliseconds() >= 4000)
		{
			clock.restart();
		}
	}
	else
	{
		sun.setRadius(40.f - 10.f + 10.f * (clock.getElapsedTime().asMilliseconds() / 2000.f));
	}
	window->draw(sun);

	CircleShape cvijet(60);
	cvijet.move(400, 150);
	cvijet.setFillColor(sf::Color::Green);

	cvijet.setOutlineThickness(30);
	cvijet.setOutlineColor(Color::Yellow);
	window->draw(cvijet);

	RectangleShape stabljika(Vector2f(150, 10));
	stabljika.setFillColor(Color::Green);
	stabljika.move(465, 300);
	stabljika.rotate(90);
	window->draw(stabljika);
	ConvexShape(list);
	list.setPointCount(4);
	list.setPoint(0, Vector2f(180, 20));
	list.setPoint(1, Vector2f(250, 90));
	list.setPoint(2, Vector2f(170, 90));
	list.setPoint(3, Vector2f(110, 50));
	list.setFillColor(Color::Green);
	list.move(205, 305);
	window->draw(list);

	ConvexShape(list_2);
	list_2.setPointCount(3);
	list_2.setPoint(0, Vector2f(260, 0));
	list_2.setPoint(1, Vector2f(310, 90));
	list_2.setPoint(2, Vector2f(370, 50));
	list_2.setFillColor(Color::Cyan);
	list_2.move(205, 305);
	window->draw(list_2);

}