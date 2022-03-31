#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Flower
{
private:
	RenderWindow* m_rw;

	CircleShape circle;
	RectangleShape tube;

	CircleShape sun;
	int sun_x = 10;
public:
	Flower(RenderWindow* rw);

	void draw();
};

