#include "Zvijezda.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Zvijezda::Zvijezda(RenderWindow* window, float x, float y)
{
	this->window = window;
	this->x = x;
	this->y = y;
	vel = rand() % 2;
	treptaj = false;
}

void Zvijezda::draw(int alpha)
{
	Time t1 = clock.getElapsedTime();
	if (t1.asMilliseconds() > rand() % 3000 + 1000) {
		treptaj = !treptaj;
		clock.restart();
	}
	CircleShape zvijezda;
	if (treptaj) {
		zvijezda.setRadius(vel + 1);
	}
	else {
		zvijezda.setRadius(vel);
	}
	zvijezda.setFillColor(Color(255, 255, 255, alpha));
	zvijezda.setPosition(x, y);
	window->draw(zvijezda);

}
