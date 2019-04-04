#include "Cvijet.h"
#include <iostream>


Cvijet::Cvijet(sf::RenderWindow* window)
{
	
	y = 700+rand()%100;
	x = 70 + rand() % 650;
	this->window = window;
	bojaLatica = sf::Color(100 + rand() % 156, 0, 0);
	bojaStabljika= sf::Color(71, 170 + rand() % 60, 61);
	bojaList = sf::Color(90, 170 + rand() % 60, 80);
	visinaLisca = rand() % 200;

}

void Cvijet::draw()
{
	velicinalatice += uvecanje;
	if (rotacija == 60){
		rotacija = 0;
	}
	if (velicinalatice > 20 || velicinalatice < 15)
		uvecanje -= 2 * uvecanje;

	const double pi = acos(-1);

	//int coloradd = rand() % 156;
	//Stabljika.setFillColor(sf::Color(100 + coloradd, 0, 0));


	sf::RectangleShape Stabljika(sf::Vector2f(20.f, 350.f));
	Stabljika.setFillColor(bojaStabljika);
	Stabljika.setPosition(sf::Vector2f(x - 10, y - 650 + 80));
	window->draw(Stabljika);

	sf::CircleShape Cvat(50.f);
	Cvat.setPosition(sf::Vector2f(x - 50, y-650));
	Cvat.setFillColor(sf::Color(242, 238, 26));
	window->draw(Cvat);

	sf::CircleShape Latica(velicinalatice);
	Latica.setFillColor(bojaLatica);


	sf::CircleShape List(15.f);
	List.setScale(4, 1);
	List.setFillColor(bojaList);
	List.setPosition(sf::Vector2f(x +10, y - 650 + 150 + visinaLisca));
	List.rotate(abs(30-rotacija));
	window->draw(List);





	int n = 3;
	for (int i = 0; i <= n; i++) {

		Latica.setPosition(sf::Vector2f(x + cos(((double(i)+rotacija/60.0)/ n)*(pi/2))* 50 -15, y - 600 + sin(((double(i) + rotacija / 60.0) / n) * (pi/2 )) * 50 - 15));
		window->draw(Latica);
		Latica.setPosition(sf::Vector2f(x + cos(((double(i) - rotacija / 60.0) / n)*(pi / 2)) * 50 - 15, y - 600 - sin(((double(i) - rotacija / 60.0) / n) * (pi / 2)) * 50 - 15));
		window->draw(Latica);
		Latica.setPosition(sf::Vector2f(x - cos(((double(i) - rotacija / 60.0) / n)*(pi / 2)) * 50 - 15, y - 600 + sin(((double(i) - rotacija / 60.0) / n) * (pi / 2)) * 50 - 15));
		window->draw(Latica);
		Latica.setPosition(sf::Vector2f(x - cos(((double(i) + rotacija / 60.0) / n)*(pi / 2)) * 50 - 15, y - 600 - sin(((double(i) + rotacija / 60.0) / n) * (pi / 2)) * 50 - 15));
		window->draw(Latica);

	}

	rotacija++;
}
