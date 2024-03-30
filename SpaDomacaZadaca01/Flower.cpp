#include "Flower.h"

Flower::Flower(RenderWindow* Window)
{
	this-> Window = Window;
}

void Flower::draw()
{
	sf::CircleShape flowerHead(50.f);
	flowerHead.setPosition(Vector2f(350.f, 250.f));
	flowerHead.setOutlineThickness(10.f);
	flowerHead.setOutlineColor(Color::Cyan);
	flowerHead.setFillColor(Color::Magenta);
	Window->draw(flowerHead);

	sf::RectangleShape stem(sf::Vector2f(150.f, 5.f));
	stem.setPosition(Vector2f(403.f, 360.f));
	stem.setFillColor(Color::Green);
	stem.rotate(90.f);
	Window->draw(stem);

	sf::ConvexShape leaf;
	leaf.setFillColor(Color::Green);
	leaf.setPosition(Vector2f(373.f, 350.f));
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(50.f, 40.f));
	leaf.setPoint(1, sf::Vector2f(150.f, 10.f));
	leaf.setPoint(2, sf::Vector2f(100.f, 90.f));
	leaf.setPoint(3, sf::Vector2f(30.f, 100.f));
	Window->draw(leaf);

	sf::ConvexShape leaf2;
	leaf2.setFillColor(Color::Green);
	leaf2.setPosition(Vector2f(428.3f, 350.f));
	leaf2.setPointCount(4);
	leaf2.setPoint(0, sf::Vector2f(50.f, 40.f));
	leaf2.setPoint(1, sf::Vector2f(150.f, 10.f));
	leaf2.setPoint(2, sf::Vector2f(100.f, 90.f));
	leaf2.setPoint(3, sf::Vector2f(30.f, 100.f));
	leaf2.setScale(Vector2f(-1, 1));
	Window->draw(leaf2);
}
