#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;
class Cvijet
{
private:
	RenderWindow* mwindow;
	Clock clock;
	Time dt;
	CircleShape krugCvijeta;
	RectangleShape stabiljka;
	ConvexShape list;
	CircleShape triangle;
	Font font;
	Text text;
	float granica_gornja = 1000.0f;
	float granica_donja = 400.0f;
	float x = 500.0f;
	float y = 200.0f;
	float brzina = 200.0f;
	float triangleRadius = 70.0f;
public:
	Cvijet();
	Cvijet(RenderWindow* window);
	void drawCvijet();
	void drawTriangle();
	void drawText(string fontDirectory);
	
};

