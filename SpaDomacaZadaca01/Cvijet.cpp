#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace std;

Cvijet::Cvijet(sf::RenderWindow &window,int x,int y,double e) : prozor(window)
{
	setPos(x, y);
	setElasticity(e);
}

Cvijet& Cvijet::operator=(const Cvijet& source) {
	if (this == &source) {
		return *this;
	}

	this->x = source.x;
	this->y = source.y;
	this->dy = source.dy;
	this->gravity = source.gravity;
	this->elasticity = source.elasticity;
	this->unistiti = source.unistiti;

}

void Cvijet::draw()
{
	sf::CircleShape shape(5);
	shape.setFillColor(sf::Color(150, 50, 250));

	// set a 10-pixel wide orange outline
	shape.setPointCount(100);
	shape.setPosition(x,y);
	prozor.draw(shape);
}

void Cvijet::update()
{
	if (y+10 < 600) {
		y += dy;
		dy += gravity;
	}
	else {
		dy *= -elasticity;
		y += dy*2;
		if (abs(dy) < 1) {
			dy = 0;
			unistiti = true;
		}
	}
}

void Cvijet::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Cvijet::setElasticity(double e) {
	elasticity = e;
}

bool Cvijet::trebaUnistiti() {
	return unistiti;
}

