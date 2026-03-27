#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow *windows);
	void draw();
private:
	sf::RenderWindow *windows;
	// create an empty shape
	sf::ConvexShape outflower;
	sf::ConvexShape inflower;
	sf::ConvexShape line;
	sf::ConvexShape petal1;
	sf::ConvexShape petal2;
	sf::ConvexShape fond;

	sf::CircleShape astro;   // soleil / lune
	bool isMoon = false;


	sf::Clock time;
	sf::Clock astroClock;
};

