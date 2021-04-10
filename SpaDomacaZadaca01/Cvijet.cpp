#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

Cvijet::~Cvijet()
{
	Cvijet::~Cvijet();
}

void Cvijet::draw()
{
	if (shapes.size() == 0)
	{
		initShapes();
	}
	std::vector<sf::Shape*>::iterator it = shapes.begin();
	sf::Shape* first = *it;

	first->setOutlineThickness((int)frameClock.getElapsedTime().asMilliseconds() / 150 % 5 * 10);
	for (; it != shapes.end(); ++it)
	{
		window->draw(**it);
	}

}

void Cvijet::initShapes()
{
	int posX = 200;
	int posY = 200;

	//Circle
	sf::CircleShape* flower = new sf::CircleShape(100);
	flower->setFillColor(sf::Color::Red);
	flower->setOutlineThickness(2);
	flower->setOutlineColor(sf::Color::Yellow);
	flower->setPosition(posX, posY);
	shapes.push_back(flower);

	posX += flower->getRadius();
	posY += flower->getRadius() * 2 + flower->getOutlineThickness();

	//Stem
	sf::RectangleShape* stem = new sf::RectangleShape(sf::Vector2f(250, 10));
	stem->setFillColor(sf::Color::Green);
	stem->rotate(90);
	stem->setPosition(posX, posY);
	shapes.push_back(stem);
	posY += 125;

	//Leaf
	sf::ConvexShape* leaf = new sf::ConvexShape();
	leaf->setPointCount(5);
	leaf->setFillColor(sf::Color::Green);
	leaf->setPoint(0, sf::Vector2f(posX, posY));
	leaf->setPoint(1, sf::Vector2f(posX + 100, posY -50));
	leaf->setPoint(2, sf::Vector2f(posX + 100 + 250, posY - 100 - 50));
	leaf->setPoint(3, sf::Vector2f(posX + 100, posY + 50));
	leaf->setPoint(4, sf::Vector2f(posX + 110, posY + 50));
	shapes.push_back(leaf);

	//Leaf 2
	sf::ConvexShape* leaf2 = new sf::ConvexShape();
	leaf2->setPointCount(5);
	leaf2->setFillColor(sf::Color::Green);
	leaf2->setPoint(0, sf::Vector2f(posX, posY));
	leaf2->setPoint(1, sf::Vector2f(posX + 100, posY - 50));
	leaf2->setPoint(2, sf::Vector2f(posX + 100 + 450, posY - 100 - 50));
	leaf2->setPoint(3, sf::Vector2f(posX + 100, posY + 50));
	leaf2->setPoint(4, sf::Vector2f(posX + 100, posY + 50));
	shapes.push_back(leaf2);

}
