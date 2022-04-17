#include "Cvijet.h"
#include <SFML/Graphics.hpp>


/*
Cvijet::Cvijet(const sf::RenderWindow* window)
{
	draw();
	ispis();
}

void Cvijet::draw(sf::RenderWindow &window) 
{
	window.draw()

	sf::CircleShape krug(50.f);
	krug.setFillColor(sf::Color(100, 150, 50));

	krug.setOutlineThickness(10.f);
	krug.setOutlineColor(sf::Color(150, 100, 50));
	
}
*/

Cvijet::Cvijet(sf::RenderWindow* window)
{
	
	draw_krug(krug);

}

void Cvijet::draw_krug(sf::CircleShape krug)
{
	krug.setPosition(400.f, 300.f);
	krug.setFillColor(sf::Color(500, 200, 50));
	krug.setOutlineThickness(50.f);
	krug.setOutlineColor(sf::Color(100, 300, 250));

	
}

void Cvijet::draw_sunce(sf::CircleShape sunce)
{

	sunce.setFillColor(sf::Color(500, 250, 150));

}

void Cvijet::draw_stabljika(sf::RectangleShape stabljika)
{
	stabljika.setPosition(450.f, 450.f);
	stabljika.setFillColor(sf::Color(300, 150, 50));

}
