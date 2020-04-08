#pragma once
#include <SFML/Graphics.hpp>


class Cvijet
{
private:
	sf::RenderWindow* Win;
	
	int frame;


public:
	Cvijet(sf::RenderWindow* Win);

	void draw();
};

