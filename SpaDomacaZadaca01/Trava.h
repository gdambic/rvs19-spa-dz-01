#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Trava
{
private:
	RenderWindow* window;
	Clock clock;
	bool nakoseno;
	float x;
	float y;
	bool mode;
public:
	Trava(RenderWindow* window, float x, float y);
	void draw();
};

