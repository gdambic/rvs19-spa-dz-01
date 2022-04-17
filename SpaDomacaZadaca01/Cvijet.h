#pragma once;
#include"SFML\Graphics.hpp"

class Cvijet {
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
private:
	sf::Clock frameClock;
	sf::RenderWindow* window;

};

