#pragma once

#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow* window;

	sf::RectangleShape stem;
	sf::CircleShape innerFlower;
	sf::CircleShape outerFlower;
	sf::ConvexShape leaf;

	sf::Clock clock;
	float t;

public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};

