#include "Cvijet.h"



void cvijet::napravi_shape()
{
	shape.setRadius(60.f);
	shape.setPosition(400.f, 250.f);
	shape.setOrigin(shape.getRadius(), shape.getRadius());
	shape.setFillColor(sf::Color(255, 255, 0));
	shape.setOutlineThickness(50.f);
	shape.setOutlineColor(sf::Color(255, 0, 0));

	
}

void cvijet::napravi_liniju()
{
	line.setSize(sf::Vector2f(150.f, 20.f));
	line.setPosition(410.f, 360.f);
	line.setFillColor(sf::Color(100, 250, 50));
	line.setRotation(90.f);
	
}

void cvijet::napravi_convex()
{
	

	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(0.f, 0.f));
	convex.setPoint(1, sf::Vector2f(40.f, -20.f));
	convex.setPoint(2, sf::Vector2f(80.f, 0.f));
	convex.setPoint(3, sf::Vector2f(40.f, 20.f));
	convex.setPosition(410.f, 435.f);
	convex.setFillColor(sf::Color(100, 250, 50));

	
}

void cvijet::napravi_sunce()
{
	sunce.setFillColor(sf::Color(255, 255, 0));
	sunce.setRadius(10.f);
}




void cvijet::draw()
{
	napravi_shape();
	napravi_liniju();
	napravi_convex();
	napravi_sunce();

	
	m_window->draw(shape);
	m_window->draw(line);
	m_window->draw(convex);

}

void cvijet::update(sf::Clock *vrijeme) 
{
	
	sunce.setPosition(50, 50);
	sunce.setRadius(vrijeme->getElapsedTime().asSeconds()*sunce.getRadius());

	if (vrijeme->getElapsedTime().asSeconds() > 3) {

		vrijeme->restart();
		
		sunce.setRadius(vrijeme->getElapsedTime().asSeconds()*sunce.getRadius());

	}
	m_window->draw(sunce);

}