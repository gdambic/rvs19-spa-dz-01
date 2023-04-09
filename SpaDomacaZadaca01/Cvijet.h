#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Main.hpp>
#include<SFML/System.hpp>
using namespace sf;

class Cvijet
{
private:
	CircleShape sunce;
	CircleShape glava;
	RectangleShape stabiljka;
	ConvexShape list;
	RenderWindow* window;
	RectangleShape trava;
	Clock clock;

public:
	Cvijet(RenderWindow* window);
	void draw();

};
