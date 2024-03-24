#include "Cvijet.h"
#include <vector>
#include <ctime>
#include <random>

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

CircleShape Cvijet::drawCloud(Color color, Vector2f position, Vector2f scale)
{
	srand(9);
	CircleShape cloud(10.f);
	cloud.setFillColor(color);
	cloud.setPosition(position);
	cloud.setScale(scale);


	return cloud;
}

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}


void Cvijet::draw()
{

	//draw field
	window->draw(drawBg({ 17,124,19 }, { 1000.f, 1000.f }));

	//draw sky
	window->draw(drawBg({ 135, 206, 235 }, { 1000.f, 200.f }));

	//draw first cloud
	for (size_t i = 0; i < 30; i++)
	{
		window->draw(drawCloud(
			{ 150,150,150 },
			{ 500.f, 50.f },
			{(float)(rand() % 8), (float)(rand() % 8)}
			));
	}

	//draw petals
	for (size_t i = 0; i < 30; i++)
	{
		CircleShape petal = drawPetal(
			{ 250, 224, 5 },
			10.f,
			{ 200.f, 170.f },
			{ 1.f, 8.f }
		);
		// define rotaion in every iteration
		petal.rotate(3 * (4 * i));

		window->draw(petal);
	}

	//draw pistil
	CircleShape pistil(80.f);
	pistil.move(Vector2f(120.f, 90.f));
	pistil.setFillColor(Color(46, 41, 17));
	window->draw(pistil);

}
