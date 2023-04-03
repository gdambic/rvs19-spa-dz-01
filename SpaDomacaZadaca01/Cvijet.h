#pragma once
#include <SFML/Graphics.hpp>


class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	void draw();

private:
	void draw_circle();
	void draw_line();
	void draw_convex();
	sf::RenderWindow* window;
	float elapsedTimef = float();
};

