#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Flower
{
private:
	RenderWindow* window;
	Clock flowerClock;
	CircleShape flower;
	RectangleShape stalk;
	ConvexShape leaf;
	Clock sunClock;
	CircleShape sun;

	void set_elements();
	void sun_animation();

public:
	Flower(RenderWindow* window);
	void draw();
};