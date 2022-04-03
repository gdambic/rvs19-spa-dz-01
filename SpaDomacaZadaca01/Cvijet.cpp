#include "Cvijet.h"

Cvijet::Cvijet(RenderWindow* window)
{
	set_window(window);
}

void Cvijet::set_window(RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	CircleShape sun(30);
	sun.setFillColor(Color(255, 255, 0));
	sun.setPosition(0, 0);
	window->draw(sun);

	/*CircleShape sun(30);
	sun.setFillColor(Color(255, 255, 0));
	float xVelocity = 3;
	if (sun.getPosition().x <= window->getSize().x)
	{
		float sunPos = sun.getPosition().x + xVelocity;
		sun.setPosition(sunPos, 0);
		window->draw(sun);
	}
	else
	{
		sun.setPosition(0, 0);
	}*/

	CircleShape head(50);
	head.setFillColor(Color(255, 255, 0));
	head.setOutlineThickness(30);
	head.setOutlineColor(Color(230, 0, 0));
	head.setPosition(head.getOutlineThickness() + 50, head.getOutlineThickness() + 50);
	window->draw(head);
	
	RectangleShape pedicel(Vector2f(185.f, 15.f));
	pedicel.setFillColor(Color(0, 230, 0));
	pedicel.setPosition(head.getPosition().x + pedicel.getSize().y/2 + head.getRadius(), head.getPosition().y + head.getRadius()*2 + head.getOutlineThickness());
	pedicel.rotate(90.f);
	window->draw(pedicel);

	ConvexShape leaf;
	leaf.setFillColor(Color(0, 230, 0));
	leaf.setPointCount(4);
	leaf.setPoint(0, Vector2f(pedicel.getPosition().x , pedicel.getPosition().y + pedicel.getSize().x/2));
	leaf.setPoint(1, Vector2f(leaf.getPoint(0).x + 50, leaf.getPoint(0).y - 40));
	leaf.setPoint(2, Vector2f(leaf.getPoint(1).x + 50, leaf.getPoint(1).y - 20));
	leaf.setPoint(3, Vector2f(leaf.getPoint(0).x + 50, leaf.getPoint(0).y - 10));
	window->draw(leaf);
	
	RectangleShape ground(Vector2f(window->getSize().x, window->getSize().y - pedicel.getPosition().y));
	ground.setFillColor(Color(102, 51 ,0));
	ground.setPosition(0, pedicel.getPosition().y + pedicel.getSize().x);
	window->draw(ground);
}