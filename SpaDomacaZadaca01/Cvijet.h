#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Cvijet
{
public:
	Cvijet(RenderWindow* renderWindow);
	void draw();
	void circle();
private:
	RenderWindow* window;
};

