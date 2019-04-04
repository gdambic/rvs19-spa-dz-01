#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Cvijet
{
private:
	RenderWindow* window;
	CircleShape krug{ 100.f };
	RectangleShape stabljika{ Vector2f(200.f, 15.f) };
	ConvexShape list;
	RectangleShape animacija{ Vector2f(100.f, 15.f) };
public:
	Cvijet(RenderWindow* window);
	void draw();
};

