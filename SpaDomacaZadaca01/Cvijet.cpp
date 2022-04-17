#include "Cvijet.h"
#include "SFML\Graphics.hpp"
#include <iostream>
using namespace std;

Cvijet::Cvijet(sf::RenderWindow* window) : window(window) {


}

void Cvijet::draw() {


	sf::RectangleShape grass(sf::Vector2f(400, 50));
	grass.rotate(0);
	grass.setFillColor(sf::Color(0, 100, 0));
	grass.setPosition(0, 350);
	window->draw(grass);
	
	/*
	sf::CircleShape flower(50);
	flower.setFillColor(sf::Color(244, 164, 96));
	flower.setOutlineThickness(15);
	flower.setOutlineColor(sf::Color(255, 255, 0));
	flower.setPosition(145, 85);
	*/

	sf::RectangleShape stem(sf::Vector2f(150, 10));
	stem.rotate(90);
	stem.setFillColor(sf::Color(0, 255, 0));
	stem.setPosition(200, 200);
	window->draw(stem);

	sf::ConvexShape flower1;
	flower1.setFillColor(sf::Color(255, 0, 0));
	flower1.setPointCount(4);
	flower1.setPoint(0, sf::Vector2f(195.f, 200.f));
	flower1.setPoint(1, sf::Vector2f(220.f, 130.f));
	flower1.setPoint(2, sf::Vector2f(240.f, 170.f));
	flower1.setPoint(3, sf::Vector2f(150.f, 185.f));
	window->draw(flower1);

	sf::ConvexShape flower2;
	flower2.setFillColor(sf::Color(255, 0, 0));
	flower2.setPointCount(4);
	flower2.setPoint(0, sf::Vector2f(195.f, 200.f));
	flower2.setPoint(1, sf::Vector2f(170.f, 130.f));
	flower2.setPoint(2, sf::Vector2f(140.f, 170.f));
	flower2.setPoint(3, sf::Vector2f(230.f, 185.f));
	window->draw(flower2);

	sf::ConvexShape flower3;
	flower3.setFillColor(sf::Color(255, 0, 0));
	flower3.setPointCount(4);
	flower3.setPoint(0, sf::Vector2f(195.f, 200.f));
	flower3.setPoint(1, sf::Vector2f(220.f, 150.f));
	flower3.setPoint(2, sf::Vector2f(195.f, 100.f));
	flower3.setPoint(3, sf::Vector2f(170.f, 150.f));
	window->draw(flower3);

	sf::CircleShape sun(30);
	sun.setFillColor(sf::Color(255, 255, 0));
	sun.setPosition(0, 50);
	window->draw(sun);
		
	sf::ConvexShape convex;
	convex.setFillColor(sf::Color(0, 255, 0));
	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(200.f, 250.f));
	convex.setPoint(1, sf::Vector2f(250.f, 260.f));
	convex.setPoint(2, sf::Vector2f(290.f, 290.f));
	convex.setPoint(3, sf::Vector2f(250.f, 290.f));
	window->draw(convex);
}