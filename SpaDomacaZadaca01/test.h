#pragma once
#include <SFML/Graphics.hpp>


class Cvijet
{
private :
	//the window 
	sf::RenderWindow* window;

	//the clock for the animation
	sf::Clock clock;

	//the shapes for the flower
	sf::RectangleShape stem;
	sf::CircleShape center;
	sf::CircleShape petal;

public:

	Cvijet(sf::RenderWindow* window);
	void draw();
};