#pragma once

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Cvijet
{
public:
	Cvijet(RenderWindow* window);
	void set_window(RenderWindow* window);
	void set_xAxisIncrement(float xAxisIncrement);
	void draw();
private:
	RenderWindow* window;
	float xAxisIncrement = 0;
};

