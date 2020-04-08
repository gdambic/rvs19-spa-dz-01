#pragma once
#include "ElipseShape.h"

class Cvijet
{
private:
	sf::RenderWindow* window;
	EllipseShape s, s1, s2, r;
	EllipseShape l[9];
	sf::CircleShape c;
	sf::Clock clk;
	sf::Time time;
	int rainposx, rainposy;
public:
	Cvijet(sf::RenderWindow* window);
	~Cvijet();
	void draw();
};
