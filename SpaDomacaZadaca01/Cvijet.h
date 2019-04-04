#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
	sf::RenderWindow* window;
	sf::ConvexShape convex;
	sf::RectangleShape rectangle;
	sf::CircleShape circle;
	sf::Clock frame_clock;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};