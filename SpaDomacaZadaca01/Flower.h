#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Flower
{
private:
	RenderWindow* Window;
public:
	Flower(RenderWindow* Window);
	void draw();
};

