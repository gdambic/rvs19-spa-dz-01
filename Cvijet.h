#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
class Cvijet

{
private:
	sf::RenderWindow* adresaProzora;
	void drawCircle(float radius, float position1, float position2, int R, int G, int B, float outline, int outR, int outG, int outB);
	void drawRectangle(float dimension1, float dimension2, float position1, float position2, int R, int G, int B);
	void drawLeaf(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, int R, int G, int B);
public:

	Cvijet(sf::RenderWindow* adresaProzora);
	void draw();




};




