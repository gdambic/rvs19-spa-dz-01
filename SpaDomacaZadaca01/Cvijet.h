#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class Cvijet
{
public:
	Cvijet(RenderWindow* adresa);


	void draw();
private:
	void drawNebo();
	void drawSunce(float radius, float position1, float position2, int fillR, int fillG, int fillB, float outline, int outR, int outG, int outB);
	void drawKrug(float radius, float position1, float position2, int fillR, int fillG, int fillB, float outline, int outR, int outG, int outB);
	void drawOblak();
	void dugaHide();

	void drawLivada();
	RenderWindow* adresa;
	Clock clock;
	
};


