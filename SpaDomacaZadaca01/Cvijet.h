#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::Clock clock;
	sf::RenderWindow* window;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};

