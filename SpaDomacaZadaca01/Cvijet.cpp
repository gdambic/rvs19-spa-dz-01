#include "Cvijet.h"

Cvijet::Cvijet(RenderWindow *window) { this->window = window; }

void Cvijet::draw_flower()
{
	CircleShape flower(80.f);
	flower.setFillColor(Color(255, 255, 0));
	flower.setOutlineColor(Color(255, 255, 0));
	flower.setPosition(100, 100);
	flower.setOutlineThickness(40);
	flower.setOutlineColor(Color(255, 0, 0));
	window->draw(flower);
}

void Cvijet::draw_stem()
{
	RectangleShape stem(Vector2f(8.f, 200.f));
	stem.setFillColor(Color(0, 255, 0));
	stem.setPosition(180, 300);
	window->draw(stem);
}

void Cvijet::draw_leaf()
{
	ConvexShape leaf;
	leaf.setPointCount(4);
	leaf.setPoint(0, Vector2f(187, 400));
	leaf.setPoint(1, Vector2f(250, 350));
	leaf.setPoint(2, Vector2f(500, 250));
	leaf.setPoint(3, Vector2f(250, 450));
	leaf.setFillColor(Color(0, 255, 0));
	window->draw(leaf);
}

void Cvijet::draw()
{
	time = clock.getElapsedTime();
	float sec = time.asSeconds();
	draw_flower();
	draw_stem();
	draw_leaf();
	CircleShape sun(30.f);
	sun.setFillColor(Color(255, 255, 0));
	if (sec >= 34.f)
		clock.restart();
	else
	{
		int speed = 25;
		float move_x = -55.f + (sec * speed);
		sun.setPosition(move_x, 10);
		window->draw(sun);
	}
}