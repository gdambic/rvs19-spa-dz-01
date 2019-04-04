#pragma once
#include "Cvijet.h"
#include <vector>
class Cvijetovi
{
public:
	Cvijetovi(sf::RenderWindow* window);
	void draw();
	void dodaj();
	void makni();

private:
	std::vector<Cvijet> cvijetovi;
	sf::RenderWindow* window;
};

