#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class Cvijet
{
private:
	sf::RenderWindow* prozor;
	sf::Clock sat;
	float njihanje;
public:
	Cvijet(sf::RenderWindow* prozor);

	void draw();
};

