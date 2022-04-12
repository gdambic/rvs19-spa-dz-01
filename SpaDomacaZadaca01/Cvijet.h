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
	void draw_flower();
	void draw_stem();
	void draw_leaf();
};