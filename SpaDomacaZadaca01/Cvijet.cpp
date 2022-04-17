#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}

void Cvijet::circle() {
	CircleShape shape(50.f);
	shape.setFillColor(sf::Color(152, 92, 255));

	shape.setPosition(100.f, 100.f);
	shape.move(10.f, 10.f);

	window->draw(shape);
}



void Cvijet::draw() {
	circle();

}
