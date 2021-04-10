#include "Cvijet.h"

using namespace std;
using namespace sf;

Cvijet::Cvijet(RenderWindow * window)
{
	this->window = window;
}

void Cvijet::draw()
{
	if (shapes.size() == 0)
	{
		init_shapes();
	}

	auto crtez = shapes.begin();

	for (;crtez != shapes.end(); crtez++)
	{
		window->draw(**crtez);
	}

}

void Cvijet::init_shapes()
{
	CircleShape* tucak = new CircleShape(100);
	tucak->setFillColor(Color::Magenta);
	tucak->setOutlineColor(Color::White);
	tucak->setOutlineThickness(20);
	tucak->setPosition(100, 100);
	shapes.push_back(tucak);

	RectangleShape* stabljika = new RectangleShape(Vector2f(300, 12));
	stabljika->setFillColor(Color::Green);
	stabljika->rotate(90);
	stabljika->setPosition(205, 300);
	shapes.push_back(stabljika);

	ConvexShape* list = new ConvexShape();
	list->setPointCount(4);
	list->setPoint(0, Vector2f(200, 505));
	list->setPoint(1, Vector2f(300, 455));
	list->setPoint(2, Vector2f(600, 355));
	list->setPoint(3, Vector2f(300, 555));
	list->setFillColor(Color::Green);
	shapes.push_back(list);
}