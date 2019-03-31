#include "Cvijet.h"
#include <iostream>


Cvijet::Cvijet(sf::RenderWindow* window)
{
	
	y = 700+rand()%100;
	x = 50 + rand() % 500;
	this->window = window;
	bojaLatica = sf::Color(100 + rand() % 156, 0, 0);

}

void Cvijet::draw()
{

	const double pi = acos(-1);
	//int coloradd = rand() % 156;
	//Stabljika.setFillColor(sf::Color(100 + coloradd, 0, 0));


	sf::RectangleShape Stabljika(sf::Vector2f(20.f, 350.f));
	Stabljika.setFillColor(sf::Color(71, 206, 61));
	Stabljika.setPosition(sf::Vector2f(x - 10, y - 650 + 80));
	window->draw(Stabljika);

	sf::CircleShape Cvat(50.f);
	Cvat.setPosition(sf::Vector2f(x - 50, y-650));
	Cvat.setFillColor(sf::Color(242, 238, 26));
	window->draw(Cvat);

	sf::CircleShape Latica(15.f);
	Latica.setFillColor(bojaLatica);

	int n = 3;

	for (int i = 0; i <= n; i++) {

		Latica.setPosition(sf::Vector2f(x + cos((double(i)/ n)*(pi/2))* 50 -15, y - 600 + sin((double(i) / n) * (pi/2 )) * 50 - 15));
		window->draw(Latica);

		Latica.setPosition(sf::Vector2f(x + cos((double(i) / n)*(pi / 2)) * 50 - 15, y - 600 - sin((double(i) / n) * (pi / 2)) * 50 - 15));
		window->draw(Latica);
		Latica.setPosition(sf::Vector2f(x - cos((double(i) / n)*(pi / 2)) * 50 - 15, y - 600 + sin((double(i) / n) * (pi / 2)) * 50 - 15));
		window->draw(Latica);
		Latica.setPosition(sf::Vector2f(x - cos((double(i) / n)*(pi / 2)) * 50 - 15, y - 600 - sin((double(i) / n) * (pi / 2)) * 50 - 15));
		window->draw(Latica);

	}
}
