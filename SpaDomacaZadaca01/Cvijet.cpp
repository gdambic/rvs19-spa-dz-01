#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow * window)
{
	this->window = window;
}

Cvijet::~Cvijet()
{
	for (std::vector<sf::Shape*>::iterator i = shapes.begin(); i != shapes.end(); ++i) {
		delete *i;
	}
}

void Cvijet::draw()
{
	if (shapes.size() == 0) {
		init_shapes();
	}
	std::vector<sf::Shape*>::iterator it = shapes.begin();
	sf::Shape* first = *it;

	first->setOutlineThickness((int)frameClock.getElapsedTime().asMilliseconds()/100 % 10 * 10);
	for (;it!=shapes.end(); ++it)
	{				
		window->draw(**it);
	}
}

void Cvijet::init_shapes()
{
	int pos_x = 200;
	int pos_y = 200;
	sf::CircleShape* flower = new sf::CircleShape(100);
	flower->setFillColor(sf::Color(255, 255, 0));
	flower->setOutlineThickness(40);
	flower->setOutlineColor(sf::Color(255, 0, 0));
	flower->setPosition(pos_x, pos_x);
	shapes.push_back(flower);

	pos_x += flower->getRadius();
	pos_y += flower->getRadius() * 2 + flower->getOutlineThickness();
	sf::RectangleShape* stem = new sf::RectangleShape(sf::Vector2f(250, 10));
	stem->setFillColor(sf::Color(0, 255, 0));
	stem->rotate(90);
	stem->setPosition(pos_x, pos_y);
	shapes.push_back(stem);

	pos_y += 125;
	sf::ConvexShape* leaf = new sf::ConvexShape();
	leaf->setPointCount(4);
	leaf->setFillColor(sf::Color(0, 255, 0));
	leaf->setPoint(0, sf::Vector2f(pos_x, pos_y));
	leaf->setPoint(1, sf::Vector2f(pos_x + 100, pos_y - 50));
	leaf->setPoint(2, sf::Vector2f(pos_x + 100 + 250, pos_y - 100 - 50));
	leaf->setPoint(3, sf::Vector2f(pos_x + 100, pos_y + 50));
	shapes.push_back(leaf);

}

