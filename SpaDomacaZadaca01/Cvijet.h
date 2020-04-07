#pragma once

#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow* windowAdress;

	sf::CircleShape glava;
	sf::RectangleShape stabljika;
    sf::ConvexShape list;

	void designGlava(sf::CircleShape glava);
	void designStabljika(sf::RectangleShape stabljika);
	void designList(sf::ConvexShape list);

public:
	Cvijet(sf::RenderWindow* windowAdress);
	void draw();

};

