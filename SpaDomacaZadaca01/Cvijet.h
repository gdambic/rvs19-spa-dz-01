#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Cvijet
{
private:
	void cvijet();
	void stabljika();
	void trn();
	RenderWindow* window;
public:
	Cvijet(RenderWindow* window);
	void draw();
};

