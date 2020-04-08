#pragma once
#include <SFML/Graphics.hpp>
#include "Sunce.h"
#include <vector>
#include "Zvijezda.h"
using namespace sf;

class Okolina
{
private:
	RenderWindow* window;
	std::vector<Sunce> sunce;
	std::vector<Zvijezda> zvijezde;
public:
	Okolina(RenderWindow* window);
	void draw();
};

