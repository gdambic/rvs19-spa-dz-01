#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
private:
	sf::RenderWindow* window;
	sf::Clock clock;
	float fi = 0.0;

};

