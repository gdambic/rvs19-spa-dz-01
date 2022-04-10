#include "Cvijet.h"

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
//using namespace sf;

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::RectangleShape pozadina(sf::Vector2f(800.f, 600.f));
	pozadina.setFillColor(sf::Color(224, 244, 255));
	

	sf::CircleShape sunce(70.f);
	sunce.setPosition(20.f, 20.f);
	sunce.setFillColor(sf::Color(242, 245, 66));
	sunce.setOutlineThickness(10.f);
	sunce.setOutlineColor(sf::Color(254, 255, 257));


	sf::Time elapsed2 = clock.getElapsedTime();

	if (clock.getElapsedTime().asMilliseconds() > 4000)
	{
		sunce.setPosition(140.f - 250.f * ((clock.getElapsedTime().asMilliseconds() - 1000) / 1000.f), 30.f);
		
		if (clock.getElapsedTime().asMilliseconds() >= 5000)
		{
			clock.restart();
		}
	}
	else
	{

		sunce.setPosition(220.f + 250.f * (clock.getElapsedTime().asMilliseconds() / 1000.f), 30.f);

	}

	sf::CircleShape cvijet(40.f);
	cvijet.setPosition(450.f, 340.f);
	cvijet.setFillColor(sf::Color(237, 36, 207));
	cvijet.setOutlineThickness(5.f);
	cvijet.setOutlineColor(sf::Color(166, 162, 252));

	sf::CircleShape cvijet1(30.f);
	cvijet1.setPosition(420.f, 340.f);
	cvijet1.setFillColor(sf::Color(239, 162, 252));
	cvijet1.setOutlineThickness(5.f);
	cvijet1.setOutlineColor(sf::Color(166, 162, 252));
	
	sf::CircleShape cvijet2(30.f);
	cvijet2.setPosition(450.f, 310.f);
	cvijet2.setFillColor(sf::Color(239, 162, 252));
	cvijet2.setOutlineThickness(5.f);
	cvijet2.setOutlineColor(sf::Color(166, 162, 252));

	sf::CircleShape cvijet3(30.f);
	cvijet3.setPosition(490.f, 320.f);
	cvijet3.setFillColor(sf::Color(239, 162, 252));
	cvijet3.setOutlineThickness(5.f);
	cvijet3.setOutlineColor(sf::Color(166, 162, 252));

	sf::CircleShape cvijet4(30.f);
	cvijet4.setPosition(490.f, 370.f);
	cvijet4.setFillColor(sf::Color(239, 162, 252));
	cvijet4.setOutlineThickness(5.f);
	cvijet4.setOutlineColor(sf::Color(166, 162, 252));

	sf::CircleShape cvijet5(30.f);
	cvijet5.setPosition(440.f, 385.f);
	cvijet5.setFillColor(sf::Color(239, 162, 252));
	cvijet5.setOutlineThickness(5.f);
	cvijet5.setOutlineColor(sf::Color(166, 162, 252));



	sf::ConvexShape convex;
	convex.setPointCount(4);

	
	convex.setPoint(0, sf::Vector2f(350.f,440.f));
	convex.setPoint(1, sf::Vector2f(430.f, 350.f));
	convex.setPoint(2, sf::Vector2f(650.f, 380.f));
	convex.setPoint(3, sf::Vector2f(430.f, 350.f));
	convex.setFillColor(sf::Color::Green);

	window->draw(pozadina);
	window->draw(sunce);
	window->draw(convex);
	window->draw(cvijet1);
	window->draw(cvijet2);
	window->draw(cvijet3);
	window->draw(cvijet4);
	window->draw(cvijet5);
	window->draw(cvijet);






}