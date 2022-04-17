#pragma once
#include<SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::Clock clock;

public:
	void draw();
	Cvijet(sf::RenderWindow* window);
};

