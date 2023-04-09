#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Cvijet
{
private:
	RenderWindow* window;
	void draw_flower(float x, float y,float radius);
	void draw_sun();
	void draw_cloud();
public:
	Cvijet(RenderWindow* window);
	void draw(float radius);
	Clock clock;
	
};
