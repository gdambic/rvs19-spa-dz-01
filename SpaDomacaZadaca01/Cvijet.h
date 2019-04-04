#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Cvijet
{
public:
	Cvijet(RenderWindow *window);
	void draw();
private:
	RenderWindow &mwin;
};



