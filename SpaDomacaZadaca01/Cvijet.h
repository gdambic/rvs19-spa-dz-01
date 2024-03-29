#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow *window;
	sf::RectangleShape grassRectangle;

public:
	Cvijet(sf::RenderWindow *window);
	void draw_flower();
	void draw_sun(float time);
	void draw_grass();
};

