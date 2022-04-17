#include <iostream>
#include "Flower.h"

Flower::Flower(RenderWindow* window)
{
	this->window = window;
	this->flowerClock = Clock();
	this->flower = CircleShape(75);
	this->stalk = RectangleShape(Vector2f(15, 250));
	this->leaf = ConvexShape(4);
	this->sunClock = Clock();
	this->sun = CircleShape(25);
	set_elements();
}


void Flower::set_elements()
{
	flower.setFillColor(Color(255, 255, 0));		// set of flower
	flower.setPosition(85, 85);
	flower.setOutlineThickness(55);
	flower.setOutlineColor(Color(255, 0, 0));
	stalk.setFillColor(Color(0, 255, 0));			// set color and position of the stalk
	stalk.setPosition(153, 290);
	leaf.setFillColor(Color(0, 255, 0));			// set color, position and shape of the leaf
	leaf.setPoint(0, Vector2f(158, 400));
	leaf.setPoint(1, Vector2f(320, 320));
	leaf.setPoint(2, Vector2f(550, 290));
	leaf.setPoint(3, Vector2f(290, 450));
	sun.setPosition(10, 10);						// set color and position of the sun
	sun.setFillColor(Color(255, 255, 0));
}



void Flower::sun_animation()
{
	Time t = sunClock.getElapsedTime();
	if (t.asMilliseconds() >= 500)					// wait 500 ms between each animation of the sun
	{
		float size = sun.getRadius();
		Vector2f pos = sun.getPosition();
		if (size == 25)
		{
			sun.setRadius(20);						// small sun
			pos.x += 5;
			pos.y += 5;
			sun.setPosition(pos);
			sun.setFillColor(Color(255, 190, 0));	// orange color
		}
		else
		{
			sun.setRadius(25);						// big sun
			pos.x -= 5;
			pos.y -= 5;
			sun.setPosition(pos);
			sun.setFillColor(Color(255, 255, 0));	// yellow color
		}
		sunClock.restart();
	}
}


void Flower::draw()									// draw all elements + animation						
{
	sun_animation();
	window->draw(flower);
	window->draw(stalk);
	window->draw(leaf);
	window->draw(sun);
}