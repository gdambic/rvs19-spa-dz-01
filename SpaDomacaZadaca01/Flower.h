#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Flower{

private:

	RenderWindow *window_local;
	CircleShape drawSun(int, int, int);
	CircleShape drawPetals(int);
	CircleShape flowerCenter();
	RectangleShape drawStem();
	ConvexShape drawLeafs();

public:
	Flower(RenderWindow *window);
	void draw(int,int);

};

