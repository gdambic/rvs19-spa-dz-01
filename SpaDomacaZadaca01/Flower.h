#pragma once
#include <SFML/Graphics.hpp>
#include "EllipseShape.h"
#include "Bee.h"
#include <cmath>

class Flower
{
public:
	Flower(sf::RenderWindow* window);
	~Flower();
	void draw();

private:
	sf::CircleShape create_petal();
	sf::RenderWindow* window;
	Bee* bee;
};

