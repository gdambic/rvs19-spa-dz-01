#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Cvijet
{
public:

	Cvijet(RenderWindow* window);
	void draw();
	void drawFlower();

private:
	Clock frameClock;
	RenderWindow* window;
};

