#include "Cvijet.h"
#include <vector>

RectangleShape Cvijet::drawBg(Color color, Vector2f size)
{
	RectangleShape bg(size);
	bg.setFillColor(color);

	return bg;
}

CircleShape Cvijet::drawPetal(Color color, float size, Vector2f position, Vector2f scale)
{

	CircleShape petal(size);
	petal.setFillColor(color);
	petal.scale(scale);
	petal.move(position);


	return petal;
}

//CircleShape Cvijet::drawPetal()
//{
//
//
//
//
//}

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}


void Cvijet::draw()
{
	//draw field

	Color grassColor = { 17,124,19 };
	Vector2f grassSize = { 1000.f, 1000.f };
	window->draw(drawBg(grassColor, grassSize));

	//draw sky
	Color skyColor = { 135, 206, 235 };
	Vector2f skySize = { 1000.f, 200.f };
	window->draw(drawBg(skyColor, skySize));




	//draw petals

	Color petalColor = { 250, 224, 5 };
	Vector2f petalPosition = { 200.f, 170.f };
	Vector2f petalScale = { 1.f, 8.f };

	for (size_t i = 0; i < 30; i++)
	{
		CircleShape petal = drawPetal(petalColor, 10.f, petalPosition, petalScale);
		petal.rotate(3 * (4 * i));
		window->draw(petal);
	}

	//draw pistil

	CircleShape pistil(80.f);
	pistil.move(Vector2f(120.f, 90.f));
	pistil.setFillColor(Color(46, 41, 17));
	window->draw(pistil);

}
