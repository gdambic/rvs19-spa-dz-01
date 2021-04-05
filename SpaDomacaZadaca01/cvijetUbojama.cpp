#include "cvijetUbojama.h"
#include<SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "stabljike.h"
#include<iostream>






cvijetUbojama::cvijetUbojama(int velicina, int x0, int y0)
{
	this->velicina = velicina;
	this->x0 = x0;
	this->y0 = y0;

	
}

cvijetUbojama::cvijetUbojama()
{
}

void cvijetUbojama::konstruktor(float velicina, int x0, int y0,sf::RenderWindow* window)
{
	this->velicina = velicina;
	this->x0 = x0;
	this->y0 = y0;
	this->window = window;
	int k = 0;
	int udaljenost = 50;
	//inicijaliziranje sarenog cvijeta
	
	
	for (int j = 4; j > 0; j -= 1) {
		udaljenost = j;
		int s = j;
		if (j < 10)
			s = 80;
		for (double i = 0; i <= 2 * atan(1) * 4; i += atan(1) * 4 / 3) {
			if (i == 0 && j == 1) { i = -0.25; }
			else if (i == 0 && j == 2) { i = -0.5; }
			else if (i == 0 && j == 3) { i = -0.75; }
			if (i == 5) { i == atan(1) * 4; }
			double x = x0;
			double y = y0;
			double xT = x;
			double yT = y;
			if (j == 2)
				sCvijet[k].setRadius(10);
			else if (j == 5) { sCvijet[k].setRadius(30); }
			else {
				sCvijet[k].setRadius(15);

			}
			sCvijet[k].setPosition(xT, yT);
			if (j == 2)
				sCvijet[k].setFillColor(Color::White);
			else if (j == 5) {
				sCvijet[k].setFillColor(Color::White);

			}
			else if (k % 3 == 1) {
				sCvijet[k].setFillColor(Color::Blue);

			}
			else if (k % 3 == 2)
				sCvijet[k].setFillColor(Color::Red);

			else
				sCvijet[k].setFillColor(Color::Magenta);
			if (j == 5)
				sCvijet[k].setScale(velicina, 0.2f);
			else
				sCvijet[k].setScale(velicina, 0.6f);
			pretvorbe[k].rotate(-(i * 180) / ((atan(1) * 4)), Vector2f(xT, yT));

			k++;
		}
	}

	
	

}

Transform cvijetUbojama::at(int a)
{
	return pretvorbe[a];
}

CircleShape cvijetUbojama::na(int a)
{
	return sCvijet[a];
}

void cvijetUbojama::zapocni(int a0, int b0)
{
	s.inicializiraj(600 - y0, 2 + (600-y0) / 100, *window, x0, y0,a0,b0);
}
