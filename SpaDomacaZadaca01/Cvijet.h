#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Cvijet
{
private:
	RenderWindow* window;

	RectangleShape drawBg(Color color, Vector2f size);

	CircleShape drawPetal(Color color, float size, Vector2f position, Vector2f scale);

public:
	Cvijet(RenderWindow* window);
	void draw();
};

