#include "Tlo.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>


Tlo::Tlo(RenderWindow* window, int n)
{
	this->window = window;
	this->n = n;
	int grid_size = 8;
	for (int i = 0; i < n; i++) {
		int x = grid_size * (rand() % (window->getSize().x / grid_size));
		int y = grid_size * (rand() % ((window->getSize().y / 3) / grid_size) + (2 * window->getSize().y / 3) / grid_size);
		trave.push_back(Trava(window, x, y));
	}
	for (int i = 0; i < n / 100; i++) {
		int x = grid_size * (rand() % (window->getSize().x / grid_size));
		int y = grid_size * (rand() % ((window->getSize().y / 3) / grid_size) + (2 * window->getSize().y / 3) / grid_size);
		cvjetovi.push_back(Cvijet(window, x, y));
	}
}

void Tlo::draw()
{
	ConvexShape tlo;
	tlo.setPointCount(4);
	tlo.setPoint(0, Vector2f(0.f, 2 * window->getSize().y / 3));
	tlo.setPoint(1, Vector2f(window->getSize().x, 2 * window->getSize().y / 3));
	tlo.setPoint(2, Vector2f(window->getSize().x, window->getSize().y));
	tlo.setPoint(3, Vector2f(0.f, window->getSize().y));
	tlo.setFillColor(Color(0, 255, 0));
	window->draw(tlo);
	for (int i = 0; i < trave.size(); i++) {
		trave[i].draw();
	}
	for (int i = 0; i < cvjetovi.size(); i++) {
		cvjetovi[i].draw();
	}
}