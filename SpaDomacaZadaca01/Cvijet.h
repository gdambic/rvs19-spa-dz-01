#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Cvijet
{
public:
	Cvijet(RenderWindow* window);
	void draw();
private:
	RenderWindow* window;
	Clock sat;
};
