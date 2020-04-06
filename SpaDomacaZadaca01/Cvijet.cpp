#include "Cvijet.h"
#include<SFML/Graphics.hpp>
#include<SFML/Main.hpp>
#include<SFML/System.hpp>
using namespace sf;

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
	sunce.setRadius(30.f);
	glava.setRadius(60.f);
	glava.setPosition(Vector2f(90.f, 90.f));
	stabiljka.setSize(Vector2f(10.f, 200.f));
	stabiljka.setPosition(Vector2f(150.f, 266.f));
	trava.setSize(Vector2f(800.f, 2000.f));
	trava.setPosition(Vector2f(0.f, 466.f));
	list.setPointCount(4);

	list.setPoint(0, Vector2f(160.f, 366.f));
	list.setPoint(1, Vector2f(220.f, 266.f));
	list.setPoint(2, Vector2f(300.f, 300.f));
	list.setPoint(3, Vector2f(220.f, 400.f));
}

void Cvijet::draw()
{

		sunce.setFillColor(Color::Yellow);
		sunce.move(Vector2f(0.8f, 0.3f));
		glava.setPointCount(9);
		glava.setFillColor(Color::White);
		glava.setOutlineThickness(60.f);
		glava.setOutlineColor(Color::Blue);

		stabiljka.setFillColor(Color(26, 85, 32, 255));

		trava.setFillColor(Color(26, 85, 32, 255));

		list.setFillColor(Color(26, 85, 32, 255));

		window->draw(sunce);
		window->draw(glava);
		window->draw(stabiljka);
		window->draw(trava);
		window->draw(list);

	
}
