#include "Cvijet.h"
#include<SFML/Graphics.hpp>



Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;

}
void::Cvijet::draw()
{
	sunce.setRadius(60);
	sunce.setPointCount(30);
	sunce.setFillColor(sf::Color(255, 69, 0));
	sunce.setOutlineThickness(-14);
	sunce.setOutlineColor(sf::Color(250, 128, 0));
	window->draw(sunce);
}
