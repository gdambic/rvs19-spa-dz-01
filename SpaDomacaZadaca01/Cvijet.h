#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	void draw (sf::RenderWindow& window);
private:
	sf::RenderWindow* window;
	sf::CircleShape shape;
	sf::RectangleShape line;
	sf::ConvexShape convex;
	sf::CircleShape sunce;
	sf::Clock clock;

};

