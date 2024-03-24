#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Cvijet
{
private:
	RenderWindow* window;
	CircleShape shape;
	CircleShape sun;
	RectangleShape stem;
	ConvexShape leaf;
	Clock frameClock;
	float sun_x;
	float sun_size;
	bool sun_state;

public:
	Cvijet(RenderWindow* window);
	void draw();


};

