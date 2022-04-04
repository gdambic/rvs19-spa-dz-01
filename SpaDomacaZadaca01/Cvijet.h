#pragma once

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Cvijet
{
public:
	Cvijet(RenderWindow* window);
	void set_window(RenderWindow* window);
	Time stanje = frameClock.getElapsedTime();
	void draw();


private:
	RenderWindow* window;

	Clock frameClock;
	
};

