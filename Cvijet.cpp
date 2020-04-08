#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	stabiljka = sf::RectangleShape(sf::Vector2f(25.f, 400.f));
	stabiljka.setFillColor(sf::Color().Green);
	stabiljka.setPosition(sf::Vector2f(400.f, 300.f));
	circ1 = sf::CircleShape(40.f,8);
	circ1.setOrigin(sf::Vector2f(40.f, 40.f));
	circ1.setPosition(sf::Vector2f(412.f, 320.f));
	circ1.setFillColor(sf::Color().Yellow);
	circ2 = sf::CircleShape(70.f,10);
	circ2.setOrigin(sf::Vector2f(70.f, 70.f));
	circ2.setPosition(sf::Vector2f(412.f, 320.f));
	circ2.setFillColor(sf::Color().White);
}

void Cvijet::draw()
{
	window->draw(stabiljka);
	window->draw(circ2);
	window->draw(circ1);
	circ2.rotate(1.f);
	circ1.rotate(-1.f);
}
