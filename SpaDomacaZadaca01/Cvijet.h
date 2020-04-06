#pragma once

#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow* windowAdress;

public:
	Cvijet(sf::RenderWindow* windowAdress);
	void draw();

};

