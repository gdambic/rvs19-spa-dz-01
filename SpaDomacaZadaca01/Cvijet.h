#pragma once
#include <SFML/Graphics.hpp>
#include<time.h>
using namespace std;
using namespace sf;


class Cvijet
{
public:
	Cvijet(RenderWindow* prozor_za_crtanje);
	void draw();
private:
	CircleShape sunce;
	CircleShape tucak;
	CircleShape latice[12];
	RectangleShape stabiljka;
	ConvexShape list;
	ConvexShape list1;
	RenderWindow* prozor_za_crtanje;
	Clock sat;
	
	
};

