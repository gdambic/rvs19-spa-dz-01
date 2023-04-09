#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Cvijet
{
private:
	RenderWindow* window;
	RectangleShape Linija, LinijaSunce1, LinijaSunce2, LinijaSunce3, Grass;
	CircleShape Oblik, Sunce;
	ConvexShape llist, rlist;

public:
	Cvijet(RenderWindow& w);
	void draw();
};
