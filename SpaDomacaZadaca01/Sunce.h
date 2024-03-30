#pragma once
#include <SFML/Graphics.hpp>

class Sunce
{
private:
	sf::RenderWindow* window;

public:
	Sunce(sf::RenderWindow* window);
	void draw();
};

