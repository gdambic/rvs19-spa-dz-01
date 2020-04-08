#include "Trava.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Trava::Trava(RenderWindow* window, float x, float y)
{
	this->window = window;
	this->x = x;
	this->y = y;
	if (rand() % 2) {
		nakoseno = true;
	}
	else {
		nakoseno = false;
	}
	mode = true;
}

void Trava::draw()
{
	float temp = 0;
	Time t1 = clock.getElapsedTime();
	if (t1.asMilliseconds() > rand() % 1000 + 500) {
		mode = !mode;
		clock.restart();
	}
	if (mode) {
		temp = 5;
	}
	else {
		temp = 0;
	}
	RectangleShape vlas1;
	RectangleShape vlas2;
	vlas1.setPosition(x, y);
	vlas2.setPosition(x, y);
	if (nakoseno) {
		vlas1.setSize(Vector2f(4, 18));

		vlas1.setRotation(160 + temp);
	}
	else {
		vlas1.setSize(Vector2f(4, 25));
		vlas1.setRotation(180 + temp);
	}
	vlas2.setSize(Vector2f(4, 15));
	vlas2.setRotation(200 + temp);
	vlas1.setFillColor(Color(34, 139, 34));
	vlas2.setFillColor(Color(34, 139, 34));
	window->draw(vlas1);
	window->draw(vlas2);

}
