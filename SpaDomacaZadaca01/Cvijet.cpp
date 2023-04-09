#include "Cvijet.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	clock.restart();
	raste = true;
	radijus = 30;
}

void Cvijet::draw()
{
	double deltaTime = clock.restart().asSeconds();

	sf::CircleShape sunce;

	sunce.setRadius(radijus);
	sunce.setFillColor(sf::Color(255, 255, 0));
	sunce.setPointCount(100);

	if (raste)
	{
		radijus += 25 * deltaTime;
		if (radijus >= 60)
		{
			raste = false; 
		}
	}
	else
	{
		radijus -= 25 * deltaTime;
		if (radijus <= 30)
		{
			raste = true;
		}
	}

	sunce.setRadius(radijus); 
	sunce.setOrigin(radijus, radijus);
	sunce.setPosition(100 + radijus, 125 + radijus);

	
	window->draw(sunce);

	


	sf::RectangleShape line2(sf::Vector2f(75, 3));
	line2.rotate(340);
	line2.setFillColor(sf::Color(255, 255, 0));
	line2.setOutlineColor(sf::Color(255, 255, 0));
	line2.setOutlineThickness(2);
	line2.setPosition(250, 150);
	window->draw(line2);

	sf::RectangleShape line3(sf::Vector2f(75, 3));
	line3.rotate(20);
	line3.setFillColor(sf::Color(255, 255, 0));
	line3.setOutlineColor(sf::Color(255, 255, 0));
	line3.setOutlineThickness(2);
	line3.setPosition(250, 190);
	window->draw(line3);

	sf::RectangleShape line4(sf::Vector2f(75, 3));
	line4.rotate(60);
	line4.setFillColor(sf::Color(255, 255, 0));
	line4.setOutlineColor(sf::Color(255, 255, 0));
	line4.setOutlineThickness(2);
	line4.setPosition(240, 230);
	window->draw(line4);

	sf::CircleShape circle(200);
	circle.setFillColor(sf::Color(128, 0, 128));
	circle.setRadius(50);
	circle.setPointCount(100);
	circle.setPosition(window->getSize().x / 2 - circle.getRadius(), window->getSize().y / 2 - circle.getRadius());

	sf::RectangleShape line(sf::Vector2f(200, 5));
	line.rotate(90);
	line.setFillColor(sf::Color(36, 143, 36));
	line.setOutlineColor(sf::Color(20, 82, 20));
	line.setOutlineThickness(3);
	line.setPosition(window->getSize().x / 2, window->getSize().y / 2 + circle.getRadius() + 7);
	window->draw(line);

	circle.setOutlineThickness(8);
	circle.setOutlineColor(sf::Color(255, 192, 203));
	window->draw(circle);

	sf::RectangleShape rectangle(sf::Vector2f(800, 100));
	rectangle.setFillColor(sf::Color(36, 143, 36));
	rectangle.setPosition(0, 550);
	window->draw(rectangle);

	sf::CircleShape triangle(12, 3);
	triangle.rotate(60);
	triangle.setFillColor(sf::Color(36, 143, 36));
	triangle.setPosition(window->getSize().x / 2 + 7, (window->getSize().y / 2) + 200);
	window->draw(triangle);

	sf::CircleShape trianglee(12, 3);
	trianglee.rotate(60);
	trianglee.setFillColor(sf::Color(36, 143, 36));
	trianglee.setPosition(window->getSize().x / 2 + 7, (window->getSize().y / 2) + 100);
	window->draw(trianglee);

	sf::CircleShape triangleee(12, 3);
	triangleee.rotate(170);
	triangleee.setFillColor(sf::Color(36, 143, 36));
	triangleee.setPosition(window->getSize().x / 2 + 5, (window->getSize().y / 2) + 170);
	window->draw(triangleee);

	sf::CircleShape trokut1(20, 3);
	trokut1.rotate(0);
	trokut1.setFillColor(sf::Color(36, 143, 36));
	trokut1.setPosition(25, 520);
	window->draw(trokut1);

	sf::CircleShape trokut2(20, 3);
	trokut2.rotate(0);
	trokut2.setFillColor(sf::Color(36, 143, 36));
	trokut2.setPosition(125, 520);
	window->draw(trokut2);

	sf::CircleShape trokut3(20, 3);
	trokut3.rotate(0);
	trokut3.setFillColor(sf::Color(36, 143, 36));
	trokut3.setPosition(275, 520);
	window->draw(trokut3);

	sf::CircleShape trokut4(20, 3);
	trokut4.rotate(0);
	trokut4.setFillColor(sf::Color(36, 143, 36));
	trokut4.setPosition(450, 520);
	window->draw(trokut4);

	sf::CircleShape trokut5(20, 3);
	trokut5.rotate(0);
	trokut5.setFillColor(sf::Color(36, 143, 36));
	trokut5.setPosition(600, 520);
	window->draw(trokut5);

	
}


