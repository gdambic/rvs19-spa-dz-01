#include "Cvijet.h"
using namespace sf;

Cvijet::Cvijet(RenderWindow& w)
{
	window = &w;
	const int xLinija = 380;
	const int yLinija = 320;
	const int xOblik = 375;
	const int yOblik = 250;
	const int xSunce = 700;
	const int ySunce = 10;
	const Color DarkGreen = Color(51, 102, 0);
	const Color GoldenYellow = Color(207, 169, 35);
	const Color LeafGreen = Color(0, 153, 51);

	Oblik.setRadius(10);
	Oblik.setPosition(xOblik, yOblik);
	Oblik.setFillColor(Color(32,32,32));
	Oblik.setOutlineThickness(50.f);
	Oblik.setOutlineColor(Color::Red);

	Linija.setSize(Vector2f(10, 250));
	Linija.setPosition(xLinija, yLinija);
	Linija.setFillColor(Color(DarkGreen));

	llist.setPointCount(3);
	llist.setPoint(0, Vector2f(xLinija, 500));
	llist.setPoint(1, Vector2f(xLinija, 550));
	llist.setPoint(2, Vector2f(250, 450));
	llist.setFillColor(Color(LeafGreen));
	llist.setOutlineThickness(3.f);
	llist.setOutlineColor(Color(DarkGreen));

	rlist.setPointCount(3);
	rlist.setPoint(0, Vector2f(xLinija + 10, 470));
	rlist.setPoint(1, Vector2f(xLinija + 10, 525));
	rlist.setPoint(2, Vector2f(500, 425));
	rlist.setFillColor(Color(LeafGreen));
	rlist.setOutlineThickness(3.f);
	rlist.setOutlineColor(Color(DarkGreen));

	Sunce.setRadius(30);
	Sunce.setPosition(xSunce, ySunce);
	Sunce.setFillColor(Color(255, 255, 51));

	LinijaSunce1.setSize(Vector2f(3, 70));
	LinijaSunce1.setPosition(685, 65);
	LinijaSunce1.setFillColor(Color(GoldenYellow));
	LinijaSunce1.rotate(50.f);

	LinijaSunce2.setSize(Vector2f(3, 70));
	LinijaSunce2.setPosition(710, 80);
	LinijaSunce2.setFillColor(Color(GoldenYellow));
	LinijaSunce2.rotate(35.f);

	LinijaSunce3.setSize(Vector2f(3, 70));
	LinijaSunce3.setPosition(685, 30);
	LinijaSunce3.setFillColor(Color(GoldenYellow));
	LinijaSunce3.rotate(65.f);

	Grass.setSize(Vector2f(800, 50));
	Grass.setPosition(0, 550);
	Grass.setFillColor(Color(LeafGreen));
}

void Cvijet::draw()
{
	window->draw(Oblik);
	window->draw(Linija);
	window->draw(llist);
	window->draw(rlist);
	window->draw(Sunce);
	window->draw(LinijaSunce1);
	window->draw(LinijaSunce2);
	window->draw(LinijaSunce3);
	window->draw(Grass);
}

