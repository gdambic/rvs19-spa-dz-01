#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Flower 
{
public:
	Flower(RenderWindow* window);
	void draw();
private:
	RenderWindow* window;
	void drawSun();
	void drawSky();
	void drawGrass();
	void drawCloud();
	void drawFlower();
};