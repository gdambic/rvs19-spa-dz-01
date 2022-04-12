#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Cvijet
{
private:
	Time time;
	RenderWindow *window;
	Clock clock;
	void draw_flower();
	void draw_stem();
	void draw_leaf();

public:
	Cvijet(RenderWindow *window);
	void draw();
};