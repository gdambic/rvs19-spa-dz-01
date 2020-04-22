#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Cvijet
{
public:
	Cvijet(RenderWindow* Window);
	void draw();
private:
	RenderWindow *Window;
	Clock clock;
	bool velicina = true;
	float radijus = 5.f;
};


