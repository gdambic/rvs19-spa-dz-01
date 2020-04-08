#pragma once

#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow* windowAdress;

	sf::CircleShape glava;
	sf::RectangleShape stabljika;
    sf::ConvexShape list;
	sf::CircleShape sunce;

	sf::Clock clock;


	int skalar;
	
	
	
	void designGlava();
	void designStabljika();
	void designList();
	void designSunce();

	void sunceAnimacija();

public:
	Cvijet(sf::RenderWindow* windowAdress);
	void draw();

};

