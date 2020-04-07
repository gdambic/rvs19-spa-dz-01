#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
using namespace sf;

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}
	

void Cvijet::draw()
{
	//tucak
	CircleShape tucak(30.f);
	tucak.setFillColor(sf::Color::White);
	
	//latice
	CircleShape latice(35.f);

	int brlatica = 16;
	float kut = 2 * 3.1415 / brlatica;

	
	//stabiljka
	RectangleShape stabiljka(Vector2f(5.f, 250.f));
	stabiljka.setFillColor(Color(0, 255, 9));

	//list
	ConvexShape list;
	list.setPointCount(4);
	list.setFillColor(Color(0, 255, 9));

	//nebo
	RectangleShape nebo(Vector2f(800, 600));
	nebo.setFillColor(Color(173, 216, 230));
	window->draw(nebo);

	//sunce
	CircleShape sunce(37);
	sunce.setPosition(51.f, 51.f);
	sunce.setFillColor(Color(255, 255, 0));
	window->draw(sunce);

	CircleShape zrake(37, 3);
	zrake.setPosition(90, 90);
	zrake.setFillColor(Color(255, 255, 0));
	for (int i = 0; i < 15; i++)
	{
		window->draw(zrake);
		zrake.rotate(30);
	}


	//trava
	RectangleShape trava(Vector2f(800, 100));
	trava.setPosition(0, 500);
	trava.setFillColor(Color(0, 255, 9));
	window->draw(trava);


float a = 270, b = 250, c = 20;
for (int i = 0; i < 2; i++)
{
	tucak.setPosition(a, b);

	stabiljka.setPosition(a + 30, b + 90);




	

	if (i % 2 == 0)
	{
		srand(time(0));
		latice.setFillColor(sf::Color(rand() + 15 % 255, rand() + 10 % 255, rand() + 10 % 255));

	}

	else
	{
		srand(time(0));
		latice.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));

	}


	list.setPoint(0, sf::Vector2f(a + 30, 410.f));
	list.setPoint(1, sf::Vector2f(a + 50, 385.f));
	list.setPoint(2, sf::Vector2f(a + 100, 380.f));
	list.setPoint(3, sf::Vector2f(a + 60, 415.f));

	window->draw(tucak);
	latice.setPosition(a+25, b+25);
	for (unsigned int j = 0; j <= brlatica; j++)
	{	
		latice.setOrigin(30.f + (30.f + 30.f) * std::sin(j * kut), 30.f + (30.f + 30.f) * std::cos(j * kut));
		//latice.setFillColor(sf::Color(128, 0, 128));
		latice.setOutlineThickness(1);
		latice.setOutlineColor(sf::Color::Black);
		window->draw(latice);
	}


	
	window->draw(stabiljka);
	window->draw(list);


	a += 200;

}



}









	

