#pragma once
#include <SFML/Graphics.hpp>


class Cvijet
{
public:

	Cvijet(sf:: RenderWindow* window);
	void draw();

private:
	sf::RenderWindow* window;
	int move = 1;
	int delta = 0;
	bool day = true;
};

