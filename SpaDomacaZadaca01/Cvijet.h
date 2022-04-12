#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
private:
	sf::Time time;
	sf::RenderWindow* window;
	sf::Clock frameClock;
	void drawFlower();
	void drawStem();
	void drawLeaf();
};
