#pragma once
#include "Cvijet.h"
#include <vector>
class Cvijetovi
{
public:
	Cvijetovi(sf::RenderWindow* window);
	void draw();

private:
	std::vector<Cvijet> cvijetovi;
};

