#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Sunce
{
private:
	RenderWindow* window;
	float x;
	float y;
	int r;
	int R;
	int os_x;
	int os_y;
	Clock clock;
	int vel;
	bool mode;
	float kut;
public:
	Sunce();
	Sunce(RenderWindow* window, int os_x, int os_y, int R, int r);
	void draw();
	float get_kut();
};

