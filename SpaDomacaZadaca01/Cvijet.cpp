#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
using namespace std;



Cvijet::Cvijet(sf::RenderWindow *window)
{
	window->clear();
	sf::RectangleShape zemlja(sf::Vector2f(800, 600));
	zemlja.setFillColor(sf::Color(0, 255, 0));
	window->draw(zemlja);

	sf::RectangleShape nebo(sf::Vector2f(800, 500));
	nebo.setFillColor(sf::Color(135, 206, 250));
	window->draw(nebo);
	
	sf::CircleShape sunce(65,10);
	sunce.setFillColor(sf::Color(255,255,0));
	window->draw(sunce);
	sf::CircleShape cvijet(60);
	cvijet.setPosition(400, 200);
	cvijet.setFillColor(sf::Color(255, 255, 0));
	cvijet.setOutlineThickness(30);
	cvijet.setOutlineColor(sf::Color(255, 140, 0));
	window->draw(cvijet);
	sf::RectangleShape line(sf::Vector2f(200, 10));
	line.rotate(90);
	line.setFillColor(sf::Color(0, 255, 0));
	line.setPosition(470, 350);
	window->draw(line);
	sf::CircleShape list(30.f, 3);
	list.setFillColor(sf::Color(0, 255, 0));
	list.setPosition(515, 370);
	list.setRotation(90);
	window->draw(list);
	sf::RectangleShape cloud(sf::Vector2f(150, 50));
	cloud.setFillColor(sf::Color(0, 191, 255));
	cloud.setPosition(500,20 );
	window->draw(cloud);
	
	window->display();
}

void Cvijet::draw()
{
	
}



