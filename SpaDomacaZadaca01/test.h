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

	//the shapes for the sun
	sf::CircleShape sun;
	sf::CircleShape sunCenter;

public:

	Cvijet(sf::RenderWindow* window);
	void draw();
};

