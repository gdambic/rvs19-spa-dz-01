#include "Cvijet.h"

Cvijet::Cvijet(RenderWindow *window)
{
	this->window = window;
}


void Cvijet::draw()
{
	CircleShape flower(75);
	flower.setFillColor(Color(255, 255, 0));
	flower.setPosition(85, 85);
	flower.setOutlineThickness(55);
	flower.setOutlineColor(Color(255, 0, 0));
	window->draw(flower);

	CircleShape sun(25);
	sun.setPosition(10, 10);
	sun.setFillColor(Color(255, 255, 0));
	window->draw(sun);

	RectangleShape rectangle(Vector2f(15, 250));
	rectangle.setFillColor(Color(0, 255, 0));
	rectangle.setPosition(153, 290);
	window->draw(rectangle);


	ConvexShape leaf(4);
	leaf.setFillColor(Color(0, 255, 0));
	leaf.setPoint(0, Vector2f(158, 400));
	leaf.setPoint(1, Vector2f(320, 320));
	leaf.setPoint(2, Vector2f(550, 290));
	leaf.setPoint(3, Vector2f(290, 450));
	window->draw(leaf);
}

void Cvijet::anim()
{

}