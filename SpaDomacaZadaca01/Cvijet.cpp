#include "Cvijet.h"
#include <vector>

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}


void Cvijet::draw()
{
	Vector2f corePosition = { 200.f, 170.f };
	Vector2f petalScale = { 1.f, 8.f };



	for (size_t i = 0; i < 30; i++)
	{
		CircleShape petal(10.f);
		petal.setFillColor(Color(240, 224, 55));
		petal.scale(petalScale);
		petal.move(corePosition);
		petal.rotate(3 * (4*i));
		window->draw(petal);
	}

	CircleShape core(80.f);
	core.move(Vector2f(120.f, 90.f));
	core.setFillColor(Color(46, 41, 17));
	window->draw(core);
}
