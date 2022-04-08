#include "Cvijet.h"

// TODO: clean up this code

void Cvijet::createInnerCircle()
{
	// Making the inner circle of the flower yellow
	innerCircle.setFillColor(innerFlowerColor);
	innerCircle.setPosition(x, y);
}

void Cvijet::createOuterCircle()
{
	outerCircle.setFillColor(outerFlowerColor);
	outerCircle.setPosition(x - (sizeOuter - sizeInner), y - (sizeOuter - sizeInner));
}

void Cvijet::createStem()
{
	float halfRadius = sizeOuter / 2.f;
	stem.setFillColor(plantColor);
	stem.setPosition(sf::Vector2f(x + halfRadius, y + (sizeOuter * 1.5f)));
}

void Cvijet::createLeaf()
{
	leaf.setFillColor(plantColor);

	setLeafSize(170.f, 60.f);
}

Cvijet::Cvijet(sf::RenderWindow* window)
{
	// Circle size
	setSize(85.f);

	this->innerCircle = sf::CircleShape(sizeInner);
	this->outerCircle = sf::CircleShape(sizeOuter);
	this->stem = sf::RectangleShape(sf::Vector2f(10.f, 180.f));
	this->leaf = sf::ConvexShape(4); // The parameter is the point count

	// Position of the flower (circle)
	setPosition(200.f, 150.f);

	// Pointer to the window
	this->window = window;

	// All colors of the flower
	this->plantColor = sf::Color(0, 192, 32);
	this->innerFlowerColor = sf::Color(255, 255, 0);
	this->outerFlowerColor = sf::Color(255, 0, 0);

	// Initaliazing all parts of the flower
	createInnerCircle();
	createOuterCircle();
	createStem();
	createLeaf();
}


void Cvijet::draw()
{
	// Drawing the stem
	window->draw(stem);

	window->draw(leaf);

	// Drawing the flower circles
	window->draw(outerCircle);
	window->draw(innerCircle);
}

void Cvijet::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;

	innerCircle.setPosition(x, y);
	outerCircle.setPosition(x - (sizeOuter - sizeInner), y - (sizeOuter - sizeInner));
	// stem.setPosition(sf::Vector2f(x + (sizeOuter / 2.f), y + (sizeOuter * 0.75)));
}

void Cvijet::setSize(float size)
{
	this->sizeOuter = size;
	this->sizeInner = size - 35.f; // This can be any number, I just used 35 because it looked nice
}

void Cvijet::setLeafSize(float width, float height)
{
	this->leafWidth = width / 2.f;
	this->leafHeight = height / 2.f;

	float halfRadius = sizeOuter / 2.f;
	float xl = x + halfRadius;
	float yl = y + (sizeOuter * 2.5f);

	setLeafPosition(xl, yl);
}

void Cvijet::setLeafPosition(float x, float y)
{
	// Defining the points of the leaf shape
	// The points have to be defined clockwise/counter clockwise
	leaf.setPoint(0, sf::Vector2f(x, y));
	leaf.setPoint(1, sf::Vector2f(x + leafWidth, y - leafHeight));
	leaf.setPoint(2, sf::Vector2f(x + (leafWidth * 2), y));
	leaf.setPoint(3, sf::Vector2f(x + leafWidth, y + leafHeight));
}
