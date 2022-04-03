#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class Cvijet
{
public:
	Cvijet(sf::RenderWindow* adresa);

	void drawNebo();
	void drawSunce(float radius, float position1, float position2, int fillR, int fillG, int fillB, float outline, int outR, int outG, int outB);
	void drawCvijet(float radius, float position1, float position2, int fillR, int fillG, int fillB, float outline, int outR, int outG, int outB);
	void drawOblak();

	void drawLivada();
	void draw();
private:
	RenderWindow* adresa;
	Clock clock;
	
};


