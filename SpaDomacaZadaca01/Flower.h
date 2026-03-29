#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Flower
{
private:
	RenderWindow* window;
	Clock clock;
	float rotation = 1.f;

public:
	Flower(RenderWindow* window, Clock& clock);
	void drawPetal(RectangleShape& petal, float rotation);
	void draw();
};