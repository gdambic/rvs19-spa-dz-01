#include "Cvijet.h"
using namespace sf;
Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;

	this->c = 3.f;
	this->n = 0.f;
	this->count = 0;
	this->sunX = 0;
	this->sunY = 100;
	this->sunRadius = 75.f;
	this->sunMovementY = 0.f;
}

void Cvijet::draw()
{
	// Animating the Sun
	sunX += 0.4;
	sunMovementY -= 0.002;
	sunY = sunRadius * sin(sunMovementY);
	CircleShape sun(sunRadius);
	sun.setPointCount(200);
	sun.setPosition(sunX, sunY);
	sun.setFillColor(Color(255, 255, 0));
	sun.setOutlineColor(Color(255, 255, 51));
	window->draw(sun);

	RectangleShape stem(Vector2f(15.f, 250.f));
	stem.setPosition(Vector2f(275.f, 340.f));
	stem.setFillColor(Color(51, 102, 0));
	window->draw(stem);

	// Base of the flower
	CircleShape flower(125.f);
	flower.setPointCount(200);
	flower.setPosition(158.f, 140.f);
	flower.setFillColor(Color(51, 0, 25));
	window->draw(flower);

	ConvexShape leaf;
	leaf.setPointCount(4);
	leaf.setPoint(0, Vector2f(285.f, 550.f));
	leaf.setPoint(1, Vector2f(360.f, 525.f));
	leaf.setPoint(2, Vector2f(425.f, 425.f));
	leaf.setPoint(3, Vector2f(325.f, 475.f));
	leaf.setFillColor(Color(51, 102, 0));
	window->draw(leaf);

	// Animating circles and mimicking phyllotaxis
	double a = this->n * 137.3f;
	double r = this->c * sqrt(n);

	double x = r * cos(a) + 278;
	double y = r * sin(a) + 260;
	this->circle.push_back(CircleShape());
	this->circle[this->count].setFillColor(Color(int(this->n) % 153, 0, 76, 102));
	this->circle[this->count].setOutlineColor(Color(204, 0, 102));
	this->circle[this->count].setPosition(Vector2f(x, y));
	this->circle[this->count].setRadius(5.f);

	window->draw(this->circle[count]);
	vector<CircleShape> oldCircle;
	oldCircle = this->circle;

	for (auto& circle : oldCircle)
	{
		window->draw(circle);
	}
	for (auto& circle : this->circle)
	{
		window->draw(circle);
	}

	if (count == 2000)
	{
		return;
	}

	window->draw(oldCircle[count]);
	this->count++;
	this->n++;
}