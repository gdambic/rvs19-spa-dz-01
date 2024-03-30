#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;

	auto size = sf::Vector2f(window->getSize().x, window->getSize().y);

	stem = sf::RectangleShape(sf::Vector2f(10, 470));
	stem.setPosition(size.x / 2 - 10.0 / 2, 70);
	stem.setFillColor(sf::Color::Green);

	outerFlower = sf::CircleShape(100);
	
	outerFlower.setFillColor(sf::Color::Red);

	innerFlower = sf::CircleShape(80);
	innerFlower.setFillColor(sf::Color::Yellow);

	leaf.setPosition(stem.getPosition().x + 5, 340);
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(0, 0));
	leaf.setPoint(1, sf::Vector2f(80, -45));
	leaf.setPoint(2, sf::Vector2f(80 + 100, -45 - 20));
	leaf.setPoint(3, sf::Vector2f(0, 100));
	leaf.setFillColor(sf::Color::Green);
}

void Cvijet::draw()
{
	t += clock.restart().asSeconds();

	outerFlower.setPosition(window->getSize().x / 2 - 100, 40 + sin(t) * 35);
	innerFlower.setPosition(outerFlower.getPosition().x + 20, outerFlower.getPosition().y + 20);

	window->draw(stem);
	window->draw(outerFlower);
	window->draw(innerFlower);
	window->draw(leaf);
}
