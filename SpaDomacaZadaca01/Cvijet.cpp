#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window): window(window){}

void Cvijet::draw()
{
	sf::CircleShape oblik(50.f);
	oblik.setFillColor(sf::Color(100, 250, 50));
	window.draw(oblik);

}
//Spriteovi -> https://www.youtube.com/watch?v=1ND_VRJChO4&ab_channel=SonarSystems