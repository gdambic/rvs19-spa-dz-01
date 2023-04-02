#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::RectangleShape stab(sf::Vector2f(10.f, 200.f));
	stab.setFillColor(sf::Color(50, 205, 50, 255));
	stab.setPosition(145.f, 250.f);
	//stemaxis.rotate(90.f);
	window->draw(stab);

	sf::ConvexShape list;
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(150.f, 400.f));
	list.setPoint(1, sf::Vector2f(350.f, 300.f));
	list.setPoint(2, sf::Vector2f(300.f, 200.f));
	list.setPoint(3, sf::Vector2f(300.f, 200.f));
	list.setFillColor(sf::Color(50, 205, 50, 255));
	window->draw(list);

	sf::CircleShape krug(50.f);
	krug.setFillColor(sf::Color::Yellow);
	krug.setOutlineColor(sf::Color::Red);
	krug.setOutlineThickness(50.f);
	krug.setPosition(100.f, 150.f);
	window->draw(krug);

}
