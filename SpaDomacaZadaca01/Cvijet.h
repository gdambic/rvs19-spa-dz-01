#pragma once
#include <SFML/Graphics.hpp>

class Cvijet {
	sf::RenderWindow* xwindow;
	sf::Clock clock;
	int i = 0;
	
public:

	Cvijet(sf::RenderWindow* window);
	void draw();
	void drawZrake();


};
