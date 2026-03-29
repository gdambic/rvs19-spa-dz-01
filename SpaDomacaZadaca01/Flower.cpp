#include "Flower.h"

Flower::Flower(RenderWindow* window, Clock& clock)
{
	this->window = window;
	this->clock = clock;
}

void Flower::drawPetal(RectangleShape& petal, float rotation)
{
	petal.rotate(rotation);
	window->draw(petal);
}

void Flower::draw()
{
	sf::Time elapsed = clock.restart();

	//set background
	RectangleShape background(Vector2f(800.f, 600.f));
	background.setFillColor(Color(0, 255, 255));

	//set flower base
	RectangleShape base(Vector2f(500.f, 8.f));
	base.setFillColor(Color(0, 204, 0));
	base.rotate(90.f);
	base.setPosition(350.f, 250.f);

	//set flower leaf
	ConvexShape leaf;
	leaf.setPointCount(3);
	leaf.setPoint(0, Vector2f(340.f, 450.f));
	leaf.setPoint(1, Vector2f(550.f, 400.f));
	leaf.setPoint(2, Vector2f(400.f, 500.f));
	leaf.setFillColor(Color(0, 204, 0));

	//set flower petals
	RectangleShape petal(Vector2f(150.f, 5.f));
	petal.setPosition(350.f, 250.f);
	rotation += 0.1;

	//set center of flower
	CircleShape flowerCenter(50.f);
	flowerCenter.setPosition(300.f, 200.f);
	flowerCenter.setFillColor(Color(255, 255, 0));
	flowerCenter.setOutlineThickness(20.f);
	flowerCenter.setOutlineColor(Color(250, 150, 100));

	//set sun
	CircleShape sun(60.f);
	sun.setPosition(650.f, 15.f);
	sun.setFillColor(Color(255, 255, 0));

	//drawing
	window->draw(background);
	window->draw(base);
	window->draw(leaf);
	for (int i = 0; i < 360 / 5; i++)
	{
		drawPetal(petal, rotation);
	}
	window->draw(flowerCenter);
	window->draw(sun);
}