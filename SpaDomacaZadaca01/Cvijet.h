#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow *window;
	sf::Clock timer;

public:
	Cvijet(sf::RenderWindow *window);
	void draw();

};

