#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Cvijet
{
private:
	//define core variables
	RenderWindow* window;
	Clock clock;
	Time time;

	//define image elements
	RectangleShape stem;
	CircleShape sun, ray, cloud, petal, pistil, pond;

	//define functions for drawing
	RectangleShape drawBg(Color color, Vector2f size);
	CircleShape drawPetal(Color color, float size, Vector2f position, Vector2f scale);
	CircleShape drawSunRay(Color color, float size, Vector2f position, Vector2f scale, float rotation);

public:
	Cvijet(RenderWindow* window);

	//main draw funcion
	void draw();
};

