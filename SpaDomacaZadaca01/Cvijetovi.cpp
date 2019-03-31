#include "Cvijetovi.h"



Cvijetovi::Cvijetovi(sf::RenderWindow* window)
{
	cvijetovi.push_back(Cvijet(window));
}

void Cvijetovi::draw()
{
	for (Cvijet c : cvijetovi) {
		c.draw();
	}
}
