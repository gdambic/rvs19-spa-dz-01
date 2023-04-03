#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::RectangleShape peteljka(sf::Vector2f(10.f, 200.f));
	peteljka.setFillColor(sf::Color::Green);
	peteljka.setPosition(145.f, 250.f);
	window->draw(peteljka);

	sf::ConvexShape list;
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(150.f, 400.f));
	list.setPoint(1, sf::Vector2f(350.f, 300.f));
	list.setPoint(2, sf::Vector2f(300.f, 200.f));
	list.setPoint(3, sf::Vector2f(300.f, 200.f));
	list.setFillColor(sf::Color::Green);
	window->draw(list);

	sf::CircleShape krug(90.f);
	krug.setFillColor(sf::Color::Yellow);
	krug.setOutlineThickness(35.f);
	krug.setOutlineColor(sf::Color::Red);
	krug.setPosition(50.f, 50.f);
	window->draw(krug);


	sf::CircleShape sunce(20.f);
	sunce.setFillColor(sf::Color::Yellow);
	sunce.setPosition(10.f, 10.f);
	window->draw(sunce);


}
