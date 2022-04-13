#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Cvijet
{
private:
	RenderWindow* window;
	Clock clock;
	CircleShape shape3;
	double rotation = 1;
public:
	Cvijet(RenderWindow* renderWindow);
	void outlineAndShape();
	void line();
	void convexShape();
	void ShapeForAnimation();
	void animationRotation();
	void draw();
};

