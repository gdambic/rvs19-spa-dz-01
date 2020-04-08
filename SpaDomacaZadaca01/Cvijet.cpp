#include "Cvijet.h"

Cvijet::Cvijet(RenderWindow* window, int x, int y)
{
	this->window = window;
	this->x = x;
	this->y = y;
}

void Cvijet::draw()
{
	CircleShape tucak;
	tucak.setPointCount(8);
	tucak.setRadius(10);
	tucak.setPosition(x - 10, y - 10);
	tucak.setFillColor(Color(255, 0, 0));
	RectangleShape stabljika;
	stabljika.setPosition(x - 2.5, y);
	stabljika.setSize(Vector2f(5, 30));
	stabljika.setFillColor(Color(34, 139, 34));
	ConvexShape list;
	list.setPointCount(5);
	list.setPoint(0, Vector2f(x - 2.5, y + 15));
	list.setPoint(1, Vector2f(x + 5, y + 10));
	list.setPoint(2, Vector2f(x + 10, y + 10));
	list.setPoint(3, Vector2f(x + 15, y + 12.5));
	list.setPoint(4, Vector2f(x  + 10, y + 15));
	list.setFillColor(Color(34, 139, 34));
	window->draw(stabljika);
	window->draw(list);
	window->draw(tucak);
}
