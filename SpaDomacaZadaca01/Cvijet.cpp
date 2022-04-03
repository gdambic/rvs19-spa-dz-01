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
	CircleShape circle(50);
	circle.setFillColor(Color(250, 50, 0));
	circle.setPosition(350.f, 250);
	window->draw(circle);
}

	