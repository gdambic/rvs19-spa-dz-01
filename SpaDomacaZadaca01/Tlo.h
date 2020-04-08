#pragma once
#include <SFML/Graphics.hpp>
#include "Trava.h"
#include "Cvijet.h"
#include <vector>
using namespace sf;

class Tlo {
private:
	RenderWindow* window;
	int n;
	std::vector<Trava> trave;
	std::vector<Cvijet> cvjetovi;
public:
	Tlo(RenderWindow* window, int n);
	void draw();
};

