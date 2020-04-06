#include "Cvijet.h"
#include <iostream>
Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw   (sf::RenderWindow& window)
{

	
	sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
	line.rotate(90.f);
	line.setFillColor(sf::Color(5, 250, 0));
	line.setPosition(sf::Vector2f(190, 290));
	line.setSize(sf::Vector2f(300, 6));


	sf::CircleShape shape(90.f);
	shape.setFillColor(sf::Color(255,250, 0));
	shape.setOutlineThickness(35.f);
	shape.setOutlineColor(sf::Color(250, 0, 0));
	shape.setPosition(sf::Vector2f(100, 100));

	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(115.f, 440.f));
	convex.setPoint(1, sf::Vector2f(170.f, 400.f));
	convex.setPoint(2, sf::Vector2f(330.f, 360.f));
	convex.setPoint(3, sf::Vector2f(188.f, 450.f));
	convex.setScale(1.6f, 1.f);
	convex.setFillColor(sf::Color(0, 250, 0));



	sf::CircleShape sunce(40.f);
	sunce.setFillColor(sf::Color(255, 250, 0));
	sunce.setPosition(sf::Vector2f(10, 10));



	if (clock.getElapsedTime().asMilliseconds() > 2000) {

		sunce.setRadius(50.f - 10.f * ((clock.getElapsedTime().asMilliseconds()-2000) / 2000.f));
	
		if (clock.getElapsedTime().asMilliseconds() >= 4000) {
			clock.restart();
		}
	}
	else
		 {
			sunce.setRadius(40.f + 10.f * (clock.getElapsedTime().asMilliseconds() / 2000.f));
		 }


	//std::cout << sunce.getRadius() << std::endl;
	//provjera
	
	window.draw(sunce);
	window.draw(line);
	window.draw(shape);
	window.draw(convex);
}
