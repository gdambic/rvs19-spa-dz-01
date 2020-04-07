#include "Cvijet.h"



void Cvijet::designGlava(sf::CircleShape glava)
{
}

void Cvijet::designStabljika(sf::RectangleShape stabljika)
{
}

void Cvijet::designList(sf::ConvexShape list)
{
}


Cvijet::Cvijet(sf::RenderWindow* windowAdress)
{
	this->windowAdress = windowAdress;
}

void Cvijet::draw()
{
	windowAdress->draw(glava);
	windowAdress->draw(stabljika);
	windowAdress->draw(list);

}
