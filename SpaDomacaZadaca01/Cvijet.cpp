#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window): window(window){}

void Cvijet::draw()
{
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color(100, 250, 50));
	window.draw(shape);

}
