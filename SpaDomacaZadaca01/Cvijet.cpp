#include "Cvijet.h"

Cvijet::Cvijet(RenderWindow *window)
{
	this->window = window;
	this->flowerClock = Clock();
	this->flower = CircleShape(75);
	this->sunClock = Clock();
	this->sun = CircleShape(25);
	this->stem = RectangleShape(Vector2f(15, 250));
	this->leaf = ConvexShape(4);
	set_param();
}


void Cvijet::set_param()
{
	flower.setFillColor(Color(255, 255, 0));
	flower.setPosition(85, 85);
	flower.setOutlineThickness(55);
	flower.setOutlineColor(Color(255, 0, 0));

	sun.setPosition(10, 10);
	sun.setFillColor(Color(255, 255, 0));

	stem.setFillColor(Color(0, 255, 0));
	stem.setPosition(153, 290);

	leaf.setFillColor(Color(0, 255, 0));
	leaf.setPoint(0, Vector2f(158, 400));
	leaf.setPoint(1, Vector2f(320, 320));
	leaf.setPoint(2, Vector2f(550, 290));
	leaf.setPoint(3, Vector2f(290, 450));
}


void Cvijet::anim_flower()
{
	Time t = flowerClock.getElapsedTime();
	if (t.asMilliseconds() >= 300)
	{
		Color col = flower.getOutlineColor();
		if (col.r == 255)
		{
			flower.setFillColor(Color(0, 255, 255));
			flower.setOutlineColor(Color(0, 0, 255));
			stem.setFillColor(Color(255, 0, 255));
			leaf.setFillColor(Color(255, 0, 255));
		}
		else
		{
			flower.setFillColor(Color(255, 255, 0));
			flower.setOutlineColor(Color(255, 0, 0));
			stem.setFillColor(Color(0, 255, 0));
			leaf.setFillColor(Color(0, 255, 0));
		}
		flowerClock.restart();
	}
}



void Cvijet::anim_sun()
{
	Time t = sunClock.getElapsedTime();
	if (t.asMilliseconds() >= 100)
	{
		float size = sun.getRadius();
		Vector2f place = sun.getPosition();
		if (size == 25)
		{
			sun.setRadius(20);
			place.x += 5;
			place.y += 5;
			sun.setPosition(place);
		}
		else
		{
			sun.setRadius(25);
			place.x -= 5;
			place.y -= 5;
			sun.setPosition(place);
		}
		sunClock.restart();
	}
}


void Cvijet::draw()
{
	anim_sun();
	anim_flower();
	window->draw(flower);
	window->draw(sun);
	window->draw(stem);
	window->draw(leaf);
}