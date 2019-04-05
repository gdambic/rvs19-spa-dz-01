#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow *window);
	void draw();

private:
	sf::CircleShape triangle1;
	sf::CircleShape triangle2;
	sf::CircleShape octagon;
	sf::RectangleShape line;

	sf::RenderWindow *window;
	sf::Clock frameClock;
	sf::CircleShape draw_triangle(float r, float p, float rot);
	sf::CircleShape draw_octagon();
	sf::RectangleShape draw_line();
	void init();
};

