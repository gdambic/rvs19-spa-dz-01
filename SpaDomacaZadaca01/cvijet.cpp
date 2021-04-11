#include "cvijet.h"


void cvijet::Circle()
{
	circle.setRadius(40.f);
	circle.setPointCount(100);
	circle.setPosition(100, 120);
	circle.setFillColor(sf::Color(120, 100, 200));
	circle.setOutlineThickness(30);

}

void cvijet::Line()
{
	line.setRotation(90.f);
	line.setSize(sf::Vector2f(150, 20));
	line.setFillColor(sf::Color::Green);
	line.setPosition(150, 230);
}

void cvijet::Convex()
{
	convex.setPointCount(5);
	convex.setPoint(0, sf::Vector2f(0.f, 0.f));
	convex.setPoint(1, sf::Vector2f(50.f, 10.f));
	convex.setPoint(2, sf::Vector2f(50.f, 90.f));
	convex.setPoint(3, sf::Vector2f(30.f, 100.f));
	convex.setPoint(4, sf::Vector2f(0.f, 50.f));
	convex.setFillColor(sf::Color(20, 200, 80));
	convex.setPosition(240, 265);
	convex.setRotation(90.f);
}

void cvijet::Sun()
{
	sun.setRadius(40.f);
	sun.setPointCount(100);
	sun.setPosition(400,10);
	sun.setFillColor(sf::Color::Yellow);	
}

void cvijet::draw()
{
	Circle();
	Line();
	Convex();
	Sun();

	MojProzor->draw(circle);
	MojProzor->draw(line);
	MojProzor->draw(convex);
}

void cvijet::crtaj(sf::Clock *animacija)
{
	
	sun.setPosition(100 *animacija->getElapsedTime().asSeconds(), 5);
	if (animacija->getElapsedTime().asSeconds()>3)
	{
		animacija->restart();
	}
	MojProzor->draw(sun);

}
