#pragma once
#include <SFML/Graphics.hpp>
class cvijet
{private:
	sf::RenderWindow* window;
	sf::Clock frameClock;
	float ustaWidth;
	bool sirenje;
public:
	cvijet(sf::RenderWindow* window);
	void draw();
};

