#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	void draw(sf::RenderWindow& window);
private:
	sf::RenderWindow* window;
	sf::CircleShape cvijet;
	sf::RectangleShape stabljika;
	sf::ConvexShape list;
	sf::CircleShape sunce;
	sf::Clock frameClock;
};