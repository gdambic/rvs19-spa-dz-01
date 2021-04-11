#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Cvijet
{
private:
	RenderWindow* window;
	CircleShape sunce;
	CircleShape head;
	CircleShape eye1;
	CircleShape eye2;
	RectangleShape line;
	RectangleShape weed;
	ConvexShape leaf;
	ConvexShape mouth;
	Clock clock;

public:
	Cvijet(RenderWindow* window);
	void draw(RenderWindow& window);
};

