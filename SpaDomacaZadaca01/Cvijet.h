#pragma once
#include"SFML/Graphics.hpp"


using namespace std;
using namespace sf;

class Cvijet
{
public:
	Cvijet(RenderWindow* window);
	void draw();
private:
	CircleShape latice[10];
	CircleShape sunce;
	CircleShape tucak;
	ConvexShape list;
	RectangleShape stabljika;
	RenderWindow* window;
	Clock sat;
};

