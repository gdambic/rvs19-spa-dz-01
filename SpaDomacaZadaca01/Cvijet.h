#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Cvijet
{
private:
	RenderWindow* window;
	int x;
	int y;
public:
	Cvijet(RenderWindow* window, int x, int y);
	void draw();
};

