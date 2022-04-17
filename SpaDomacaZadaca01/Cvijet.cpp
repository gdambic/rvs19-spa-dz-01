#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	{
		
		sf::CircleShape cvijet(65);
		cvijet.setFillColor(sf::Color(255, 255, 0));
		cvijet.setPosition(350, 350);
		cvijet.setOutlineColor(sf::Color(255, 51, 255));
		cvijet.setOutlineThickness(20);

		sf::CircleShape sunce(50);
		sunce.setRadius(50);
		sunce.setFillColor(sf::Color::Yellow);

		sf::RectangleShape stabiljka(sf::Vector2f(10, 500));
		stabiljka.setPosition(410, 400);
		stabiljka.setFillColor(sf::Color(0, 255, 0));

		sf::CircleShape triangle(30, 3);
		triangle.setFillColor(sf::Color(0, 255, 0));
		triangle.setPosition(410, 500);



		float pomak = 5;

		
			if (sunce.getPosition().x > 700)
			{
				pomak = -5;
				cvijet.setRadius(40);
				sunce.setFillColor(sf::Color(96, 96, 96));
			}
			else if (sunce.getPosition().x < 0) {
				pomak = 5;
				cvijet.setRadius(65);
				sunce.setFillColor(sf::Color::Yellow);
			}

			sunce.move(pomak, 1);

			window->draw(cvijet);
			window->draw(sunce);
			window->draw(stabiljka);
			window->draw(triangle);
			window->display();
		}
}
