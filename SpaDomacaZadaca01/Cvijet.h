#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Cvijet
{
private:
	RenderWindow* window;
	Clock frameClock;

public:
	Cvijet(RenderWindow* window);
	void draw();
};

