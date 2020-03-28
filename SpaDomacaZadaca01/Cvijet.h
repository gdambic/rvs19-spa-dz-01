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
	CircleShape sunce;
	CircleShape tucak;
	CircleShape cvijet_latice[8];
	CircleShape list01;
	CircleShape list02;
	RectangleShape stabljika;
	RenderWindow* window;
};

