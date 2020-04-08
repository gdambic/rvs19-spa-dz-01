#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Cvijet
{
private:
	RenderWindow* renwin;

	CircleShape octagon;
	CircleShape shape;
	RectangleShape branch;
	ConvexShape leaf;
	CircleShape sun;

	Clock clock;
	float frameClock=0;

public:
	Cvijet(RenderWindow *window);
	void draw();

	void setCvijet();
	void setOctagon();
	void setCircle();
	void setBranch();
	void setLeaf();
	void setSun();

};

