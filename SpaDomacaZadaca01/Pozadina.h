#pragma once

#include <SFML/Graphics.hpp>

class Pozadina
{
private:
	sf::RenderWindow* window;
	
	sf::RectangleShape grass;
	sf::CircleShape sun;

public:
	Pozadina(sf::RenderWindow* window);
	void draw();
};

