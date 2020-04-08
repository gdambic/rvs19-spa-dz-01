#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Zvijezda
{
private:
	RenderWindow* window;
	Clock clock;
	bool treptaj;
	float x;
	float y;
	int vel;
public:
	Zvijezda(RenderWindow* window, float x, float y);
	void draw(int alpha);
};

