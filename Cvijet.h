#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;


class Cvijet
{
private:
	RenderWindow* window;

public:
	Cvijet(RenderWindow* w);
	void make_frame();
	void make_stem();
	void make_leaf();
	void make_flower();
	void draw();

};

