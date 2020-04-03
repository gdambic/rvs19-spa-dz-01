#include "Cvijet.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

Cvijet::Cvijet(RenderWindow* prozor_za_crtanje)
{
	this->prozor_za_crtanje = prozor_za_crtanje;
}

void Cvijet::draw()
{

	sunce.setRadius(40);
	sunce.setPointCount(60);
	sunce.setFillColor(Color(255, 255, 0));
	sunce.setOutlineThickness(10);
	sunce.setOutlineColor(Color(255, 100, 0));
	sunce.setPosition(50.f, 50.f);
	sunce.setRotation(sat.getElapsedTime().asMilliseconds()/10);
	sunce.setPointCount(12);

	

	tucak.setPosition(190.f, 280.f);
	tucak.setRadius(40);
	tucak.setPointCount(20);
	tucak.setFillColor(Color(255, 3,62));

	stabiljka.setSize(Vector2f(20.f, 240.f));
	stabiljka.setFillColor(Color(0, 100, 0));
	stabiljka.setPosition(220.f, 360.f);

	list.setPointCount(4);
	list.setPoint(0, Vector2f(50.f, 50.f));
	list.setPoint(1, Vector2f(100.f,25.f));
	list.setPoint(2, Vector2f(250.f,50.f));
	list.setPoint(3, Vector2f(100.f,75.f));
	list.setFillColor(Color(0, 100, 0));
	list.setPosition(170,470);
	list.setRotation(-25);


	list1.setPointCount(4);
	list1.setPoint(0, Vector2f(50.f, 50.f));
	list1.setPoint(1, Vector2f(100.f,25.f));
	list1.setPoint(2, Vector2f(250.f,50.f));
	list1.setPoint(3, Vector2f(100.f,75.f));
	list1.setFillColor(Color(0, 100, 0));
	list1.setPosition(245,560);
	list1.setRotation(-155);


	latice[0].setRadius(16);
	latice[0].setPointCount(30);
	latice[0].setFillColor(Color(255, 3, 62));
	latice[0].setPosition(170.f, 280.f);

	latice[1].setRadius(16);
	latice[1].setFillColor(Color(255, 3, 62));
	latice[1].setPointCount(30);
	latice[1].setPosition(164.f, 305.f);

	latice[2].setRadius(16);
	latice[2].setFillColor(Color(255, 3, 62));
	latice[2].setPointCount(30);
	latice[2].setPosition(265.f, 305.f);
	
	latice[3].setRadius(16);
	latice[3].setFillColor(Color(255, 3, 62));
	latice[3].setPointCount(30);
	latice[3].setPosition(259.f, 280.f);

	latice[4].setRadius(16);
	latice[4].setFillColor(Color(255, 3, 62));
	latice[4].setPointCount(30);
	latice[4].setPosition(173.f, 330.f);

	latice[5].setRadius(16);
	latice[5].setFillColor(Color(255, 3, 62));
	latice[5].setPointCount(30);
	latice[5].setPosition(256.f, 330.f);
	
	latice[6].setRadius(15);
	latice[6].setFillColor(Color(255, 3, 62));
	latice[6].setPointCount(30);
	latice[6].setPosition(193.f, 350.f);
	
	latice[7].setRadius(15);
	latice[7].setFillColor(Color(255, 3, 62));
	latice[7].setPointCount(30);
	latice[7].setPosition(238.f, 350.f);

	latice[8].setRadius(16);
	latice[8].setPointCount(30);
	latice[8].setFillColor(Color(255, 3, 62));
	latice[8].setPosition(215.f, 355.f);

	latice[9].setRadius(16);
	latice[9].setPointCount(30);
	latice[9].setFillColor(Color(255, 3, 62));
	latice[9].setPosition(213.f, 253.f);

	latice[10].setRadius(16);
	latice[10].setPointCount(30);
	latice[10].setFillColor(Color(255, 3, 62));
	latice[10].setPosition(238.f, 262.f);

	latice[11].setRadius(16);
	latice[11].setPointCount(30);
	latice[11].setFillColor(Color(255, 3, 62));
	latice[11].setPosition(188.f, 262.f);

	prozor_za_crtanje->draw(sunce);
	prozor_za_crtanje->draw(tucak);
	prozor_za_crtanje->draw(stabiljka);
	prozor_za_crtanje->draw(list);
	prozor_za_crtanje->draw(list1);
	for (int i = 0; i < 12; i++)
	{
		prozor_za_crtanje->draw(latice[i]);	
	}
}
