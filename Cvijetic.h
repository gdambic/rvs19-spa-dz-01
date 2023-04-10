#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::CircleShape flower;
	sf::RectangleShape straw;
	sf::ConvexShape leaf;
	sf::Vector2f rectanglePosition;

	sf::CircleShape dot;
	sf::Clock clock;



public:
	Cvijet(sf::RenderWindow* window);
	void print_flower();
	void animate_dot();
	void draw();
};
