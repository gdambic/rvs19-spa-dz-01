#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Cvijet
{
private:
	RenderWindow* Window;
	double sunAngle;
	double moonAngle;
	double sunSpeed;
public:
	Cvijet(RenderWindow* Window);
	void draw();
};

