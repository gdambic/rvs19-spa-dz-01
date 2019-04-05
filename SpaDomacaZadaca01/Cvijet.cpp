#include "Cvijet.h"
#include <iostream>

Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::RectangleShape stabiljka(sf::Vector2f(10.0f, 150.0f));
	stabiljka.setFillColor(sf::Color::Green);
	stabiljka.setPosition(200.0f, 450.0f);

	sf::ConvexShape list;
	list.setPointCount(4);
	list.setFillColor(sf::Color::Green);
	list.setPoint(0, sf::Vector2f(200.0f, 500.0f));
	list.setPoint(1, sf::Vector2f(250.0f, 475.0f));
	list.setPoint(2, sf::Vector2f(300.0f, 500.0f));
	list.setPoint(3, sf::Vector2f(250.0f, 525.0f));

	sf::CircleShape tucak(100.0f);
	tucak.setFillColor(sf::Color::Yellow);
	tucak.setPosition(200.0f, 300.0f);

	sf::CircleShape latice(75.0f);
	latice.setFillColor(sf::Color::Red);
	latice.setPosition(125.0f, 300.0f);
	latice.setOutlineThickness(30.0f);
	latice.setOutlineColor(sf::Color::Yellow);	

	float radiusSunca = 30.0f;
	sf::CircleShape sunce(radiusSunca);
	sunce.setFillColor(sf::Color::Yellow);
	sunce.setPosition(50.0f, 50.0f);
	
	sf::Time elapsed = frameClock.restart();

	ukupnoVrijeme += elapsed.asSeconds();

		if (ukupnoVrijeme <= 3) {
			sunce.setRadius(ukupnoVrijeme + radiusSunca);
		}
		else if (ukupnoVrijeme > 3 && ukupnoVrijeme < 6) {
			sunce.setRadius(radiusSunca - ukupnoVrijeme + 7);
		}
		else if (ukupnoVrijeme >= 6) {
			ukupnoVrijeme = 0;
		}
		
		std::cout << ukupnoVrijeme << std::endl;
	
	window->draw(stabiljka);
	window->draw(list);
	window->draw(latice);
	window->draw(sunce);
}