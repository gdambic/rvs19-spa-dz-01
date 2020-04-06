#pragma once
#include<vector>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Cvijet
{
public:
	Cvijet(RenderWindow* window);
	void draw()const;

private:
	RenderWindow* window;
	Clock sat;
};
