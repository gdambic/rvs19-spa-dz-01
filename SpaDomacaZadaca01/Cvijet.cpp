#include "Cvijet.h"
#include <SFML/Graphics.hpp>

void Cvijet::draw()
{

	window->clear(sf::Color::Blue);

	sf::CircleShape sunce(70.f);
	sunce.setFillColor(sf::Color::Yellow);
	sunce.setPosition(0, 0);
	sunce.setOutlineThickness(15.f);
	sunce.setOutlineColor(sf::Color(247,129,11));
	window->draw(sunce);




	sf::CircleShape krug(50.f);
	krug.setFillColor(sf::Color::Yellow);
	krug.setPosition(200, 200);
	krug.setOutlineThickness(15.f);
	krug.setOutlineColor(sf::Color::Magenta);
	window->draw(krug);

	sf::RectangleShape stabiljka(sf::Vector2f(120.f, 5.f));
	stabiljka.setPosition(250, 300);
	stabiljka.setFillColor(sf::Color::Green);
	stabiljka.rotate(90.f);
	window->draw(stabiljka);

	sf::ConvexShape list;
	list.setPointCount(5);
	list.setFillColor(sf::Color::Green);
	list.setPosition(350, 320);
	list.setPoint(0, sf::Vector2f(0.f, 0.f));
	list.setPoint(1, sf::Vector2f(30.f, 10.f));
	list.setPoint(2, sf::Vector2f(70.f, 90.f));
	list.setPoint(3, sf::Vector2f(30.f, 100.f));
	list.setPoint(4, sf::Vector2f(0.f, 50.f));
	list.rotate(100.f);
	window->draw(list);



}


Cvijet::Cvijet(sf::RenderWindow * window)
{
	this->window = window;
}
