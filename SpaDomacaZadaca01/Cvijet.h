#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Cvijet
{
private:
	RenderWindow* window;
	Clock clock;
	Time time;

	RectangleShape drawBg(Color color, Vector2f size);
	CircleShape drawPetal(Color color, float size, Vector2f position, Vector2f scale);
	CircleShape drawCloud(Color color, Vector2f position, Vector2f scale);
	CircleShape drawSunRay(Color color, float size, Vector2f position, Vector2f scale, float rotation);

public:
	Cvijet(RenderWindow* window);
	void draw();
};

