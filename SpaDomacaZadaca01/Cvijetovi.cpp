#include "Cvijetovi.h"



Cvijetovi::Cvijetovi(sf::RenderWindow* window)
{
	cvijetovi.push_back(new Cvijet(window));
	this->window = window;
}

void Cvijetovi::draw()
{
	for (Cvijet* c : cvijetovi) {
		c->draw();
	}
}

void Cvijetovi::dodaj()
{
	cvijetovi.push_back(new Cvijet(window));
}

void Cvijetovi::makni()
{
	if (cvijetovi.size()>0)
	{ 
		delete cvijetovi[cvijetovi.size() - 1];
		cvijetovi.pop_back();

	}
}
