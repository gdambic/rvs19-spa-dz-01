#pragma once
#include <SFML/Graphics.hpp>


class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
private:
	sf::RenderWindow* window;
	sf::ConvexShape middle;
	sf::ConvexShape petal1;
	sf::ConvexShape petal2;
	sf::ConvexShape tige;
	sf::ConvexShape feuille1;
	sf::ConvexShape feuille2;
	sf::ConvexShape fond;
	sf::CircleShape sun1;

	sf::Clock clock;

	bool sunrised;
};

