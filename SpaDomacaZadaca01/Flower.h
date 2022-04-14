#pragma once
#include <SFML/Graphics.hpp>
#include "Colors.h"
#include "Weather.h"
using namespace sf;
class Flower
{
public:
	Flower(RenderWindow* window, struct colors* c, Weather* weather);
	void draw();
	void drawStem(Color c);
	void drawLeaf(Color c);
	void drawMainPart(Color c);
	void setScale(float scale);
	float getScale();
	float getWater();
	void drawPetal(Color c);
private:
	RenderWindow* window;
	float water = 2;
	struct colors* c;
	float x = 300.f;
	float stemHeight = 100.f;
	float stemWidth = 20.f;
	float scale = 0;
	float mainPartSize = 30.f;
	float petalSize = 20.f; 
	int nbPetal = 8;
	Clock clock;
	Weather* weather;
	void updateScale();
	void incWater();
	void decWater();

};

