#include "Cvijet.h"
#include <SFML/Graphics.hpp>
//implementacija
Cvijet::Cvijet(sf::RenderWindow* s_window)
{
	window = s_window;
	
	circle.setPosition(sf::Vector2f(600.f, 325.f));
	circle.setRadius(10);
	circle.setFillColor(sf::Color::Yellow);

	
	circle2.setPosition(sf::Vector2f(580.f, 305.f));
	circle2.setRadius(30);
	circle2.setFillColor(sf::Color::Red);

	
	rect.setPosition(sf::Vector2f(610.f, 365.f));
	rect.setSize(sf::Vector2f(2, 100));
	rect.setFillColor(sf::Color::Green);
}
void Cvijet::draw() 
{
	circle.move(0.5f, 0.1f);
	circle2.move(0.5f, 0.1f);
	rect.move(0.5f, 0.1f);

	window->draw(circle2);
	window->draw(circle);
	window->draw(rect);
}

