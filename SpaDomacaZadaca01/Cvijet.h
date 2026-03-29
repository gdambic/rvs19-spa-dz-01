#pragma once
#include <SFML/Graphics.hpp>
#include "Petal.h"
#include <cmath>

class Cvijet
{

public:

	Cvijet(sf::RenderWindow* window);
	void draw();

private:	

	sf::RenderWindow* window;
	sf::CircleShape head;
	sf::RectangleShape stem;
	sf::ConvexShape leaf;
	sf::CircleShape sun;
	sf::Clock clock;
	Petal petals[10];


};

