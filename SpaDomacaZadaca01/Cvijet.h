#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
	void drawFlower();
private:
	sf::RenderWindow* window;
	sf::Clock frameClock;
};

