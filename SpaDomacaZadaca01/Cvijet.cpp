#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;
using namespace sf;

Cvijet::Cvijet()
{

}

Cvijet::Cvijet(RenderWindow* window) 
{
	this->mwindow = window;
	
}

void Cvijet::drawCvijet()
{


	//Stabiljka
	stabiljka.setSize(Vector2f(300, 20));
	stabiljka.setFillColor(Color::Yellow);
	stabiljka.setRotation(90);
	stabiljka.setPosition(200, 285);
	mwindow->draw(stabiljka);

	//Cvijet
	krugCvijeta.setRadius(70);
	krugCvijeta.setFillColor(Color::Green);
	krugCvijeta.setOutlineThickness(45);
	krugCvijeta.setOutlineColor(Color::Red);
	krugCvijeta.setPosition(120, 100);
	mwindow->draw(krugCvijeta);

	//List
	list.setPointCount(5);
	list.setFillColor(Color::Blue);
	list.setPoint(0, Vector2f(0.f, 0.f));
	list.setPoint(1, Vector2f(150.f, 100.f));
	list.setPoint(2, Vector2f(120.f, 90.f));
	list.setPoint(3, Vector2f(30.f, 100.f));
	list.setPoint(4, Vector2f(0.f, 50.f));
	list.setPosition(360, 350);
	list.setRotation(120);
	mwindow->draw(list);
}

void Cvijet::drawTriangle()
{

	dt = clock.restart();
	triangle.setRadius(triangleRadius);
	triangle.setPointCount(3);
	triangle.setPosition(x, y);
	triangle.setFillColor(Color::Magenta);
	mwindow->draw(triangle);

	x += brzina * dt.asSeconds();
	triangleRadius -= 0.5;
	
	if (x >= granica_gornja || x <= granica_donja)
	{
		triangleRadius = 50;
		brzina *= -1.0f;
	}
}

void Cvijet::drawText(string fontDirectory)
{
	if (!font.loadFromFile(fontDirectory))
	{
		cerr << "Nemogu naci font!";
	}
	text.setFont(font);
	text.setString("BIMBA, CVILI ... SIJA NUSR !!!");
	text.setCharacterSize(50);
	text.setFillColor(Color::Cyan);
	text.setStyle(Text::Bold);
	text.setPosition(400, 500);
	mwindow->draw(text);
}
