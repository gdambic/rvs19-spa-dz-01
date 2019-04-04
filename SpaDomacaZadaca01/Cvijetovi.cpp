#include "Cvijetovi.h"



Cvijetovi::Cvijetovi(sf::RenderWindow* window)
{
	cvijetovi.push_back(Cvijet(window));
	this->window = window;
}

void Cvijetovi::draw()
{
	for (Cvijet& c : cvijetovi) {
		c.draw();
	}
}

void Cvijetovi::dodaj()
{
	cvijetovi.push_back(Cvijet(window));
}

void Cvijetovi::makni()
{
	if (cvijetovi.size()>0)
	{ 

		cvijetovi.pop_back();

	}
}
