#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::CircleShape sunce;
	sf::CircleShape head;
	sf::RectangleShape line;
	sf::ConvexShape leaf;
	sf::Clock clock;
public:
	Cvijet(sf::RenderWindow* window);
	void draw(sf::RenderWindow& window);
};
