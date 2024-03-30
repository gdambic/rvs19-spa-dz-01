#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	int windowWidth = window->getSize().x;
	int windowHeight = window->getSize().y;
	float cvijetY = windowHeight * 0.52;
	float cvijetX = windowWidth * 0.50;

	sf::CircleShape shape;
	shape.setRadius(60.f);
	shape.setFillColor(sf::Color(252, 227, 3));
	shape.setOutlineThickness(60.f);
	shape.setOutlineColor(sf::Color(73, 31, 110));
	shape.setPosition(cvijetX, cvijetY);
	
	sf::RectangleShape line;
	line.setSize(sf::Vector2f(200.f, 5.f));
	line.rotate(90.f);
	line.setPosition(cvijetX + shape.getRadius(), cvijetY + 2*shape.getRadius() + 60.f);
	line.setFillColor(sf::Color(32, 125, 14));
	
	sf::ConvexShape leaf;
	float posLeaf = line.getPosition().y + line.getPosition().y / 5;
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(line.getPosition().x, posLeaf));
	leaf.setPoint(1, sf::Vector2f(line.getPosition().x + 100, line.getPosition().y + 100.f));
	leaf.setPoint(2, sf::Vector2f(line.getPosition().x + 200.f, line.getPosition().y));
	leaf.setPoint(3, sf::Vector2f(line.getPosition().x + 50.f, line.getPosition().y + 50));
	leaf.setFillColor(sf::Color(32, 125, 14));

	window->draw(shape);
	window->draw(line);
	window->draw(leaf);
	
	
}
