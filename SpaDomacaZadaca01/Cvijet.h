#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private: 
	void drawSunce();
	void drawCvijet();
	void drawPeteljka();
	void drawList();
	sf::RenderWindow* window;
	sf::Clock clock;

public:

	Cvijet(sf::RenderWindow* window);

	void draw();

};

