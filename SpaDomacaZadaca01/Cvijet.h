#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Cvijet
{
	CircleShape circle;
	CircleShape circle1;
	CircleShape circle2;
	CircleShape circle3;
	CircleShape circle4;
	CircleShape circle5;
	CircleShape circleSun;

	CircleShape cloud;
	CircleShape cloud2;
	CircleShape cloud3;
	CircleShape cloud4;
	CircleShape cloud5;
	CircleShape cloud6;

	RectangleShape rectangle;

	RenderWindow* window;

public:
	Cvijet(RenderWindow* windows);
	void draw();
};

