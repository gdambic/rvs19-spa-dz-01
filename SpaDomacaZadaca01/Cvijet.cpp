#include "Cvijet.h"


Cvijet::Cvijet(RenderWindow* window) : window(window),sun_size(30),sun_state(true),sun_x(10)
{}

void Cvijet::draw()
{
	sun.setPosition(sun_x, 10);
	sun.setRadius(sun_size);
	sun.setFillColor(Color::Yellow);

	shape.setPosition(100, 150);
	shape.setRadius(60);
	shape.setFillColor(Color::Red);
	shape.setOutlineThickness(50);
	shape.setOutlineColor(Color::Magenta);

	stem.setPosition(Vector2f(155, 320));
	stem.setSize(Vector2f(10, 270));
	stem.setFillColor(Color::Green);

	leaf.setPointCount(4);
	leaf.setPosition(Vector2f(160, 400));
	leaf.setPoint(0, Vector2f(0, 0));
	leaf.setPoint(1, Vector2f(100, 10));
	leaf.setPoint(2, Vector2f(200, 90));
	leaf.setPoint(3, Vector2f(50, 50));
	leaf.setFillColor(Color::Green);

	window->draw(shape);
	window->draw(sun);
	window->draw(stem);
	window->draw(leaf);

	

	if (frameClock.getElapsedTime().asMilliseconds() > 300) {
			frameClock.restart();
			if (sun_state) {

				if (sun_x<500) {
					sun_x += 15;
					sun_size++;
				}
				else {
					sun_state = false;
				}
			}
			else {
				if (sun_x > 10) {
					sun_x -= 15;
					sun_size--;
				}
				else {
					sun_state = true;
				}
			}
	}
}
