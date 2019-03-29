#include "Cvijet.h"
#include <iostream>
using namespace std;

Cvijet::Cvijet(RenderWindow * window)
{
	this->window = window;
}

void Cvijet::draw()
{
	RectangleShape line(Vector2f(150, 5));
	line.rotate(90);
	line.setFillColor(Color(0,100,0));
	line.setPosition(200, 300);

	CircleShape circle(50);
	circle.setPosition(150, 250);
	circle.setFillColor(Color(255,255,0));
	circle.setOutlineThickness(10);
	circle.setOutlineColor(Color(150, 0, 0));
	ConvexShape shape(4);
	shape.setPoint(0,Vector2f(200,400));
	shape.setPoint(1, Vector2f(300, 350));
	shape.setPoint(2, Vector2f(350, 400));
	shape.setPoint(3, Vector2f(300, 450));
	shape.setFillColor(Color(0, 255, 0));
	CircleShape sun(20);
	sun.setFillColor(Color(255, 255, 0));
	sun.setPosition(50, 50);

	window->draw(sun);
	window->draw(shape);
	window->draw(line);
	window->draw(circle);
}
