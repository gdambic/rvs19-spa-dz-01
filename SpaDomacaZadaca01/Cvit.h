#pragma once
#include <SFML/Graphics.hpp>

class Cvit
{
private:
	sf::RenderWindow* window;

public:
	Cvit(sf::RenderWindow &window);
	void draw();
};

