#include "Flower.h"

Flower::Flower(sf::RenderWindow* window)
{
	this->window = window;
	this->bee = new Bee();
}

Flower::~Flower()
{
	delete bee;
}

void Flower::draw()
{
	sf::RectangleShape background(sf::Vector2f(window->getSize().x, window->getSize().y));
	background.setFillColor(sf::Color(9, 224, 239));
	window->draw(background);

	sf::RectangleShape floor(sf::Vector2f(window->getSize().x, 50));
	floor.setFillColor(sf::Color(28, 224, 24));
	floor.setPosition(sf::Vector2f(0, window->getSize().y - floor.getSize().y));
	window->draw(floor);

	for (unsigned i = 0; i < 150; i++)
	{
		sf::ConvexShape grass;
		grass.setPointCount(3);
		grass.setPoint(0, sf::Vector2f(0.f, 0));
		grass.setPoint(1, sf::Vector2f(7, 0));
		grass.setPoint(2, sf::Vector2f(3.5, 50));
		grass.setRotation(180);
		grass.setPosition(10 + 10*i + 10 * sin(i / 10), window->getSize().y - 20 + 10*cos(i * 10));
		grass.setFillColor(sf::Color(28, 178, 24));
		window->draw(grass);
	}

	sf::RectangleShape body(sf::Vector2f(5, 700));
	body.setPosition(sf::Vector2f(210, 80));
	body.setFillColor(sf::Color(0, 255, 0));
	window->draw(body);

	EllipseShape leaf(sf::Vector2f(100, 25));
	leaf.setFillColor(sf::Color(10, 255, 10));
	leaf.setPosition(195, 400);
	leaf.setRotation(-45);
	window->draw(leaf);

	sf::CircleShape mainCircle(100.0f);
	mainCircle.setFillColor(sf::Color(255, 255, 0));
	mainCircle.setPosition(sf::Vector2f(120, 40));
	
	for (int i = 0; i < 12; i++)
	{
		sf::CircleShape petal = create_petal();
		petal.setPosition(sf::Vector2f(200 + 100*sin(i*100), 120 + 100*cos(i*100)));
		window->draw(petal);
	}
	
	window->draw(mainCircle);

	// Bee animation
	bee->setPosition(300, 300);
	bee->animation(window);
	window->draw(*bee);
}

sf::CircleShape Flower::create_petal()
{
	sf::CircleShape petal(20.0f);
	petal.setFillColor(sf::Color(255, 255, 255));
	return petal;
}
